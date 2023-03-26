#include <stdio.h>
#include <vector>
using namespace std;
int main(){
   vector<int> fresh;
   int n,m,r,a,b;
   scanf("%d %d %d",&n,&m,&r);
   for(int i=0;i<r;i++){
      scanf("%d %d",&a,&b);
      fresh.push_back(b);
   }
   for(int i=0;i<m;i++){
      int counter=0;
      for(int j=0;j<r;j++){
         if(fresh[j]-1==i){
            counter++;
         }
      }
      printf("%d ",counter);
   }
}