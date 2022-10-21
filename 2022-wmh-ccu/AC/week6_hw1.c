#include <stdio.h>

int main(){
    int year, month, date, sum=0, counter=0,temp;
    scanf("%d/%d/%d",&year,&month,&date);
    while(scanf("%d",&temp)!=EOF){
        sum+=temp;
        counter++;
    }
    sum=sum/counter;

    while(sum!=0){
        switch(month){
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                if(sum+date>31){
                    if(month!=12){
                        month+=1;
                    }
                    else{
                        month=1;
                        year++;
                    }
                    sum-=(32-date);
                    date=1;
                }
                else{
                    date+=sum;
                    sum=0;
                }
                break;
            case 2:
                if((year%4==0&&year%100!=0)||year%400==0){
                    if((sum+date)>29){
                        month+=1;
                        sum-=(30-date);
                        date=1;
                    }
                    else{
                        date+=sum;
                        sum=0;
                    }
                }
                else{
                    if((sum+date)>28){
                        month+=1;
                        sum-=(29-date);
                        date=1;
                    }
                    else{
                        date+=sum;
                        sum=0;
                    }
                }
                break;
            case 4: case 6: case 9: case 11:
                if((sum+date)>31){
                    month+=1;
                    sum-=(31-date);
                    date=1;
                }
                else{
                    date+=sum;
                    sum=0;
                }
                break;               
        }
    }
    printf("%d/",year);
    if(month<10){
        printf("0");
    }
    printf("%d/",month);
    if(date<10){
        printf("0");
    }
    printf("%d",date);


    return 0;
}
