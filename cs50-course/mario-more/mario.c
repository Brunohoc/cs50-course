#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for valid input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //building the pyramid
    int i, j, k;

    for (i = 0; i < height; i++)
    {
        for (k = 0; k < height - 1 - i; k++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}