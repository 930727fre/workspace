#include <iostream>
#include <algorithm>
#include <ctype.h>
using namespace std;
int main(){
    int n,m,ans=0;
    cin>>n>>m;
    char arr[n][m];
    char str[1000];
    for(int i=0;i<n;i++){
        fgets(str,1000,stdin);
        for(int j=0;j<m;j++){
            arr[i][j]=str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                if(isdigit(arr[i-1][j])&&i>0){
                    arr[i][j]=arr[i-1][j];
                    continue;
                }
                else if(isdigit(arr[i][j-1]&&j>0)){
                    arr[i][j]=arr[i][j-1];
                    continue;
                }
                else if(isdigit(arr[i][j+1]&&j<m-1)){
                    arr[i][j]=arr[i][j+1];
                    continue;
                }
                else if(isdigit(arr[i+1][j]&&i<n-1)){
                    arr[i][j]=arr[i+1][j];
                    continue;
                }  
                else{
                    ans++;
                    arr[i][j]=ans+47;
                }
            }           
        }
        break;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
        break;
    }
    cout<<ans;
}
