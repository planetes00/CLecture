#include <stdio.h>
#include <string.h>

/*
size_t strlen(const char * str);				// returns the length of str
char* strcpy(char *dest, const char *src);		// copy string from src to dest
int strcmp(const char *str1, const char *str2);	// compares str1 with str2
	// returns 0 (str1 == str2), negative (str1 < str2) or positive (str1 > str2)
char* strcat(char *dest, const char *src);	// append src at the end of dest
*/

int main()
{
    char str1[128] = "I love you! ";
    char str2[128] = "God bless you! ";
    char str3[128] = "Nice to see you! ";
    
    printf("str1 = \"%s\", strlen(str1) = %lu\n", str1, strlen(str1));
    printf("str2 = \"%s\", strlen(str2) = %lu\n", str2, strlen(str2));
    printf("str3 = \"%s\", strlen(str3) = %lu\n", str3, strlen(str3));

    printf("before strcpy(), strcmp(str1, str2) = %d\n", strcmp(str1, str2));
    printf("before strcpy(), strcmp(str1, str3) = %d\n", strcmp(str1, str3));

    strcpy(str3, str1);
    printf("str3 = \"%s\"\n", str3);

    printf("after strcpy(), strcmp(str1, str3) = %d\n", strcmp(str1, str3));

    strcat(str3, str2);
    printf("str3 = \"%s\"\n", str3);
    
    return 0;
}