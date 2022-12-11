#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
/*input
5
order 7
order 6
delivery
order 8
delivery
*/

int main(){
    queue<int> que;
    int n;
    char str[100],*token;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",str);
        str[strlen(str)]='\0';

        if(str[0]=='o'){
            scanf("%s",str);
            //printf("push in: %d\n",atoi(str));
            que.push(atoi(str));
        }
        else if(!strcmp(str,"delivery")){
            if(que.size()==0){
                printf("-1\n");
            }
            else{
                printf("%d\n",que.front());
                que.pop();
            }
        }
        else{
            printf("\"%s\" wrong command\n",str);
        }
        
    }
}