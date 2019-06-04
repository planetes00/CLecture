#include <stdio.h>
int main()
{
    char text[256];
    int no_char=0, no_word=0;
    int i=0;
    
    printf("Input a text line: ");
    gets(text);

    i=0;
    while(text[i]!=0){
        //만약  스페이스가 아니고, 그 앞게 0이거나, 그 앞이 스페이스면 
        if(text[i]!=' '){
            if(text[i-1]==' '||i==0){
                //늘려버려 단어수
                no_word++;
            }
        }
        i++;
    }
    no_char=i;
    printf("String\"%s\" has %d characters and %d words.\n", text, no_char,no_word);
    return 0;
}