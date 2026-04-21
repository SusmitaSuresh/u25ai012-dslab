#include<iostream>
#include<string>
using namespace std;

class MidSquare
{
    public:    
    int *hash;
    int m;
    float a;

    MidSquare(int n)
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
        int q = key*key;
        string s = to_string(q);
        int mid = s.length()/2;
        if(s.length() > 1)
        {
            s = s.substr(mid - 1, 2);
        }
        q = stoi(s);
        return q%m;
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
    
    MidSquare ms = MidSquare(n);
    ms.createHashTable(a);
    ms.displayHashTable();
}