#include <stdio.h>
int main()
{
    double a=0., b=0.;// 변수. 받을 숫자 2개 (타입은 더블)
    double result=0;//결과(더블)
    char op=0;//연산자

    //값을 입력
    printf("input a binary expression: ");
    scanf("%lf %c %lf", &a, &op, &b);
    //결과 계산
    //+이면 더한다.
    if(op=='+'){
        result=a+b;
    //-면 곱한다 
    }else if(op=='-'){
        result=a-b;
    //*면 뺀다
    }else if(op=='*'){
        result=a*b;
    ///면 나눈다.
    }else if(op=='/'){
        //분모가 0이면 아니다 이 앙마야하면서 에러메세지 띄우고 결과를 0으로 돌리자.
        if(b==0){
            printf("error! division by zero!\n");
            result=0;
        //아니면 곱게 계산해주자.
        }else{
            result=a/b;
        }
    }



    //출력
    printf("%lf %c %lf = %lf\n", a, op, b,result);
    return 0;
}