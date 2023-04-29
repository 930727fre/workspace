#include<bits/stdc++.h>
using namespace std;

int arr[10000];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            int r[n + 1];
            for(int k = 1; k <= n; k++) r[k] = arr[k]; 
            for(int k = i; k <= j; k++){
                swap(r[k], r[j - k + 1]);
            }
            int sum = 0;
            int m = 0;
            for(int k = 1; k <= n; k++){
                sum += r[k];
                if(sum < 0) sum = 0;
                if(sum > m) m = sum;
            }
            cout << m << "\n";
        }
    }
}