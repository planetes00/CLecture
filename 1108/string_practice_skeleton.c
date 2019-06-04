#include <stdio.h>
#include <string.h>

// if necessary, use the following functions declared in string.h
// strlen(str)
// strcmp(str1, str2)
// strcpy(dest, src)
// strcat(dest, src)


char lexicon[1024][64];
int no_word = 0;

void DisplayStringArray(char str_array[][64], int size);
void SortStringArray(char str_array[][64], int size);


int main()
{
    char word[64];
	int ret=0;
	printf("input words(type EOF to finish.)\n");
    // read strings and put them into lexicon until the user types EOF
	while(1){
		ret=scanf("%s",word);
		if(ret==EOF) break;
		strcpy(lexicon[no_word++], word);
	}
    // print all word in the lexicon
	DisplayStringArray(lexicon, no_word);
    // sort lexicon
	SortStringArray(lexicon, no_word);
    // print all word in the lexicon
	DisplayStringArray(lexicon, no_word);
    return 0;
}

void DisplayStringArray(char str_array[][64], int size)
{
	for(int i=0;i<size;i++) printf("%d-th word is \'%s\'\n",i,str_array[i]);
}

void SortStringArray(char str_array[][64], int size)
{
    
    // the following code is the Selection Sort in the lecture slide
    // Convert it to sort an array of string.

    int current=0;			// start of the unsorted str_array

	for(current = 0; current < size - 1; current++){
		int smallest=0;		// location of the smallest element 
		int walk=0;		// variable to traverse the unsorted str_array
		char tempData[64];		// temporary variable for exchange

		// find the smallest in the unsorted str_array
		smallest = current;
		for(walk = current + 1; walk < size; walk++)
			if(strcmp(str_array[walk] , str_array[smallest])<0)
				smallest = walk;

		// exchange the smallest with the first of unsorted str_array
		strcpy(tempData, str_array[current]);
		strcpy(str_array[current], str_array[smallest]);
		strcpy(str_array[smallest] , tempData);
	}
    
}
