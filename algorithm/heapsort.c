#include <stdio.h>
#include <stdlib.h>
void Heapify(int H[], int n) // To construct the heap
{
    int k, v, i, j, heap = 0;
    for (i = (n / 2); i >= 1; i--)
    {
        k = i;
        v = H[k];
        heap = 0;
        while (!heap && (2 * k) <= n)
        {
            j = 2 * k; // Get the left child of a root node
            if (j < n) // To check whether root had right child also
                if (H[j] < H[j + 1])
                    j++;
            if (v >= H[j])
                heap = 1;
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}
void HeapSort(int H[], int n)
{
    int i;
    Heapify(H, n);
    for (i = n; i >= 2; i--)
    {
        H[1] = H[1] + H[i]; //
        H[i] = H[1] - H[i]; // SWAP without using temp
        H[1] = H[1] - H[i]; // It is same even if swapping done using temp
        Heapify(H, i - 1);
    }
}
int main()
{
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter %d elements :\n", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("Array before sorting:\n");
    for (i = 1; i <= n; i++)
        printf("\t%d", a[i]);
    HeapSort(a, n);
    printf("\nArray after sorting:\n");
    for (i = 1; i <= n; i++)
        printf("\t%d", a[i]);
    return 0;
}
