#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j > 0; j--)
        {
            if(arr[j] < arr[j-1]) //swap
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
        }
    }

    printf("The ascending sorted array is: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n");
    insertion_sort(arr, n);
    return 0;
}