#include <queue>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    queue <int> que;
    que.push(2);
    que.push(4);
    cout<<que.size()<<endl;
    for(int i=0;i<que.size()+1;i++){
        printf("%d\n",que.front());
        que.pop();
    }
}