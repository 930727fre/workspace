#include <stdio.h>

int main(){
    int numberOfLayer, sideOfTheTopLayer, growthOfEachLayer, trunkWidth, trunkHeight;
    char margin='#', interior='@', trunkSign='|', temp=' ';
    printf("Please input the number of layer(the value has to be smaller than 5 and greater than 2.");
    scanf(" %d",&numberOfLayer);
    while(numberOfLayer>5||numberOfLayer<2){
        printf("The value has to be smaller than 5 and greater than 2. Please input again.");
        scanf(" %d",&numberOfLayer);
    }
    printf("Please input the side of the top layer(the value has to be smaller than 6 and greater than 3.");
    scanf(" %d",&sideOfTheTopLayer);
    while(sideOfTheTopLayer>6||sideOfTheTopLayer<3){
        printf("The value has to be smaller than 6 and greater than 3. Please input again.");
        scanf(" %d",&sideOfTheTopLayer);
    }
    printf("Please input the growth of each layer(the value has to be smaller than 5 and greater than 1.");
    scanf(" %d",&growthOfEachLayer);
    while(growthOfEachLayer>5||growthOfEachLayer<1){
        printf("The value has to be smaller than 5 and greater than 1. Please input again.");
        scanf(" %d",&growthOfEachLayer);
    }
    printf("Please input the width of trunk(the value has to be a odd number which is smaller than 9 and greater than 3.");
    scanf(" %d",&trunkWidth);
    while(trunkWidth>9||trunkWidth<3||trunkWidth%2==0){
        printf("The value has to be a odd number which is smaller than 9 and greater than 3. Please input again.");
        scanf(" %d",&trunkWidth);
    }
    printf("Please input the height of trunk(the value has to be smaller than 10 and greater than 4.");
    scanf(" %d",&trunkHeight);
    while(trunkHeight<4||trunkHeight>10){
        printf("The value has to be smaller than 10 and greater than 4. Please input again.");
        scanf(" %d",&trunkHeight);
    }
    
    printf("Please input the sign of leaf margin. Default:'#'");
    scanf(" %c",&temp);
    if(temp!=' '){
        margin=temp;
        temp=' ';
    }
    printf("Please input the sign of leaf. Default:'@'");
    scanf(" %c",&temp);
    if(temp!=' '){
        interior=temp;
        temp=' ';
    }
    printf("Please input the sign of trunk. Default:'|'");
    scanf(" %c",&temp);
    if(temp!=' '){
        trunkSign=temp;
        temp=' ';
    }
    

    int width=1+2*growthOfEachLayer*numberOfLayer;
    int lowestLayer,numOfSign;
    for(int a=0;a<(width/2);a++){
        printf(" ");
    }
    printf("%c\n",margin);

    for(int a=0;a<numberOfLayer;a++){
        lowestLayer=(a+1)*growthOfEachLayer;
        for(int b=1;b<sideOfTheTopLayer+growthOfEachLayer*a-1;b++){
            for(int c=0;c<(width/2-b);c++){
                printf(" ");
            }
            if(b+1!=lowestLayer){
                for(int c=0;c<1+b*2;c++){
                    if(c==0||c==b*2){
                        printf("%c",margin);
                    }
                    else{
                        printf("%c",interior);
                    }
                    
                }
            }else{
                for(int c=0;c<1+b*2;c++){
                    printf("%c",margin);
                }
            }
            


            printf("\n");
        }

    }
    for(int a=0;a<trunkHeight;a++){
        for(int b=0;b<(width-trunkWidth)/2;b++){
            printf(" ");
        }
        for(int b=0;b<trunkWidth;b++){
            printf("%c",trunkSign);
        }
        printf("\n");
    }
}