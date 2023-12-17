#include <stdio.h>

int main() {
    int electricity;
    double summer_rate, non_summer_rate;
    // 計算夏月和非夏月的金額
    double summer_cost = 0.0;
    double non_summer_cost = 0.0;

    // 輸入度數
    scanf("%d", &electricity);

    // 判斷夏月和非夏月的電費率
    if(electricity>700){
        summer_cost+=5.63*(electricity-700);
        non_summer_cost+=4.50*(electricity-700);
        electricity=700;
    }
    if(electricity>500){
        summer_cost+=4.97*(electricity-500);
        non_summer_cost+=4.01*(electricity-500);
        electricity=500;
    }    
    if(electricity>330){
        summer_cost+=4.39*(electricity-330);
        non_summer_cost+=3.61*(electricity-330);
        electricity=330;
    }  
    if(electricity>120){
        summer_cost+=3.02*(electricity-120);
        non_summer_cost+=2.68*(electricity-120);
        electricity=120;
    }  

    summer_cost+=2.10*(electricity);
    non_summer_cost+=2.10*(electricity);
  

    // 輸出結果，保留兩位小數
    printf("Summer months:%.2lf\nNon-Summer months:%.2lf\n", summer_cost, non_summer_cost);

    return 0;
}
