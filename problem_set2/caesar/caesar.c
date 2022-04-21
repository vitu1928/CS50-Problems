#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string cypher(string str, int cypherKey);

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] != NULL)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        for (int i = 0, len = strlen(argv[1]); i != len; i++) 
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                exit(1);
            }
            else if (i == len - 1)
            {
                int key = atoi(argv[1]);
                string phrase = get_string("plaintext: ");

                string c = cypher(phrase, key);
                printf("ciphertext: %s\n", c);
            }
        }
    }
}

string cypher(string str, int cypherKey)
{
    string encryptedText = str;

    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            int ci;
            if (isupper(str[i]))
            {
                ci = (((int) str[i] - 65) + cypherKey) % 26;
                ci += 65;
            }
            else
            {
                ci = (((int) str[i] - 97) + cypherKey) % 26;
                ci += 97;
            }
            encryptedText[i] = (char) ci;
        }
    }

    return encryptedText;
}