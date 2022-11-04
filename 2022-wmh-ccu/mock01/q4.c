#include <stdio.h>
#include <math.h>

int fc(int m,int flag){
	//printf("n= %d\n",m);
	if(m==1){
		return 1;
	}
	else if(m%10==m && flag==0){
		return 0;		
	}
	else if(m%10==m && flag==1){
		fc(m*m,0);
	}
	else{
		
		int temp=m,degree=0,sum=0,a,b;
		while(1){
			degree++;
			if(temp<10){
				break;
			}
			else{
				temp=temp/10;
			}
		}
		//printf("degree= %d\n",degree);
		a=0;
		b=0;//105 b=5 
		for(int i=0;i<degree;i++){
			temp=pow(10,i+1);
			a=((m%temp)-b)/pow(10,i);
			//printf("%d\n",a);
			sum+=a*a;
			b=a+b;
		}
		//printf("sum= %d\n",sum);
		fc(sum,0);
	}
	
}

int main(){
	int m,n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		printf("Case #%d: %d is ",i+1,n);
		if(fc(n,1)){
			printf("a Happy number.\n");
		}
		else{
			printf("an Unhappy number.\n");
		}
	}
}