#include <stdio.h>

int main(){
    unsigned code;
    while(scanf("%d",&code)!=EOF){
        int counter=0;
        for(unsigned i=16;i<32;i++){
            if(((code<<i)>>31)==1){
                counter++;
            }
        }
        if(counter%2!=0){
            printf("ERROR\n");
        }
        else{
            printf("%d-",code<<16>>29);
            printf("%d-",code<<19>>28);
            if(code<<23>>31){
                printf("M-");
            }
            else{
                printf("F-");
            }
            printf("%d\n",code<<24>>25);
        }

    }

    
}
