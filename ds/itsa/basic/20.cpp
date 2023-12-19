#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b, ans, tempStr;
    int n, length, temp, carry;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        length=a.length()-b.length();
        if(length<0){
            a.swap(b);
            length*=-1;
        }
        for(int i=0;i<length;i++){
            b.insert(0,"0");
        }
        // cout<<a<<endl<<b<<endl;
        length=a.length();
        ans.clear();
        carry=0;
        for(int i=length-1;i>=0;i--){
            temp=(a[i]-'0')+(b[i]-'0');
            temp+=carry;
            tempStr=(temp%10)+'0';
            ans.insert(0, tempStr);
            carry=temp/10;
            if(i==0){
                if(carry){
                    cout<<1;
                }
            }
        }
        for(int i=0;i<length;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}