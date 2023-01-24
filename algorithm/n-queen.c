#include <stdio.h>
#include <stdlib.h>
int cannotBePlaced(int k, int col[])
{
    int i;
    for (i = 1; i <= k - 1; i++) // Check whether 2 queens attack vertically, horizontally or diagonally
        if (col[k] == col[i] || (abs(i - k) == abs(col[i] - col[k])))
            return 1; // Queen k cannot be placed in row k and column col[k]
    return 0;
}
int NQueen(int n)
{
    int k = 1;     // Indicated queen to be placed and row number
    int count = 0; // Number of possible solutions
    int i, j, col[n + 1];
    col[k] = 0;    // Queen 1 is selected but yet to be placed in row 1 and column a[1]
    while (k != 0) // Backtrack till any one queen exists
    {
        col[k] = col[k] + 1; // Place queen k in 1st column
        while (col[k] <= n && cannotBePlaced(k, col))
            col[k] = col[k] + 1; // Move queen k to next column
        if (col[k] <= n)         // Queen successfully placed
        {
            if (k == n) // All queens are placed
            {
                count++;
                printf("\nSolution-%d :\n", count);
                for (i = 1; i <= n; i++)
                {
                    for (j = 1; j <= n; j++)
                        if (col[i] == j)
                            printf(" Q%d", i);
                        else
                            printf(" * ");
                    printf("\n\n");
                }
            }
            else
            {
                k++;        // Select next queen
                col[k] = 0; // Queen k is yet to be placed
            }
        }
        else
            k--; // Backtrack and select previous queen
    }
    return count;
}
int main()
{
    int n, solutions;
    printf("Enter the number of queens : ");
    scanf("%d", &n);
    solutions = NQueen(n);
    if (solutions == 0)
        printf("No solution!!");
    return 0;
}