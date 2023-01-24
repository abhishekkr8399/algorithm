#include <stdio.h>
#include <stdlib.h>
void Merge(int b[], int c[], int a[], int p, int q)
{
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) // whether any subarray b or c is exhausted
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if (i == p)
    {
        while (j < q && k < (p + q))
        {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < p && k < (p + q))
        {
            a[k] = b[i];
            k++;
            i++;
        }
    }
}
void mergeSort(int n, int a[])
{
    if (n > 1)
    {
        int i, j, len;
        len = n / 2;
        int b[len], c[n - len]; // divide array into two subarrays of equal parts
        for (i = 0, j = 0; i < len && j < len; i++, j++)
        {
            b[j] = a[i];
        }
        for (i = len, j = 0; i < n && j < n - len; i++, j++)
        {
            c[j] = a[i];
        }
        mergeSort(len, b);
        mergeSort(n - len, c);
        Merge(b, c, a, len, n - len);
    }
}
int main()
{
    int i, n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    mergeSort(n, a);
    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    return 0;
}
