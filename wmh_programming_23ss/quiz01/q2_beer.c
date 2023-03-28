#include <stdio.h>

float p,ans=0;
int n;
void fc(float, int);
int main(){
    scanf("%f %d",&p,&n);
    fc(1,0);
    printf("%.2f",ans);
}

void fc(float prob, int i){
    if(i==n-1){
        ans+=prob;
    }
    else{
        ans+=prob*p;
        ans+=prob*(1-p)*2;
        // printf("%f %d %f\n",prob, i, ans);
        fc(prob*(1-p), i+1);
    }

}