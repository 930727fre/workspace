#include <stdio.h>
#include <string.h>

int main(){
    char str[100050], arr[100050];
    int arrIdx=-1, len;
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        if(arrIdx<0){
            arrIdx++;
            arr[0]=str[i];
        }
        else if(str[i]!=arr[arrIdx]){
            arrIdx++;
            arr[arrIdx]=str[i];
        }
        else{
            arrIdx--;
        }
    }
    printf("%d\n",arrIdx+1);
}