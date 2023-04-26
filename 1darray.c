// One-dimensional array
/* Given below are some frequently performed functions in 1-D array.
--> Searching
--> Insertion
--> Deletion
--> Sorting
--> Merging
*/

// 1-D array algorithms
#include <stdio.h>
void sort(int arr[], int n);
void search(int arr[], int n);
void linear(int ls[], int n);
void binary(int ba[], int n);
void delete(int arr[], int n);
void insert(int arr[], int n);
void merge(int arr[], int n);
int main()
{
    int choice, n;
    printf("Select any number listed below to use that algorithm");
    printf("\nEnter 1 --> To display sorting of an array");
    printf("\nEnter 2 --> To search an element in array");
    printf("\nEnter 3 --> To delete an element from array");
    printf("\nEnter 4 --> To insert an element to the array");
    printf("\nEnter 5 --> To merge two arrays\n");
    printf("Enter your choice =");
    scanf("%d", &choice);
    printf("Enter the number of elements you want to enter in the array");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    switch (choice)
    {
    case 1:
        sort(arr,n);
        break;
    case 2:
        search(arr,n);
        break;
    case 3:
        delete (arr,n);
        break;
    case 4:
        insert(arr,n);
        break;
    case 5:
        merge(arr,n);
        break;
    default:
        printf("You are entering a wrong choice please try again");
    }
    return 0;
}
void sort(int arr[], int n)
{
    int i, temp;
    printf("Original array -->\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array -->\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}

// Searching in an array:- Liner search and Binary search
// Linear Search
void search(int arr[], int n)
{
    char choice;
    printf("Search an element in the array\n");
    printf("Now choose whether do you want to use linear search or binary search\n");
    printf("\nType 'l' to use linear search or type 'b' to use binary search\n");
    fflush(stdin);
    printf("Enter your choice =");
    scanf("%c", &choice);
    switch (choice)
    {
    case 'l':
        printf("You have choosed linear search -->");
        linear(arr, n);
        break;
    case 'b':
        printf("You have choosed binary search");
        binary(arr, n);
        break;
    }
}
void linear(int ls[], int n)
{
    int num, flag = 0, i;
    printf("Enter the number which you want to search");
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (num == ls[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Element %d found at %d position", num, i + 1);
    else
        printf("Element not found");
}
void binary(int ba[], int n)
{
    int num, end=n-1, beg=0, pos=-1, mid ;
    printf("Enter the number which you want to search using binary search");
    scanf("%d",&num);
    while (beg<=end)
    {
        mid = (beg+end)/2;
        if (ba[mid] == num)
        {
            pos = mid;
            break;
        }
        else if (ba[mid]>num)
        {
            beg = mid+1;
        }
        else if (ba[mid] < num)
        {
            end= mid-1;
        }
    }
    if (pos != -1)
    printf("Element %d found at %d location",num,pos+1);
    else
    printf("Element not found");
}
void delete(int arr[], int n)
{
    int ele, pos, flag = 0;
    printf("Enter the element which you want to delete");
    scanf("%d",&ele);
     // Now first we will find out the position of that element
    for (int i=0; i<n; i++)
    {
        if (arr[i] == ele)
        {
            pos = i; 
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        for(int j=pos; j<n-1; j++)
        {
            arr[j] = arr[j+1];     
        }
        for (int k = 0; k<n; k++)
        printf("%d  ",arr[k]);
    }
    else
    printf("This element is not present in the given array");
}
void insert(int arr[], int n)
{
    int ele, pos;
    printf("Enter the element which you want to insert in this array = ");
    scanf("%d",&ele);
    printf("Enter the position where you want to add this element");
    scanf("%d",&pos);
    for (int i=n-1; i>=pos-1; i--)
    {
        arr[i+1] = arr[i]; 
    }
    arr[pos-1] = ele;
    printf("Displaying the new array\n");
    for (int j=0; j<=n; j++)
    printf("%d  ",arr[j]);
}
void merge(int arr[], int n)
{
    
}