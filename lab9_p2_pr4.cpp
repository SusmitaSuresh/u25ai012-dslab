#include<iostream>
using namespace std;

class LinearProbing
{
    public:    
    int *hash;
    int m;

    LinearProbing(int n)
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

    int LP(int key)         //hash function
    {
        int cn=0;
        while(hash[(HF(key)+cn)%m]!=-1 && hash[(HF(key)+cn)%m]!=key && cn!=m)
        {
            cn++;
        }
        if(cn == m)
        {
            return -1;
        }
        return ((key%m)+cn)%m;      
    }

    void createHashTable(int arr[])
    {
        for(int i=0; i<m; i++)
        {
            if(LP(arr[i])!=-1)
            {
                hash[LP(arr[i])] = arr[i];   
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

    LinearProbing lp = LinearProbing(n);
    lp.createHashTable(a);
    lp.displayHashTable();
}