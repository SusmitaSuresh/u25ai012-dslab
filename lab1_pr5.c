#include<stdio.h>
int main()
{
    int n,m,i,j,*p;    
    printf("enter no. of rows: ");
    scanf("%d", &n);
    printf("enter no. of columns: ");
    scanf("%d", &m);
    int a[n][m];
    int b[m][n];
    printf("enter elements in row major order:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("elements with their adresses are: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d-%u\t", a[i][j], &a[i][j]);
        }
        printf("\n");
    }
    printf("calculated adresses of elements are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            p=(&a[0][0]+ (i)*m+j);
            printf("%u\t", p);
        }
        printf("\n");
    }
    printf("enter elements in column major order:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("elements with their adresses are: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d-%u\t", b[j][i], &b[j][i]);
        }
        printf("\n");
    }
    printf("calculated adresses of elements are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            p=(&b[0][0]+ (j)*n+i);
            printf("%u\t", p);
        }
        printf("\n");
    }  
}