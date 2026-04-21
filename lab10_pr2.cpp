#include<iostream>
using namespace std;

int main()
{
    //SELECTION SORT

    int n, *a;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    cout<<"the sorted array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}