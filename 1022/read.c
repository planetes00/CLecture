#include <stdio.h>
#define FILE_NAME "number.txt"
int main(){
    
    FILE *fp =NULL;
    int i=0;
    //open a file
    fp=fopen(FILE_NAME,"w");
    //print numbers into the stream(fp)
    for(i=1;i<=100;i++){ 
        fprintf(fp,"%d ",i);
    }

    //close file
    fclose(fp);
    return 0;
}