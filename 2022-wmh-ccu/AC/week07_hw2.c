#include <stdio.h>

int main(){
    int n,m,counter,temp;
    scanf("%d%d",&n,&m);
    int arr[n][m],ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            counter=0;
            if(i-1<0){
                temp=0;
            }
            else{
                temp=i-1;
            }
            for(int k=temp;(k<i+2)&&(k>-1)&&(k<n);k++){
                if(j-1<0){
                    temp=0;
                }
                else{
                    temp=j-1;
                }
                for(int l=temp;(l<j+2)&&(l>-1)&&(l<m);l++){
                    temp++;
                    if(k==i&&l==j){
                        continue;
                    }
                    if(arr[k][l]==1){
                        counter++;
                    }
                }
            }
            ans[i][j]=counter;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("|| :");
            if(arr[i][j]==1){
                printf("boom");
            }
            else{
                switch(ans[i][j]){
                    case 0:
                        printf("zero");
                        break;
                    case 1:
                        printf("one");
                        break;                        
                    case 2:
                        printf("two");
                        break;                        
                    case 3:
                        printf("three");
                        break;                        
                    case 4:
                        printf("four");
                        break;
                    case 5:
                        printf("five");
                        break;                        
                    case 6:
                        printf("six");
                        break;                        
                    case 7:
                        printf("seven");
                        break;
                    case 8:
                        printf("eight");
                        break;                        
                }
            }
            printf(": ||");
            if(j!=m-1){
                printf(" ");
            }
        }
        //if(i!=n-1){
            printf("\n");
        //}
    }    
    
}