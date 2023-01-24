#include <stdio.h>
#include <stdlib.h>
int binarySearch(int a[], int n, int key)
{
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2; // Find mid element
        if (a[mid] == key)
            return mid;
        if (key < a[mid])
            high = mid - 1; // Search in first half
        else
            low = mid + 1; // Search in second half
    }
    return -1;
}
int main()
{
    int n, key, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements in non-decreasing order : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key element \n");
    scanf("%d", &key);
    i = binarySearch(a, n, key);
    if (i == -1)
        printf("Key element is not found!");
    else
        printf("%d is present at position %d ", key, i + 1);
    return 0;
}