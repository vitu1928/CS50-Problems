#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int dollars;
    do
    {
        dollars = round(get_float("Cash owned: ")* 100);
    } while (dollars < 0.0);
    int coins[] = {25, 10, 5, 1}, _coins = 0;
    for (int numb = 0; dollars > 0.0 && numb <= 3;)
    {
        if (dollars >= coins[numb]) {
            // printf("%u %d %d\n", dollars, numb, _coins);
            _coins++;
            dollars -= coins[numb];
        } else numb++;
    };
    printf("%d\n", _coins);
}