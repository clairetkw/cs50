#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Get long from user
    long n;
    do
    {
        n = get_long("Number: ");
    }
    // Reject all negative and non-numerical entries
    while (n < 0);


    // Get every even digit from n, starting from the back, before multiplying by 2
    int second_last = ((n % 100) / 10) * 2;
    int fourth_last = ((n % 10000) / 1000) * 2;
    int sixth_last = ((n % 1000000) / 100000) * 2;
    int eighth_last = ((n % 100000000) / 10000000) * 2;
    int tenth_last = ((n % 10000000000) / 1000000000) * 2;
    int twelfth_last = ((n % 1000000000000) / 100000000000) * 2;
    int fourteenth_last = ((n % 100000000000000) / 10000000000000) * 2;
    int sixteenth_last = ((n % 10000000000000000) / 1000000000000000) * 2;


    // Add the sum of the digits from the numbers obtained above
    int digitA = second_last / 10;
    int digitB = second_last % 10;
    int sum1 = digitA + digitB;

    int digitC = fourth_last / 10;
    int digitD = fourth_last % 10;
    int sum2 = digitC + digitD;

    int digitE = sixth_last / 10;
    int digitF = sixth_last % 10;
    int sum3 = digitE + digitF;

    int digitG = eighth_last / 10;
    int digitH = eighth_last % 10;
    int sum4 = digitG + digitH;

    int digitI = tenth_last / 10;
    int digitJ = tenth_last % 10;
    int sum5 = digitI + digitJ;

    int digitK = twelfth_last / 10;
    int digitL = twelfth_last % 10;
    int sum6 = digitK + digitL;

    int digitM = fourteenth_last / 10;
    int digitN = fourteenth_last % 10;
    int sum7 = digitM + digitN;

    int digitO = sixteenth_last / 10;
    int digitP = sixteenth_last % 10;
    int sum8 = digitO + digitP;


    // Get every odd digit from n, starting from the back
    int last = (n % 10);
    int third_last = ((n % 1000) / 100);
    int fifth_last = ((n % 100000) / 10000);
    int seventh_last = ((n % 10000000) / 1000000);
    int ninth_last = ((n % 1000000000) / 100000000);
    int eleventh_last = ((n % 100000000000) / 10000000000);
    int thirteenth_last = ((n % 10000000000000) / 1000000000000);
    int fifteenth_last = ((n % 1000000000000000) / 100000000000000);


    // Add all the digits together before % 10
    int sumtotal = (sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8 + last + third_last + fifth_last +
                    seventh_last + ninth_last + eleventh_last + thirteenth_last + fifteenth_last);
    int checksum = sumtotal % 10;


    // Make sure checksum == 0 and check if n is a valid credit card number
    if ((checksum == 0) && (n / 10000000000000 == 34 || n / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if ((checksum == 0) && (n / 100000000000000 == 51 || n / 100000000000000 == 52 || n / 100000000000000 == 53
                                 || n / 100000000000000 == 54 || n / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((checksum == 0) && (n / 1000000000000 == 4 || n / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}