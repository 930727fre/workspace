#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int lcs(int, int, int);
int ans=0,lcsHead,lcsTail;
char *s1,*s2;
int main(){
    //cin>>s1>>s2;
    s1=(char*)malloc(1000);
    s2=(char*)malloc(1000);
    strcpy(s1,"GeeksQuiz");
    strcpy(s2,"GeeksforGeeks");
    lcs(0,0,0)
    cout<<"ans = "<<ans;
}

int lcs(int h1, int h2, int length){ // headin index for s1 and s2
    if(s1[h1]==s2[h2]){
        lcs(h1+1,h2+1,length+1);
    }
    else{
        if(length!=0&&ans)
    }
}