#include<stdio.h>
int main()
{
    int n,m,i,j;    
    printf("enter no. of rows: ");
    scanf("%d", &n);
    printf("enter no. of columns: ");
    scanf("%d", &m);
    int a[n][m];
    printf("enter elements in row major order:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("elements are: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}