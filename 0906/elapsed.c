#include <stdio.h>
int main(){
    int startHour=0, startMinute=0; //시작시간,분
    int endHour=0, endMinute=0;//끝 시간, 분
    int elapsedHour=0, elapsedMinute=0;//걸린 시간 , 분

    //시작시간을 받는다.
    printf("input start time :");
    scanf("%d %d",&startHour,&startMinute);

    //끝시간을 받는다.
    printf("input end time :");
    scanf("%d %d",&endHour,&endMinute);

    //시간을 뺀다.
    elapsedHour=endHour-startHour;
    elapsedMinute=endMinute-startMinute;

    //만약 분단위가 0보다 작다
    if(elapsedMinute<0){
        //시간을 하나 줄이고 분에 60을 더해주자!
        elapsedHour=elapsedHour-1;
        elapsedMinute=elapsedMinute+60;
    }
    
    //뱉자
    printf("Elapsed time is %d : %d\n",elapsedHour,elapsedMinute);
}