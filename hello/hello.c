#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get name from user
    string name = get_string("What's your name? ");

    //print hello, user
    printf("hello, %s\n", name);
}