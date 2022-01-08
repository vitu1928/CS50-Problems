#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

char *
str_repeat(char str[], unsigned int times)
{
    if (times < 1)
        return "";

    char *result;
    size_t str_len = strlen(str);
    result = malloc(sizeof(char) * str_len + 1);

    while (times--)
        strcat(result, str);

    return result;
}

int main(void) {
    int height;
    do
    {
        // printf("Height: ");
        // scanf("%d", &height)
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int spaces = height - 1, hashs = 1, num = 1; num <= height; num++, --spaces, hashs++)
        printf(
            "%s%s\n",
            str_repeat(" ", spaces),
            str_repeat("#", hashs),
            str_repeat("#", hashs)
        ); // Fazendo as pirâmides
        
        
    // for (int spaces = height - 1, hashs = 1, num = 1; num <= height; num++, --spaces, hashs++)
    //     printf(
    //         "%s%s %s%s\n",
    //         str_repeat(" ", hashs),
    //         str_repeat("#", spaces),
    //         str_repeat("#", spaces),
    //         str_repeat(" ", hashs)
    //     ); // Fazendo as pirâmides ao contrário
}
