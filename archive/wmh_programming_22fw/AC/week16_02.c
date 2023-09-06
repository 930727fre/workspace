#include <stdio.h>
#include <string.h>
/*input
3 7
rice rice
spaghetti spaghetti
octopus octopi
rice
lobster
spaghetti
strawberry
octopus
peach
turkey
*/
int es(char* );

int main(){
    int l,n,found;
    char list[30][2][30],str[100];
    scanf("%d %d",&l,&n);
    for(int i=0;i<l;i++){
        scanf("%s %s",list[i][0],list[i][1]);
    }

    for(int i=0;i<n;i++){
        found=0;
        scanf("%s",str);
        for(int j=0;j<l;j++){
            if(!strcmp(list[j][0],str)){
                printf("%s\n",list[j][1]);
                found=!found;
                break;                
            }

        }
        if(found){
            continue;
        }
        else if(str[strlen(str)-1]=='y'&&!strspn(&str[strlen(str)-2],"aeiou")){
            for(int j=0;j<strlen(str)-1;j++){
                printf("%c",str[j]);
            }
            printf("ies\n");
        }
        else if(es(str)){
            printf("%ses\n",str);
        }
        else{
            printf("%ss\n",str);
        }

    }
}
int es(char* str){
    if(str[strlen(str)-1]=='o'||str[strlen(str)-1]=='s'||str[strlen(str)-1]=='x'){
        return 1;
    }
    else if((str[strlen(str)-2]=='c'&&str[strlen(str)-1]=='h')||(str[strlen(str)-2]=='c'&&str[strlen(str)-1]=='h')){
        return 1;
    }
    else{
        return 0;
    }

}
