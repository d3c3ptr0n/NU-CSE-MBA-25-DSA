#include <stdio.h>

int binary_search(int arr[], int n, int find)
{
    int start = 0, end = n-1;

    if(arr[start] < arr[end]) // if array is in ascending order
    {
        while(start <= end)
        {
            int middle = start + (end - start)/2;
            if(find < arr[middle])
                end = middle - 1;
            else if(find > arr[middle])
                start = middle + 1;
            else
                return middle;
        }
    }    
    else if(arr[start] > arr[end]) // if array is in descending order
    {
        while(start <= end)
        {
            int middle = start + (end - start)/2;
            if(find > arr[middle])
                end = middle - 1;
            else if(find < arr[middle])
                start = middle + 1;
            else
                return middle;
        }
    }
    else // if all elements of the array are same
        return 0;
    
    return -1;
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
    int find;
    printf("Enter the number you want to search: ");
    scanf("%d", &find);

    printf("\n");
    int index = binary_search(arr, n, find);
    if(index == -1)
        printf("%d is not in the array.\n", find);
    else 
        printf("%d found at index %d.\n", find, index);
    return 0;
}