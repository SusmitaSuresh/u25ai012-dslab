#include<stdio.h>
#include<stdlib.h>
void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void insert(int arr[], int *n, int pos, int val)
{
    for (int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}
void delete(int arr[], int *n, int pos)
{
    for (int i = pos; i < *n - 1; i++)
    {    
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
void reverse__using_temp(int arr[], int n)
{
    int temp[20];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - 1 - i];
    }
    display(temp, n);
}
void reverse_inplace(int arr[], int n)
{
    int t;
    for (int i = 0; i < n / 2; i++)
    {
        t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}
void copy_subarray(int subArr[], int n1, int arr[], int *n)
{
    for (int i = 0; i < n1; i++)
    {    
        if(*n<20)
        {
            arr[*n] = subArr[i];
            (*n)++;
        }
    }
}
void merge_desc(int sub1[], int n1, int sub2[], int n2, int main[])
{
    int k=0, temp;
    for(int i=0, j=0; i<n1 && j<n2; i++, j++)
    {
        main[k] = sub1[i];        //adding element into the merged array and sorting into descending after adding every element
        for(int l = k; l>0; l--)
        {
            if(main[l]<main[l-1])
                break;
            else
            {
                temp = main[l];
                main[l] = main[l-1];
                main[l-1] = temp;
            }
        }
        k++;
        main[k] = sub2[j];
        for(int l = k; l>0; l--)
        {
            if(main[l]<main[l-1])
                break;
            else
            {
                temp = main[l];
                main[l] = main[l-1];
                main[l-1] = temp;
            }
        }
        k++;
    }
    if(n1>n2)
    {
        for(int i=n2; i<n1; i++)
        {
            main[k] = sub1[i];       
            for(int l = k; l>0; l--)
            {
                if(main[l]<main[l-1])
                    break;
                else
                {
                    temp = main[l];
                    main[l] = main[l-1];
                    main[l-1] = temp;
                }
            }
            k++;
        }
    }
    else if(n2>n1)
    {
        for(int i=n1; i<n2; i++)
        {
            main[k] = sub2[i];       
            for(int l = k; l>0; l--)
            {
                if(main[l]<main[l-1])
                    break;
                else
                {
                    temp = main[l];
                    main[l] = main[l-1];
                    main[l-1] = temp;
                }
            }
            k++;
        }
    }
}
int sum_non_recursive(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {    
        sum = sum + arr[i];
    }
    return sum;
}
int sum_recursive(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return arr[n - 1] + sum_recursive(arr, n - 1);
}
int search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
}
void separate_even_odd(int arr[], int n)
{
    printf("Even: ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\nOdd: ");
    for (int i = 0; i < n; i++)
    {    
        if (arr[i] % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void separate_pos_neg(int arr[], int n)
{
    printf("Positive: ");
    for (int i = 0; i < n; i++)
    {    if (arr[i] >= 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\nNegative: ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
int main()
{
    int n=0,n1=0,n2=0,choice,pos,val,key;
    int MainArray[20], SubArray1[10], SubArray2[10];
    
    printf("hey, this is what i can do when you enter a number:\n");
    printf("0. Display the array\n");
    printf("1. Insert element into array\n");
    printf("2. Delete element from array\n");
    printf("3. Reverse the array using temp array\n");
    printf("4. Reverse the array without using temp array\n");
    printf("5. Copy subarray to MainArray\n");
    printf("6. Merge two sorted arrays into descending order\n");
    printf("7. Find sum of elements of an array\n");
    printf("8. Search element in an array\n");
    printf("9. Separate even & odd elements of an array\n");
    printf("10. Separate positive & negative elements of an array\n");
    TakeInput:
    printf("(enter any number apart from 0 to 10 to exit)\nenter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0: 
            display(MainArray, n);
            break;
        case 1: 
            printf("enter position and value: ");
            scanf("%d%d", &pos, &val);
            if(pos<=n)
            {
                insert(MainArray, &n, pos, val);
            }
            else
            {
                printf("invalid position sorry :(");
            }
            break;
        case 2:
            printf("enter position: ");
            scanf("%d", &pos);
            if(pos<n)
            {
                delete(MainArray, &n, pos);
            }
            else
            {
                printf("invalid position sorry :(");
            }
            break;
        case 3:
            reverse__using_temp(MainArray, n);
            break;
        case 4:
            reverse_inplace(MainArray, n);
            break;
        case 5:
            printf("Copying SubArray1 to MainArray\n");
            printf("enter number of elements in subarray 1 ");
            scanf("%d", &n1);
            printf("enter the elements of sub array 1 please: ");
            for(int i=0; i<n1; i++)
            {
                scanf("%d", &SubArray1[i]);
            }
            copy_subarray(SubArray1, n1, MainArray, &n);
            break;
        case 6:
            printf("enter number of elements in subarray 1 and 2: ");
            scanf("%d%d", &n1, &n2);
            printf("enter the elements of sub array 1 please: ");
            for(int i=0; i<n1; i++)
            {
                scanf("%d", &SubArray1[i]);
            } 
            printf("enter the elements of sub array 1 please: ");
            for(int i=0; i<n2; i++)
            {
                scanf("%d", &SubArray2[i]);
            }    
            int descending[20];
            merge_desc(SubArray1, n1, SubArray2, n2, descending);
            display(descending, n1+n2);
            break;
        case 7:
            printf("Sum without recursion: %d\n", sum_non_recursive(MainArray, n));
            printf("Sum with recursion: %d\n", sum_recursive(MainArray, n));
            break;
        case 8: 
            printf("Enter element to search: ");
            scanf("%d", &key);
            if(search(MainArray, n, key) == 1)
            {
                printf("Element found\n");
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 9:
            separate_even_odd(MainArray, n);
            break;
        case 10:
            separate_pos_neg(MainArray, n);
            break;
        default: exit(1);
    }
    goto TakeInput;
} 