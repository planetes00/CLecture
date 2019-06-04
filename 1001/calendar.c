#include <stdio.h>

int main()
{
    int i=0; 
    int kan=0, nal=0;
    //띄는 칸, 전체 날자 알아내기
    printf("input start day and number of days : ");
    scanf("%d %d",&kan,&nal);
    //월화수 찍기
    printf("SUN\t");
    printf("MON\t");
    printf("TUE\t");
    printf("WED\t");
    printf("THU\t");
    printf("FRI\t");
    printf("SAT\t");
    printf("\n");
    //찍찍이 찍기
    //반복한다 0에서 6까지
    for(i=0;i<7;i++){
        //찍찍이 세개를 찍고 탭을 한다.
        printf("---\t");
    }
    //엔터!
    printf("\n");
    //빈칸 찍기
    //반복한다. 0에서 빈칸 하나 전까지. 
    for(i=0;i<kan;i++){
        //사실 탭하면 될거 같다 음..
        printf("\t");
    }
    //날짜 찍기
    //반복한다. 1에서 날짜까지
    for(i=1;i<=nal;i++){
        //날짜찍는다
        printf("%d\t",i);
        //만약 빈칸이랑 그날의 날짜랑 더해서 7의 배수가 된다면
        if((kan+i)%7==0){
            //엔터를 쳐준다.
            printf("\n");
        }
    }
    //엔터!
    printf("\n");
    //찍찍이 찍기
    for(i=0;i<7;i++){
        //찍찍이 세개를 찍고 탭을 한다.
        printf("---\t");
    }
    printf("\n");
    return 0;
}