#include<stdio.h>
int main()
{
    int n,i,sum,max,min,key;
    float avg=0;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    max=a[0];
    min=a[0];
    printf("enter the element to search: ");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
        else if(a[i]<min)
            min=a[i];
        avg= avg+ a[i];
        if(a[i]==key)
        {
            printf("key is found at %d index\n", i);
        }
    }
    avg=avg/n;
    printf("max and min are: %d and %d", max, min);
    printf("avg is %f", avg);
}