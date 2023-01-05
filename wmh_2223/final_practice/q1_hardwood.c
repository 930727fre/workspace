#include <stdio.h>
#include <string.h>

int cmp(int);
char species[2000][30],str[1000];
int main(){
    int n,flag=0,qty[2000],index,foundFlag,temp;
    float sum;
    fgets(str,1000,stdin);
    n=atoi(str);
    for(int i=0;i<n;i++){
        index=-1;
        sum=0.0;
        while(fgets(str,1000,stdin)!=NULL){
            fflush(stdin);
            if(strlen(str)==1){
                if(!flag){
                    flag=!flag;
                    continue;
                }
                else{

                    break;
                }                
            }
            else{
                sum++;
                str[strlen(str)-1]='\0';
                foundFlag=0;
                for(int j=0;j<=index;j++){
                    if(!strcmp(species[j],str)){
                        qty[j]++;
                        foundFlag=1;
                        break;
                    }
                }
                if(!foundFlag){
                    index++;
                    strcpy(species[index],str);
                    qty[index]=1;
                }


            }


        }
        for(int j=0;j<=index;j++){
            for(int k=0;k<=index-j-1;k++){
                if(cmp(k)){
                    //printf("%d %s <-> %s\n",k,species[k],species[k+1]);
                    temp=qty[k];
                    qty[k]=qty[k+1];
                    qty[k+1]=temp;
                    strcpy(str,species[k]);
                    strcpy(species[k],species[k+1]);
                    strcpy(species[k+1],str);
                }
            }
        }
        //printf("sum = %f\n",sum);
        for(int i=0;i<=index;i++){
            printf("%s %.4f\n",species[i],qty[i]/sum*100);
        }
        if(i!=n-1){
            printf("\n");
        }

    }
}

int cmp(int k){
    for(int i=0;i<strlen(species[k])&&i<strlen(species[k+1]);i++){
        if(species[k][i]==species[k+1][i]){
            continue;
        }
        else if(species[k][i]>species[k+1][i]){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}