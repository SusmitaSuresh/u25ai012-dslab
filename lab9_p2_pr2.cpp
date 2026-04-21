#include<iostream>
#include <cmath>
using namespace std;

class HashTable
{
    public:    
    int *hash;
    int m;
    float a;

    HashTable(int n, int f)
    {
        a = f;
        m = n;
        hash = new int[m];
        for(int i=0; i<m; i++)
        {
            hash[i] = -1;
        }
    }

    int HF(int key)         //hash function
    {
        return floor((m*(((int)(key*a))%m)));      
    }

    void createHashTable(int arr[])
    {
        for(int i=0; i<m; i++)
        {
            hash[HF(arr[i])] = arr[i];
        }
    }

    void displayHashTable()
    {
        for(int i=0; i<m; i++)
        {
            cout<<hash[i]<<" ";
        }
    }
};

int main()
{
    int n;
    int *a;
    float f;
    cout<<"enter number of elements in a: "<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter elements of a: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"enter a random value bw 0 and 1"<<endl;
    cin>>f;
    
    HashTable h = HashTable(n,f);
    h.createHashTable(a);
    h.displayHashTable();
}