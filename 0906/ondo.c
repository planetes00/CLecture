#include <stdio.h>
int main(){
    float celsi=0, fahr=0;//섭씨변수, 화씨변수
    //물어보자
    printf("화씨로 몇 도입니까?\n");
    //입력
    scanf("%f",&fahr);
    //계산해라
    celsi=(fahr-32)*5/9;
    //뱉어라!
    printf("섭씨로 %f도 입니다!\n",celsi);
}