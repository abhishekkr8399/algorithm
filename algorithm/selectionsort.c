#include <stdio.h>
#include <stdlib.h>
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++) // Find smallest element in the array
            if (a[j] < a[min])
                min = j;
        temp = a[min]; // Place the min element in ith position
        a[min] = a[i];
        a[i] = temp;
    }
}
int main()
{
    int i, n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Before Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    selectionSort(a, n);
    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}
