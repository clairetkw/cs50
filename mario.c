#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1) ; j++)
            //for (int j = (n - 1); j > i; j--)
        {
            printf(" ");
        }


        for (int k = 0; k < (i + 1); k++)
            //for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }


        printf("  ");


        for (int m = 0; m < i + 1; m++)
            //for (int m = i + 1; m > 0 ; m--)
        {
            printf("#");
        }


        printf("\n");
    }

}