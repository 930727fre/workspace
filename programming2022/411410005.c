#include <stdio.h>

int main(){
    int numberOfLayer, sideOfTheTopLayer, growthOfEachLayer, trunkWidth, trunkHeight; //declare all designated variables
    char margin='#', interior='@', trunkSign='|', temp=' '; //declare signs of trunk
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
    

    int width=1+2*growthOfEachLayer*numberOfLayer; //calculate the width of whole graph
    int lowestLayer,numOfSign;
    for(int a=0;a<(width/2);a++){ //print the top of whole tree
        printf(" ");
    }
    printf("%c\n",margin);

    for(int a=0;a<numberOfLayer;a++){ //the for loop for running the layers
        lowestLayer=(a+1)*growthOfEachLayer; //calculate the index of lowest layer
        for(int b=1;b<sideOfTheTopLayer+growthOfEachLayer*a-1;b++){ //print each layer
            for(int c=0;c<(width/2-b);c++){ //print the spaces
                printf(" ");
            }
            if(b+1!=lowestLayer){ //if it's not the lowest index of that layer, print "@" and "#"
                for(int c=0;c<1+b*2;c++){
                    if(c==0||c==b*2){
                        printf("%c",margin);
                    }
                    else{
                        printf("%c",interior);
                    }
                    
                }
            }else{ //if it's the lowest index of that layer, print "#"s.
                for(int c=0;c<1+b*2;c++){
                    printf("%c",margin);
                }
            }
            


            printf("\n"); //next line
        }

    }
    for(int a=0;a<trunkHeight;a++){ // the for loop for each layer of trunk
        for(int b=0;b<(width-trunkWidth)/2;b++){ //print the spaces before the "|"s
            printf(" ");
        }
        for(int b=0;b<trunkWidth;b++){ //print all the "|" of each layer
            printf("%c",trunkSign);
        }
        printf("\n");
    }
}