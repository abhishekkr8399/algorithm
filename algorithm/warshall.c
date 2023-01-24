#include <stdio.h>
#include <stdlib.h>
int A[25][25];
void Warshalls(int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
}
int main()
{
    int v, e, i, j, v1, v2;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("\nEnter %d edges :\n", e);
    for (i = 1; i <= e; i++)
    {
        printf("Edge-%d : ", i);
        scanf("%d%d", &v1, &v2);
        A[v1][v2] = 1;
    }
    printf("\nAdjacency matrix :\n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
            printf(" %d", A[i][j]);
        printf("\n");
    }
    Warshalls(v);
    printf("\nTransitive closure : \n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
            printf(" %d", A[i][j]);
        printf("\n");
    }
    return 0;
}
