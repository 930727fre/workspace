#include <stdio.h>

int main(){
	int n,a,f;
	scanf(" %d",&n);
	for(int p=0;p<n;p++){
		scanf(" %d%d",&a,&f);
		for(int i=0;i<f;i++){
			for(int j=0;j<a;j++){
				for(int k=0;k<a-j-1;k++){
					printf(" ");
				}
				for(int k=0;k<j+1;k++){
					printf("%d",j+1);
				}
				printf("\n");
			}
			for(int j=a-2;j>=0;j--){
				for(int k=0;k<a-j-1;k++){
					printf(" ");
				}
				for(int k=0;k<j+1;k++){
					printf("%d",j+1);
				}
				printf("\n");

			}
			if(p!=n-1||i!=f-1){
				printf("\n");
			}
		}		
	}

}