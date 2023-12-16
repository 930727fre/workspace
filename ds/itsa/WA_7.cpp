#include <stdio.h>

int main(){
    int n;
    char a;
    float b,c,d,e;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf(" %c %f %f %f %f",&a, &b, &c, &d, &e);
        switch(a){
            case '+':
                printf("%.0f %.0f\n",b+c,d+e);
                break;
            case '-':
                printf("%.0f %.0f\n",b-c,d-e);
                break;
            case '*':
                printf("%.0f %.0f\n",b*d-c*e,b*e+c*d);
                break;        
            case '/':
                printf("%.0f %.0f\n", (b*d+c*e)/(d*d+e*e), (c*d-b*e)/(d*d+e*e));
                break;
        }
    }
}