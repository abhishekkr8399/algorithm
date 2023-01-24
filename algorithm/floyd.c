#include <stdio.h>
#include <stdlib.h>
int W[25][25];
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void Floyds(int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
}
int main()
{
    int v, e, i, j, v1, v2, w;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    for (i = 1; i <= v; i++)
        for (j = 1; j <= v; j++)
            if (i == j)
                W[i][j] = 0; // Vertex to itself is zero
            else
                W[i][j] = 999; // No direct edge
    printf("\nEnter %d edges :\n", e);
    for (i = 1; i <= e; i++)
    {
        printf("Edge-%d : ", i);
        scanf("%d%d", &v1, &v2);
        printf("Enter the distance %d-->%d : ", v1, v2);
        scanf("%d", &w);
        W[v1][v2] = w;
    }
    printf("\nWeight matrix :\n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
            printf(" %d", W[i][j]);
        printf("\n");
    }
    Floyds(v);
    printf("\nShortest distance matrix : \n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
            printf(" %d", W[i][j]);
        printf("\n");
    }
    return 0;
}