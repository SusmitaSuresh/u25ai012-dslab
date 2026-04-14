#include<stdio.h>
int main()
{
    int a[3][3]= {10,20,301,40,554,60,1370,804,90};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d-%u\t", a[i][j], &a[i][j]);
        }
        printf("\n");
    }
    int m= &a[0][1] - &a[0][0];
    printf("if m (which is &a[0][1] - &a[0][0]) is 1,"); 
    printf("then in memory, matrix is stored in memory through row major order");
    printf("\nm=%d", m);
}