#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*input
n = 3
A =
1 2 3
2 2 2
3 2 1
B =
2 0 1
0 1 0
1 0 2
A+B*A+B
*/
void add(long long int[100][100]);
void multi(long long int[100][100]);
long long int a[100][100],b[100][100],ans[100][100],n,temp[100][100];
int main(){
    char str[100]="n = 345\n";
    for(int i=0;i<100;i++){//initialize ans array
        for(int j=0;j<100;j++){
            ans[i][j]=0;
        }
    }
    scanf("%c %c %lld",str,str,&n);//n = 3
    //printf("!n = %d\n",n);
    scanf("%s %s",str,str);//A = 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    scanf("%s %s",str,str);//B = 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&b[i][j]);
        }
    }
    scanf("%s",str);//A+B*A+B
    if(str[0]=='A'){
        add(a);
    }
    else{
        add(b);
    }
    for(int i=1;i<strlen(str);i+=2){
        if(str[i]=='+'){
            if(str[i+1]=='A'){
                add(a);
            }
            else{
                add(b);
            }
        }
        else{
            if(str[i+1]=='A'){
                multi(a);
            }
            else{
                multi(b);
            }
        }
    }
    for(int i=0;i<20;i++){
        //printf("-");
    }
    //printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%lld",ans[i][j]);
            if(j!=n-1) printf(" ");

        }
        printf("\n");
    }      
}

void add(long long int m[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]+=m[i][j];
        }
    }
}
void multi(long long int m[100][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<n;l++){
                temp[i][j]+=ans[i][l]*m[j][l];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=temp[i][j];
        }
    }
}
