#include<iostream>
using namespace std;

class DoubleHashing
{
    public:    
    int *hash;
    int m;

    DoubleHashing(int n)
    {
        m = n;
        hash = new int[m];
        for(int i=0; i<m; i++)
        {
            hash[i] = -1;
        }
    }

    int HF1(int key)         //hash function
    {
        return (key%m);      
    }
    int HF2(int key)
    {
        return key%(m-1)+1;     //random hash function
    }

    int DH(int key)         //hash function
    {
        int cn=0;
        while(hash[(HF1(key)+cn*HF2(key))%m]!=-1 && hash[(HF1(key)+cn*HF2(key))%m]!=key && cn!=m)
        {
            cn++;
        }
        if(cn == m)
        {
            return -1;
        }
        return ((key%m)+cn*HF2(key))%m;      
    }

    void createHashTable(int arr[])
    {
        for(int i=0; i<m; i++)
        {
            if(DH(arr[i])!=-1)
            {
                hash[DH(arr[i])] = arr[i];
            }
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

    DoubleHashing dh = DoubleHashing(n);
    dh.createHashTable(a);
    dh.displayHashTable();
}