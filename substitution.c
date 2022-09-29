#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    char ciphertext[1000] = "";
    if (argc != 2)
        //only 2 arguments must be present
    {
        printf("Usage: ./substitution <key>");
        return 1;
    }



    string key = argv[1];
    if (strlen(key) != 26)
        //key must have 26 characters
    {
        printf("Key must have 26 characters.\n");
        return 1;
    }



    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == 0)
            //all characters must be alphabetical
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }
    }



    for (int j = 0; j < 25; j++)
    {
        for (int k = j + 1; k < 26; k++)
        {
            if (key[j] == key[k])
                //key must not have duplicate characters
            {
                printf("Key must not contain duplicate characters.\n");
                return 1;
            }
        }
    }



    for (int x = 0; x <= strlen(key); x++)
    {
        key[x] = tolower(key[x]);
    }



    string plaintext = get_string("plaintext: ");
    for (int a = 0; a <= strlen(plaintext); a++)
    {
        if (islower(plaintext[a]) == 0)
            //if letters of the plaintext not lowercase (i.e. uppercase or special characters)
        {
            int b = plaintext[a] - 65;
            if (b > -1 && b < 26)
            {
                char upper = key[b];
                ciphertext[a] = toupper(upper);
            }
            else
            {
                ciphertext[a] = plaintext[a];
            }
        }
        else
            //if letters of the plaintext are lowercase
        {
            int c = plaintext[a] - 97;
            if (c > -1 && c < 26)
            {
                char lower = key[c];
                ciphertext[a] = lower;
            }
        }
    }



    printf("ciphertext: %s\n", ciphertext);
    return 0;
}