#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char s[1000],*pos,ans[100][100];
    int t,temp;
    string c;
    cin>>t;
    for(int i=0;i<t;i++){
        int k=0;
        cin>>s;
        cin>>temp;
        pos=&s[temp];
        cin>>c;
        for(int j=0;j<sizeof(c);j++){
            switch(c[j]){
                case '>':
                    pos++;
                    break;
                case '<':
                    pos--;
                    break;
                case '+':
                    (*pos)++;
                    break;
                case '-':
                    (*pos)--;
                    break;
                case '.':
                    //printf("%c",*pos);
                    //ans[i][k]=*pos;
                    cout<<*pos;
                    k++;
                    break;
            }
        }
        cout<<endl;
    }
    //for(int i=0;i<t;i++){
    //    cout<<ans[i]<<endl;
    //}
}
