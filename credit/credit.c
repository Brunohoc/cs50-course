#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for input:
    long card = get_long("Number: ");


    //printf("%li\n", card);

    //calculate checksum:
    int i;
    for (i = 1; i < 5; i++)
    {
        int tens = card % (10 * i);


        //Find total number of digit - 1
        int n_digit = (int)log10(tens);

        //Find first digit
        int firstDigit = (int) (tens / pow(10, n_digit));

        printf("%i   %i   %i   %i\n", i, tens, n_digit, firstDigit);

    }




    //check for card length and starting digits:

    //print AMEX, MASTERCARD, VISA, or INVALID:
}