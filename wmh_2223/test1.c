#include <stdio.h>
#include <string.h>

int main ()
{
   FILE *fp;
   int c;
   int n = 0,index=0,counter[10];
   char str[20];

    for(int i=0;i<10;i++){
        counter[i]=0;
    }
   fp = fopen("/Users/930727fre/Downloads/wmh_hw02/fruit.txt","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   while(!feof(fp))
   {
        c = fgetc(fp);
        if(c==' '){
            str[index]='\0';
            index=0;
            if(strstr(str,"apple")){
                printf("%s\n",str);

                counter[0]++;
            }
            else if(strstr(str,"banana")){
                printf("%s\n",str);

                counter[1]++;
            }
            else if(strstr(str,"kiwi")){
                printf("%s\n",str);

                counter[2]++;
            }
            else if(strstr(str,"orange")){
                printf("%s\n",str);

                counter[3]++;               
            }
            else if(!strcmp(str,"papaya")){
                printf("%s\n",str);

                counter[4]++;              
            }
            else if(!strcmp(str,"pineapple")){
                printf("%s\n%d\n",str,counter[5]);
                counter[5]++;
            }
            for(int i=0;i<6;i++){
                printf("%d ",counter[i]);
            }                                        
        }
        else{
            str[index++]=c;
        }
   }
   for(int i=0;i<6;i++){
    printf("%d ",counter[i]);
   }
  
   fclose(fp);
   
   return(0);
}