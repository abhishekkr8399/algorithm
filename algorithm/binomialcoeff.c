#include <stdio.h>
#include <stdlib.h>
int min(int i, int k)
{
    if (i < k)
        return i;
    else
        return k;
}
int Binomial(int n, int k, int C[n + 1][k + 1])
{
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= min(i, k); j++)
            if (j == 0 || i == j) // C(n,n)==1 or C(n,0) =1
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    return C[n][k];
}
int main()
{
    int n, k, coeff;
    printf("Enter n and k in C(n,k) : ");
    scanf("%d%d", &n, &k);
    if (k > n)
    {
        printf("Invalid input!"); // C (n,k) for n<k is not defined
        exit(0);
    }
    int table[n + 1][k + 1];
    coeff = Binomial(n, k, table);
    printf("Binomial coefficient, C(%d,%d)=%d", n, k, coeff);
    return 0;
}
