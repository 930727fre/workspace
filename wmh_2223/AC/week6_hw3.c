#include <stdio.h>

int main(){
    int n,avg=0,temp,ans[10000],counter=0;
    while(1){
        scanf("%d",&n);
        avg=0;
        if(n==0){
            break;
        }
        counter++;
        ans[counter-1]=0;
        int h[n];
        for(int i=0;i<n;i++){
            scanf("%d",&h[i]);
            avg+=h[i];
        }
        avg=avg/n;
        for(int i=0;i<n;i++){
            temp=h[i]-avg;
            if(temp<0){
                temp=temp*(-1);
            }
            ans[counter-1]+=temp;
        }
        ans[counter-1]=ans[counter-1]/2;
    }
    for(int i=1;i<=counter;i++){
        printf("Set #%d\n",i);
        printf("The minimum number of moves is %d.\n",ans[i-1]);
        if(i!=counter){
            printf("\n");
        }
    }
    
}