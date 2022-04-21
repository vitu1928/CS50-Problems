#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string cypher(string str, string alphabet);

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] != NULL)
    {
        printf("Usage: ./substitution KEY\n");
        exit(1);
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    else
    {
        int haveRepeatedCharacters = 0;
        for (int i = 0, len = strlen(argv[1]); i != len; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                exit(1);
            }
            else
            {
                for (int o = i + 1, leng = strlen(argv[1]); o != leng; o++)
                {
                    if (argv[1][i] == argv[1][o]) haveRepeatedCharacters = 1;
                }
            }
            if (i == len - 1)
            {
                if (haveRepeatedCharacters != true)
                {
                    string phrase = get_string("plaintext: ");

                    string c = cypher(phrase, argv[1]);
                    printf("ciphertext: %s\n", c);
                }
                else
                {
                    printf("Key must not contain repeated characters.\n");
                    exit(1);
                }
            }
        }
    }
}

string cypher(string str, string alphabet)
{
    string encryptedText = str;

    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            int v;
            char letter;

            if (isupper(str[i]))
            {
                v = str[i] - 65;
                if (isupper(alphabet[v]))
                    encryptedText[i] = alphabet[v];

                else
                    encryptedText[i] = alphabet[v] - 32;

            }
            else
            {
                v = str[i] - 97;
                if (islower(alphabet[v]))
                    encryptedText[i] = alphabet[v];

                else
                    encryptedText[i] = alphabet[v] + 32;

            }

        }
    }

    return encryptedText;
}