#include<iostream>
using namespace std;

class QuadraticProbing
{
    public:    
    int *hash;
    int m;

    QuadraticProbing(int n)
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

    int QP(int key)         //hash function
    {
        int cn=0;
        while(hash[(HF(key)+cn*cn)%m]!=-1 && hash[(HF(key)+cn*cn)%m]!=key && cn!=m)
        {
            cn++;
        }
        if(cn==m)
        {
            return -1;
        }
        return ((key%m)+cn*cn)%m;      
    }

    void createHashTable(int arr[])
    {
        for(int i=0; i<m; i++)
        {
            if(QP(arr[i])!=-1)
            {
                hash[QP(arr[i])] = arr[i];
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

    QuadraticProbing qp = QuadraticProbing(n);
    qp.createHashTable(a);
    qp.displayHashTable();
}