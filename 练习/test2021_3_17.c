#include <stdio.h>

int main()
{
    long int n = 0;
    int i = 0;
    long int a, b, c, d, e, f;
    long int cont = 0;
    scanf("%ld", &n);
    for (i = 1; i <= n; i++)
    {
        if (i < 10)
        {
            cont++;
            continue;
        }
        if (i >= 10 && i < 100)
        {
            a = i / 10;
            b = i % 10;
            if (a <= b)
            {
                cont++;
                continue;
            }
        }
        if (i >= 100 && i < 1000)
        {
            a = i / 100;
            b = i / 10 % 10;
            c = i % 10;
            if (a <= b && b <= c)
            {
                cont++;
                continue;
            }
        }
        if (i >= 1000 && i < 10000)
        {
            a = i / 1000;
            b = i / 100 % 10;
            c = i / 10 % 10;
            d = i % 10;
            if (a <= b && b <= c && c <= d)
            {
                cont++;
                continue;
            }
        }
        if (i >= 10000 && i < 100000)
        {
            a = i / 10000;
            b = i / 1000 % 10;
            c = i / 100 % 10;
            d = i / 10 % 10;
            e = i % 10;
            if (a <= b && b <= c && c <= d && d <= e && e <= f)
            {
                cont++;
                continue;
            }
        }
        if (i >= 100000 && i < 1000000)
        {
            a = i / 100000;
            b = i / 10000 % 10;
            c = i / 1000 % 10;
            d = i / 100 % 10;
            e = i / 10 % 10;
            f = i % 10;
            if (a <= b && b <= c && c <= d && d <= e)
            {
                cont++;
                continue;
            }
        }
    }
    printf("%ld", cont);

    return 0;
}