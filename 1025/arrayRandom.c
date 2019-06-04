#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int array[10];
    int i=0;
    srand(time(NULL));
    for(i=0;i<10;i++){
        array[i]=rand()%100+1;
        printf("array[%d]=%d\n",i, array[i]);
    }
    return 0;
}