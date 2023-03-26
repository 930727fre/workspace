#include <stack>
#include <iostream>
#include <string.h>
using namespace std;
/*input
5
next 3
next 6
show
prev
show
*/

int main(){
    int q;
    char str[100];
    cin>>q;
    stack<int> sk;
    for(int i=0;i<q;i++){
        scanf("%s",str);
        if(!strcmp(str,"prev")){
            if(!sk.size()){
                //printf("-1\n");
            }
            else{
                sk.pop();
            }
        }
        else if(!strcmp(str,"next")){
            scanf("%s",str);
            sk.push(atoi(str));
        }
        else if(!strcmp(str,"show")){
            if(!sk.size()){
                printf("-1\n");
            }
            else{
                printf("%d\n",sk.top());
            }
        }        
    }
}