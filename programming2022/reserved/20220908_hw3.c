//#include <stdio.h>
//#include <stdbool.h>
#include <bits/stdc++.h>

int HeightOfTri=3;
bool shrink = 0;

int fn(int counter){
    for(int j=0;j<3;j++){
        printf(" ");
        for(int i=0;i<(2*HeightOfTri-2)/2;i++){
            printf(" ");
        }

        for(int i=0;i<counter; i++){
            printf("*");
        }
        if(j!=2){
            for(int i=0;i<(2*HeightOfTri-2)/2;i++){
                printf(" ");
            }

        }


    }


    printf("\n");
    printf("\n");

    if(shrink){
        fn(counter--);
    }
    else if(counter==2*HeightOfTri-1){
        shrink = true;
        fn(counter--);
    }
    else{
        fn(counter++);
    }

    return 0;
    
}

int main(){
    int a=1;
    a=a-1;
    printf("%c", a);
    //fn(1);

    return 0;
}