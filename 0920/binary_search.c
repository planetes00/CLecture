#include <stdio.h>

int main()
{
    int guess = 0;
    int lower = 0, upper = 0;
    char answer = 0;

    //Tell the user to select a number between 1 and 100
    printf("Select a number between 1 and 100.\n");

    //Initialize lower by 1 and upper by 100
    lower = 1;
    upper = 100;

    //Repeat while lower <= upper
    while(lower <= upper){
        //Hit average of upper and lower
        guess = (upper + lower) / 2;

        //Read user’s response
        printf("Is it %d?\n", guess);
        scanf(" %c", &answer);

        //If guess is too small (answer == ‘<‘), lower = guess + 1
        if(answer == '<')
            lower = guess + 1;

        //If guess is too large (answer == ‘>‘), upper = guess - 1
        if(answer == '>')
            upper = guess - 1;

        //If answer is ‘=’, print a message and terminate loop
        //User break; statement
        if(answer == '='){
            printf("Yes! I got it! ...\n");
            break;
        }
    }

    return 0;
}