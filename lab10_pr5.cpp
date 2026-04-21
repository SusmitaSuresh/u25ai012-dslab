#include<iostream>
using namespace std;

int partition(int a[], int lb, int ub)
{
    int pivot = lb;
    int i = lb+1;
    int j = ub;
    while(i<j)
    {
        if(a[i]>=a[pivot] && a[j]<a[pivot])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;            
        }
        if(a[i]<a[pivot])
        {
            i++;
        }
        if(a[j]>a[pivot])
        {
            j--;
        }
    }
    int temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp; 
    return j;
}

void quickSort(int a[], int lb, int ub)
{
    int q = partition(a, lb, ub);
    quickSort(a, lb, q-1);
    quickSort(a, q+1, ub);
}

int main()
{
    //QUICK SORT

    int n, *a;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    quickSort(a, 0, n-1);

    cout<<"the sorted array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}