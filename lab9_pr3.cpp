#include<iostream>
#include<iterator>
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
            hash[i] = 0;
        }
    }

    int HF(int key)         //hash function
    {
        return (key%m);      
    }

    int LP(int key)         //hash function
    {
        int cn=0;
        while(hash[(HF(key)+cn)%m]!=0 && hash[(HF(key)+cn)%m]!=key && cn!=m)
        {
            cn++;
        }
        return ((key%m)+cn)%m;      
    }

    void createHashTable(int arr[])
    {
        int cn;
        for(int i=0; i<m; i++)
        {
            cn=0;
            hash[LP(arr[i])] = arr[i];
        }
    }
};

int* commonElements(int a[], int b[], int n, int m, int *k)
{
    int *c;
    if(m>n)
    {
        c = new int[n];
        LinearProbing h = LinearProbing(m);
        h.createHashTable(b);
        for(int i=0; i<n; i++)
        {
            if(h.hash[h.LP(a[i])] == a[i])
            {
                c[(*k)++] = a[i];
            }
        }
    }
    else
    {
        c = new int[m];
        LinearProbing h = LinearProbing(n);
        h.createHashTable(a);
        for(int i=0; i<m; i++)
        {
            if(h.hash[h.LP(b[i])] == b[i])
            {
                c[(*k)++] = b[i];
            }
        } 
    }
    return c;
}

int main()
{
    int n, m;
    int *a, *b;
    cout<<"enter number of elements in a and b: "<<endl;
    cin>>n>>m;
    a = new int[n];
    b = new int[m];
    cout<<"enter elements of a: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements of b: "<<endl;
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    int k = 0;
    int *c = commonElements(a, b, n, m, &k);
    for(int i=0; i<k; i++)
    {
        cout<<c[i]<<" ";
    }
}