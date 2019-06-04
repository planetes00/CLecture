#include <stdio.h>
int main(){
    FILE *fp= NULL;
    int i=0;
    fopen("number.txt","r");
    for(i=0;i<100;i++){
        int x=0;
        fscanf(fp,"%d",&x);
        printf("%d ",x);
    }
    printf("\n");
    fclose(fp);
    return 0;
}