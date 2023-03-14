#include <stdio.h>
typedef long long int LL;
LL ans=0;
int matrix[11][11], arr[11], size;
LL det(int);
int main(){
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<size;i++){ //initialize
        arr[i]=1;
    }
    printf("%lld\n",det(size));
}

LL det(int n){
    LL temp=0;
    int counter=0, a, b, c, d;
    if(n==2){
        for(int i=size-n;i<size;i++){
            for(int j=0;j<size;j++){
                if(arr[j]){
                    switch (counter)
                    {
                        case 0:
                            a=matrix[i][j];
                            break;
                        case 1:
                            b=matrix[i][j];
                            break;
                        case 2:
                            c=matrix[i][j];
                            break;
                        case 3:
                            d=matrix[i][j];
                            break;
                    }
                    counter++;
                }

            }
        }
        return a*d-b*c;
    }
    else{
        int sign=1;
        for(int i=0;i<size;i++){
            if(arr[i]){
                arr[i]=0;
                temp+=det(n-1)*sign*matrix[size-n][i];
                sign*=-1;
                arr[i]=1;
            }

        }
        return temp;
    }
}