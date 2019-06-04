#include <stdio.h>

int main(){
    int x=0;
    char bits[33];
    //read a integer
    printf("input a integer: ");
    scanf("%d",&x);

    /*나누어줄 2진수를 만들어줍니다. 
    unsigned 한 이유는 integer 의 제일 앞에 있는 애가 부호를 나타내기 때문이에요.*/
    unsigned int m=1<<31;

    //convert integer into bit string
    int i=0;
    for(i=0;i<32;i++){
        if(x&m)
            bits[i]='1';
        else
            bits[i]='0';
        m>>=1;
    }
    bits[i]=0;
    
    //print the string.
    printf("integer = %d = %s\n",x,bits);
    return 0;
}