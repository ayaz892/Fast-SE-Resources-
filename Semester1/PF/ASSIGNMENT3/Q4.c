//Assignment No = 03
 //Section =SE-2A
 //Std.Id = 20K-1044
 //Name = MUHAMMAD AYAZ

#include <stdio.h>

void sort(int arr[], int size)
{
	int temp,i;
    temp = arr[size - 1];
    
    for (i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    
    for (i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int size,i;
    
    printf("Enter size of element: ");
    scanf("%d",&size);
    
    int arr[size];
    
    for (i = 0; i < size; i++)
    {
        printf("Enter element number ", i + 1, ": ");
        
        scanf("%d",&arr[i]);
    }
    sort(arr, size);

    return 0;
}
