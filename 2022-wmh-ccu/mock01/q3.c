#include <stdio.h>

int main(){
	double h,w,temp;
	scanf(" %lf%lf",&h,&w);
	h=(int)h;
	temp=w*10-(int)(w)*10;
	temp=(int)temp;
	w=temp/10+(int)w;
	h=h/100;

	temp=w/h/h;
	//printf("%lf %lf %lf\n",h,w,temp);


	if(h>=1.96||h<=1.57){
		printf("MILITARY SERVICE EXEMPTION");
	}
	else{
		if(temp<16.5||temp>31.5){
			printf("MILITARY SERVICE EXEMPTION");
		}
		else if((16.5<=temp&&temp<17)||(31<temp&&temp<=31.5)){
			printf("ALTERNATIVE SERVICE");
		}
		else{
			printf("REGULAR SERVICE");
		}
	}
}