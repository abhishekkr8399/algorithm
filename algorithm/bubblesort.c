#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)         // Number of passes
        for (j = 0; j < n - i - 1; j++) // For each pass one largest element bubbled to its position
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}
int main()
{
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nElements before sorting :\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    bubbleSort(a, n);
    printf("\nElements after sorting :\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    return 0;
}
