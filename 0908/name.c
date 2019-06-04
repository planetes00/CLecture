#include <stdio.h>
int main(){
    int num1, num2, num3; // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
	int max_num, min_num; // 가장 큰 숫자, 가장 작은 숫자 
	//숫자 세개 입력합시다.
	printf("첫번째 숫자?");
	scanf("%d",&num1);
	printf("두번째 숫자?");
	scanf("%d",&num2);
	printf("세번째 숫자?");
	scanf("%d",&num3);
    //1번이 가장 클경우->max=num1
    if(num1>num2&&num1>num3){
        max=num1;
        //가장 작은 수는 2번 혹은 3번->if(num2<num1){}else{}
        if(num2<num3) min=num2;
        else min=num3
    //아니면 2가 가장클경우->max=num2
    }else if(num2>num1&&num2>num3){}
        //가장 작은 수는 1번 혹은 3번
    //아니면 ->max=num3
    }else{
        //가장 작은 수는 1번 혹은 2번
    }
    printf()
    return 0;
}