#include <stdio.h> 
#include <stdlib.h>

enum RomanNumbers {
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};

int romanToInt(char* s)
{
    int total = 0;
    while (*s != '\0')
    {
        char nextChar = *(s + 1);
        switch (*s)
        {
        case 'I':
            if (nextChar == 'V')
            {
                total += V - I;
                s++;
            }
            else if (nextChar == 'X')
            {
                total += X - I;
                s++;
            }
            else
            {
                total += I;
            }
            break;

        case 'V':
            total += V;
            break;

        case 'X':
            if (nextChar == 'L')
            {
                total += L - X;
                s++;
            }
            else if (nextChar == 'C')
            {
                total += C - X;
                s++;
            }
            else
            {
                total += X;
            }
            break;

        case 'L':
            total += L;
            break;

        case 'C':
            if (nextChar == 'D')
            {
                total += D - C;
                s++;
            }
            else if (nextChar == 'M')
            {
                total += M - C;
                s++;
            }
            else
            {
                total += C;
            }
            break;

        case 'D':
            total += D;
            break;

        case 'M':
            total += M;
            break;
        }
        s++;
    }
    return total;
}

int main(int argc, char const* argv[])
{
    char* s = "MCMXCIV";
    printf("%s: %d\n", s, romanToInt(s));
    return 0;
}
