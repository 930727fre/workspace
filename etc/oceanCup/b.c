#include<stdio.h>
char template[238]="...................................###.###.###.###.###..###.#.#.###..#.#.#...#...#.#.#.#..#...#.#.#.#..#.#.#...###.###.#.#..#...#.#.###..#.#.#...#...#.#.#.#..#...#.#.#....###.###.###.#.#.#.#..###.###.#.....................................";
char arr[238];


int main(){
    int ans=0,flag, idx, temp;
    for(int i=0;i<7;i++){
        scanf("%s",&arr[34*i]);
    }
   
    for(int i=0;i<34;i++){
        for(int j=0;j<34;j++){
            flag=0;
            for(int k=0;k<7;k++){
                if(template[j+34*k]==arr[i+34*k]){
                    flag=1;
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                template[j]=0;
                arr[i]=j;
                break;
            }
            else{
                continue;
            }
        }
    }

    for(int i=0;i<34;i++){
        for(idx=i;idx<34;idx++){
            if(arr[idx]==i){
                break;
            }
        }
        for(;idx>i;idx--){
            temp=arr[idx-1];
            arr[idx-1]=arr[idx];
            arr[idx]=temp;
            ans++;
        }
        // for(int i=0;i<34;i++){
        //     printf("%d ",arr[i]);
        // }
        // printf("\n");
    }
    printf("%d\n",ans);
}