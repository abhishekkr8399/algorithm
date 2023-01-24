#include <stdio.h>
#include <stdlib.h>
int HoarePartition(int a[], int l, int r)
{
    int p, i, j, temp;
    p = a[l];
    i = l;
    j = r + 1;
    do // till i and j crosses each other
    {
        do
        {
            i++;
        } while (a[i] < p && i <= r);
        do
        {
            j--;
        } while (a[j] > p);
        if (i <= r)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    if (i <= r) // Undo unnecessary swap
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    temp = a[l]; // Swap pivot and jth element to put pivot in right position
    a[l] = a[j];
    a[j] = temp;
    return j;
}
void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int s = HoarePartition(a, l, r); // Partition the array into sub-array based on pivot element
        QuickSort(a, l, s - 1);          // Sort first sub-array
        QuickSort(a, s + 1, r);          // Sort second sub-array
    }
}
int main()
{
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nArray before sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    QuickSort(a, 0, n - 1); // Quicksort(a[l,..,r])
    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    return 0;
}
