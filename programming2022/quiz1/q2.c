#include <stdio.h>

int main(){
    int h,m,time,previous=0;
    int darada, coco, luna, tmt, kanata;
    scanf(" %d%d",&h,&m);
    time=h*60+m;
    darada=time/302;
    time=time%302;
    coco=time/124;
    time=time%124;
    luna=time/90;
    time=time%90;
    tmt=time/66;
    time=time%66;
    kanata=time/24;
    m=time%24;
    if(darada!=0){
        printf("%d Darada",darada);
        previous=1;
    }
    if(coco!=0){
        if(previous==1){
            printf(" ");
        }
        printf("%d Coco",coco);
        previous=1;
    }
    if(luna!=0){
        if(previous==1){
            printf(" ");
        }
        printf("%d Luna",luna);
        previous=1;
    }
    if(tmt!=0){
        if(previous==1){
            printf(" ");
        }
        printf("%d TMT",tmt);
        previous=1;
    }
    if(kanata!=0){
        if(previous==1){
            printf(" ");
        }
        printf("%d Kanata",kanata);
        previous=1;
    }
    if(m!=0){
        if(previous==1){
            printf(" ");
        }
        printf("%d Min",m);
    }
    if(darada==0 &&coco==0&&luna==0&&tmt==0&&kanata==0&&m==0){
        printf("0 Min");
    }
    printf("\n");
    return 0;
}