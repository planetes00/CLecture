#include <stdio.h>
int CountChar(char Text[ ]);
int main()
{
    char text[256];
    printf("Input a text line: ");
    gets(text);

    printf("String\"%s\" has %d characters.\n", text, CountChar(text));
    return 0;
}
int CountChar(char Text[ ])
{
    int i=0;
    i=0;//안정성을 위해서 넣어줍니다. 여기서는 딱히 필요없지만,
    while(Text[i]!=0){
        i++;
    }
    return i;
}