#include <stdio.h>
int main(){
    int num_max=0;//알아낸 최소 숫자
    int num_min=101;//알아낸 최대숫자
    int input_num=50;//뱉는 아이.
    char size=0;//크다 작다 맞다
    int x=1;//횟수
    //50은 어때?
    printf("select a number between 1 and 100\n");
    printf("How about %d? (try more : <, try less : >, right : =)",input_num);
    scanf(" %c",&size);
    //반복한다.
    while(num_min>=num_max){
         //중간값 계산
        input_num=(num_min+num_max)/2;
        //만약 작댄다!
        if(size=='>'){
            //최소숫자를 50으로 설정
            num_min=input_num;
            //횟수하나 늘린다
            x++;
            //만약 크댄다
        }else if(size=='<'){
            //최대숫자를 그걸로 설정
            num_max=input_num;
            //횟수하나 늘린다
            x++;
            //0이다
        }else if(size=='='){
            //이거군요! 하면서 알려준다.
            printf("your number is %d\n",input_num);
            //멈춘다
            break;
            //횟수하나 늘린다
            x++;
        }
        printf("How about %d? (try more : 1, try less : 2, right : 0)",input_num);
        scanf(" %c",&size);
    }
    //횟수를 알려준다.
    printf("%d tried.\n",x);
    return 0;
}