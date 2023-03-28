#include <stdio.h>

int n,e,w[100000],v[1000000],ans=0,temp;
void fc(int, int, int);
int main(){
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d %d",&w[i],&v[i]);
    }      
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;                
            }
        }
    }
    fc(e, 0,n-1);
    printf("%d",ans);
}

void fc(int remainder, int value, int index){
    printf("%d %d %d\n",remainder, value, index);
    if(value>ans){
        ans=value;
    }
    if(remainder==0||index<0){
        return;
    }
    for(int i=index;i>=0;i--){
        fc(remainder, value, index-1);
        if(remainder>=w[i]){
            fc(remainder-w[i], value+v[i],index-1);
        }
    }
}