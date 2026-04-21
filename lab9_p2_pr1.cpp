#include<iostream>
using namespace std;

class HashTable
{
    public:    
    int *hash;
    int m;

    HashTable(int n)
    {
        m = n;
        hash = new int[m];
        for(int i=0; i<m; i++)
        {
            hash[i] = -1;
        }
    }

    int HF(int key)         //hash function
    {
        return (key%m);      
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
    cout<<"enter number of elements in a: "<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter elements of a: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    HashTable h = HashTable(n);
    h.createHashTable(a);
    h.displayHashTable();

}