#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char outputPictureInfo[6000000];

//儲存bmp圖檔的資訊
typedef struct bmpInfo {
    unsigned size; //文件的大小 (byte)
    char reserved[4] ; //保留空間
    unsigned offsetBits; //像素陣列 (pixel array) 的起始位置 (通常為 54)
    unsigned infoSize; //圖片資訊 (image information) 的大小 (byte) (為 40)
    unsigned width; //點陣圖寬度 (pixel)
    unsigned height; //點陣圖高度 (pixel)
    short unsigned planes; //色彩平面數 (1)
    short unsigned bitPerPixel; //每個像素所占大小(bit) (通常為24)
    unsigned compression; //使用的壓縮方法 (0為不壓縮)
    unsigned imageSize; // 像素陣列大小(byte)，有時為0 (省略)
    unsigned XResolution; //橫向解析度
    unsigned YResolution; //縱向解析度
    unsigned colors; //調色盤的顏色數 (通常為0)
    unsigned importantColors; //重要顏色數 (0為預設)
} BmpInfo;

//取得檔案名稱
void getFileName( FILE *ptr, char arr[], char target[] ){
    int pathName = 0;
    int j=0;
    for ( int i=0; i< strlen(arr); i++){
        if ( arr[i] == '='){
            pathName = 1;
            continue;
        }
        if (pathName){
            target[j] = arr[i];
            j++;
        }
    }
}

//取得圖片檔案的路徑
void getPicturePath ( char targetPath[], char original[], char name[]){
    int index = 0;
    strcpy ( targetPath, original);
    index = strrchr( targetPath, '/') - targetPath;
    for ( int i=index; i < strlen(targetPath); i++ ){
        ++index;
        targetPath[index] = '\0';
    }
    strcat ( targetPath, name);
}

int main() {
    char filePath[100000], fileName[100000], temp[100000], output[100000], obj[100000], msk[100000], bg[100000];
    char outputPath[100000], objPath[100000], mskPath[100000], bgPath[100000];
    int pathName=0;
    unsigned bg_temp, obj_temp, msk_temp, output_temp;
    FILE *fptr, *output_ptr, *obj_ptr, *msk_ptr, *bg_ptr;
    printf ( "Please enter the name of your file.\n" );
    gets ( filePath );
    // printf ( "Please enter the name of your file.\n" );
     //gets ( fileName );

    //確認是否為有效的檔案的路徑與名稱
    fptr = fopen ( filePath, "r");
    if ( fptr == NULL ){
        printf ( "Invalid entering path or filename.\n" );
        return 0;
    }

    //取出output, obj, msk, bg的檔案名稱
    while ( fscanf ( fptr, "%s", temp ) != EOF ){
        if ( strncmp ( temp, "OUTPUT",5) == 0 ){
            getFileName ( fptr, temp, output);
        }
        if ( strncmp ( temp, "OBJ",3) == 0 ){
            getFileName ( fptr, temp, obj);
        }
        if ( strncmp ( temp, "MSK",3) == 0 ){
            getFileName ( fptr, temp, msk);
        }
        if ( strncmp ( temp, "BG",2) == 0 ){
            getFileName ( fptr, temp, bg);
        }
    }

    //取出output, obj, msk, bg的路徑
    getPicturePath ( outputPath, filePath, output);
    getPicturePath ( objPath, filePath, obj);
    getPicturePath ( mskPath, filePath, msk);
    getPicturePath ( bgPath, filePath, bg);
    
    //確認output, obj, msk, bg是否能成功開啟
    output_ptr = fopen ( output, "wb");
    obj_ptr = fopen ( obj, "rb");
    msk_ptr = fopen ( msk, "rb");
    bg_ptr = fopen ( bg, "rb");

    if ( obj_ptr == NULL ){
        printf ( "Invalid path.\n" );
        return 0;
    }
    else if ( msk_ptr == NULL ){
        printf ( "Invalid path.\n" );
        return 0;
    }
    else if ( bg_ptr == NULL ){
        printf ( "Invalid path.\n" );
        return 0;
    }
    
    //將圖片資料存入sructure裡面
    BmpInfo output_pic, background_pic, object_pic, mask_pic;
    fseek ( bg_ptr, 0x02, SEEK_SET);
    fread ( &background_pic, sizeof(BmpInfo), 1, bg_ptr);
    fseek ( obj_ptr, 0x02, SEEK_SET);
    fread ( &object_pic, sizeof(BmpInfo), 1, obj_ptr);
    fseek ( msk_ptr, 0x02, SEEK_SET);
    fread ( &mask_pic, sizeof(BmpInfo), 1, msk_ptr);
    
    //分別印出背景圖片、物件圖片、物件遮罩圖片的檔名、寬度 (Width)、高度 (Height)、橫向解析度 (XResolution)、縱向解析度 (YResolution)。
    printf ("background:%s\n",bg);
    printf (">> Width:%d  Height:%d  XResolution:%d  YResolution:%d\n", background_pic.width, background_pic.height, background_pic.XResolution, background_pic.YResolution);
    printf ("object:%s\n",obj);
    printf (">> Width:%d  Height:%d  XResolution:%d  YResolution:%d\n", object_pic.width, object_pic.height, object_pic.XResolution, object_pic.YResolution);
    printf ("mask:%s\n",msk);
    printf (">> Width:%d  Height:%d  XResolution:%d  YResolution:%d\n", mask_pic.width, mask_pic.height, mask_pic.XResolution, mask_pic.YResolution);
    
    //若obj與mask圖片大小不同，則提示遮罩圖片大小有誤並結束程式
    if ( (object_pic.width/object_pic.XResolution)*(object_pic.height/object_pic.YResolution) != (mask_pic.width/mask_pic.XResolution)*(mask_pic.height/mask_pic.YResolution) ){
        printf ( "Warning: sizes of object and mask arn't the same.\n");
    }
    //若obj與bj圖片大小不同，則提示背景圖片大小有誤並結束程式
    else if ( (object_pic.width/object_pic.XResolution)*(object_pic.height/object_pic.YResolution) != (background_pic.width/background_pic.XResolution)*(background_pic.height/background_pic.YResolution) ){
        printf ("Warning: sizes of object and background arn't the same.\n");
    }

    //合成圖片
    int total = background_pic.height * (background_pic.width * 3 + (4 - background_pic.width * 3 % 4) % 4); // (width *3 +padding)
    fseek ( bg_ptr, 0x36, SEEK_SET);
    fseek ( obj_ptr, 0x36, SEEK_SET);
    fseek ( msk_ptr, 0x36, SEEK_SET);
    for ( int i=0; i<total; i++){       
        fread ( &bg_temp, sizeof(char), 1, bg_ptr ); 
        fread ( &obj_temp, sizeof(char), 1, obj_ptr );
        fread ( &msk_temp, sizeof(char), 1, msk_ptr );
        output_temp = bg_temp * ( msk_temp / 255.0) + obj_temp * ( 255 - msk_temp ) / 255.0;
        // printf ("%02x ", bg_temp);
        // printf ("%02x ", obj_temp);
        // printf ("%02x ", msk_temp);
        outputPictureInfo[i] = output_temp; 
    }
    
    // for ( int i=0; i=total; i++){
    //     printf ( "%02x ", outputPictureInfo[i]);
    // }
    fwrite ("BM", 2, 1, output_ptr);
    fwrite ( &background_pic, sizeof(BmpInfo), 1, output_ptr);
    fwrite ( outputPictureInfo, 1, total, output_ptr);
    fclose(output_ptr);
}
