#include <iostream>
#include <cstring>
using namespace std;
int valid(void);
void dfs(int,int);
char n[18],str[18];
int ans=32;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>str;
        dfs(strlen(str),0);
        cout<<ans;
    }
}

void dfs(int length,int step){
    if(valid()){
        if(ans>step){
            ans=step;
        }
        return;
    }
    else if(length==1){
        return;
    }
    for(int i=0;i<length;i++){
        strcpy(n,str);
        n[i]=0;
        dfs(length-1,step+1);
    }
}
int valid(void){
    int temp=0,flag=0;
    cout<<strlen(str)<<endl;
    for(int i=strlen(n)-1;i>=0;i--){
        cout<<n[i];
        if(flag==2){
            break;
        }
        else{
            if(n[i]>=48&&n[i]<=57){
                if(flag==1){
                    temp+=10*(n[i]-48);
                }
                else{
                    temp+=n[i]-48;
                }
                // cout<<temp<<endl;
                flag++;
            }
        }
    }
    cout<<endl<<"valid() temp = "<<temp<<endl;
    if(temp%25==0){
        return 1;
    }
    else{
        return 0;
    }
}

/*


*/