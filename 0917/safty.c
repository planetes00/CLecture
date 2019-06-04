#include <stdio.h>

int main(){
    int x=0;//받는 변수
    //묻는다
     printf("input an integer(1~100): ");
    //받는다
     scanf("%d",&x);
    //반복한다
    //만약 그게 1보다 작고 100보다 크다면
    while(x<1||x>100){
        //묻는다
        printf("input an integer(1~100): ");
        //받는다
         scanf("%d",&x);
    }

    //얘가 정신을 차리면 뱉는다.
    printf("input number is %d\n",x);
    return 0;
}