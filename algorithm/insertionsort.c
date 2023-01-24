#include <stdio.h>
#include <stdlib.h>
void InsertionSort(int a[], int n)
{
    int i, j, v;
    for (i = 1; i < n; i++) // Adding one element at a time to its original position
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
int main()
{
    int i, n;
    printf("Enter the value of n :");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d element:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    InsertionSort(a, n);
    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    return 0;
}