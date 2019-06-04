#include <stdio.h>

int main()
{
    int height=0; // input height
    int i=0, j=0 ;  // integer for repeat
    //Input the height of triangle:
    printf("Input the height of triangle: ");
    scanf("%d",&height);
    //repeat: height~1
    for(i=1;i<=height;i++){
        //repeat print star: 0~i-1
        for(j=1;j<=i;j++){
            //star
            printf("%d",j);
        }
        //line break
        printf("\n");
    }
    return 0;
}