#include <stdio.h>
#include <string.h>

int main ()
{
   FILE *fp;
   int c;
   int n = 0,index=0;
   long long int counter[]={0,0,0,0,0,0};
   char str[20];

   fp = fopen("/Users/930727fre/Downloads/wmh_hw02/fruit.txt","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   while(!feof(fp))
   {
        c = fgetc(fp);
        printf("%c",c);
        if(c==' '){
            str[index]='\0';
            index=0;
            if(!strcmp(str,"apple")){
                //printf("%s\n",str);
                counter[0]++;
            }
            else if(!strcmp(str,"banana")){
                //printf("%s\n",str);
                counter[1]++;
            }
            else if(!strcmp(str,"kiwi")){
                //printf("%s\n",str);

                counter[2]++;
            }
            else if(!strcmp(str,"orange")){
                //printf("%s\n",str);

                counter[3]++;               
            }
            else if(!strcmp(str,"papaya")){
                //printf("%s\n",str);

                counter[4]++;              
            }
            else if(!strcmp(str,"pineapple")){
                //printf("%s\n%lld\n",str,counter[5]);
                counter[5]++;
            }
            for(int i=0;i<6;i++){
                //printf("%lld ",counter[i]);
            }                                        
        }
        else{
            str[index]=c;
            index++;
        }
   }
            str[index]='\0';
            index=0;
            if(!strcmp(str,"apple")){
                //printf("%s\n",str);
                counter[0]++;
            }
            else if(!strcmp(str,"banana")){
                //printf("%s\n",str);
                counter[1]++;
            }
            else if(!strcmp(str,"kiwi")){
                //printf("%s\n",str);

                counter[2]++;
            }
            else if(!strcmp(str,"orange")){
                //printf("%s\n",str);

                counter[3]++;               
            }
            else if(!strcmp(str,"papaya")){
                //printf("%s\n",str);

                counter[4]++;              
            }
            else if(!strcmp(str,"pineapple")){
                //printf("%s\n%lld\n",str,counter[5]);
                counter[5]++;
            }
            for(int i=0;i<6;i++){
                //printf("%lld ",counter[i]);
            }   
   for(int i=0;i<6;i++){
    printf("%lld ",counter[i]);
   }
  
   fclose(fp);
   
   return(0);
}