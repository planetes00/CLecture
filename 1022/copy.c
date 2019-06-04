#include <stdio.h>

#define SRC_FILE "file_read.c"
#define DEST_FILE "dest.txt"

int main()
{
    FILE *in = NULL, *out = NULL;

    in = fopen(SRC_FILE, "r");
    out = fopen(DEST_FILE, "w");

    while(1){
        int c = 0;
        c = fgetc(in);
        
        if(c == EOF)
            break;
        fputc(c, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}