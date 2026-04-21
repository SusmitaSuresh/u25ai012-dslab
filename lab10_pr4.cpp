#include<iostream>
using namespace std;

void merge(int A[], int ub, int mid, int lb)
{
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int *L = new int[n1];
    int *R = new int[n2];
    
    for(int i=0; i<n1; i++)
    {
        L[i] = A[lb+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = A[mid+1+i];
    }

    int j=0, k=0, i=0;
    while(j<n1 && k<n2)
    {
        if(L[j]<=R[k])
        {
            A[lb+i] = L[j];
            j++;
        }
        else
        {
            A[lb+i] = R[k];
            k++;
        }
        i++;
    }
    while(j<n1)
    {
        A[lb+i] = L[j];
        i++;
        j++;
    }
    while(k<n2)
    {
        A[lb+i] = R[k];
        i++;
        k++;
    }
}

void mergeSort(int A[], int ub, int lb)
{
    int mid = (lb+ub)/2;
    if(lb<ub)
    {
        mergeSort(A, mid, lb);
        mergeSort(A, ub, mid+1);
        merge(A, ub, mid, lb);
    }
}

int main()
{
    //MERGE SORT

    int n, *a;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    mergeSort(a, n-1, 0);

    cout<<"the sorted array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}