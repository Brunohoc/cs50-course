// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Missing command-line arguments!\n");
        return 1;
    }
    else
    {
        string input = argv[1];

        for (int i = 0; input[i] != '\0'; i++)
        {
            switch (input[i])
            {
                case 'a':
                    input.Replace('a', '6');
                    break;
                case 'e':
                    input.replace('e', '3');
                    break;

                case 'i':
                    input.replace('i', '1');
                    break;

                case 'o':
                    input.replace('o', '0');
                    break;

                default:
                    break;
            }
        }
        printf("%s\n", input);
    }
}


