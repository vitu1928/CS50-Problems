#include <stdio.h>
#include <cs50.h>
#include <math.h>
// Tests
// 4003600000000014
// 5152333451589881
// 348722771093101

int main(void)
{
    long long creditNumber = get_long_long("Number: ");
    long long _creditNumber = creditNumber;
    int digitos = 0, soma_primer_digit = 0, soma_segund_digit = 0;
    bool vezPrimer = true;

    while (creditNumber > 0)
    {

        int num = creditNumber % 10;
        if (vezPrimer) soma_segund_digit += num;
        else
        {
            if ((num) >= 5) soma_primer_digit += (((num) * 2) % 10) + floor((((num) * 2) / 10));
            else soma_primer_digit += (num) * 2;
        }

        creditNumber /= 10;
        digitos++;
        vezPrimer = !vezPrimer;
    };

    int primers_digit = floor(_creditNumber / pow(10, (digitos - 2)));
    bool valido = (soma_primer_digit + soma_segund_digit) % 10 == 0;

    // American Express uses 15-digit numbers, start with 34 or 37
    if ((primers_digit == 34 || primers_digit == 37) && digitos == 15 && valido) printf("AMEX\n");
    // Visa uses 13- and 16-digit numbers, start with 4
    else if ((digitos >= 13 && digitos <= 16) && floor(primers_digit / 10) == 4 && valido) printf("VISA\n");
    // MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55
    else if ((primers_digit >= 51 && primers_digit <= 55) && digitos == 16 && valido) printf("MASTERCARD\n");
    // Invalid
    else printf("INVALID\n");
}