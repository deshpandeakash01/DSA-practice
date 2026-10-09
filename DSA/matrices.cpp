//traingular matrix and diagonal matrix
#include<iostream>
struct matrix
{
    int A[10];
    int n;
};
struct Tmatrix
{
    int *A;
    int n;
};
void set(struct matrix *m, int i, int j, int x)
{
    if(i == j)
    {
        m->A[i-1] = x;       
    }
}
void setT(struct Tmatrix *m, int i, int j, int x)
{
    if(i >= j)
    {
        m->A[i*(i-1)/2 + j-1] = x; 
        //m->A[m->n*(j-1)-((j-1)*(j-2))/2+(i-j)];      
    }
}
int get(struct matrix m, int i, int j)
{
    if(i == j)
    {
        return m.A[i-1];
    }
    else
        return 0;
}
void display(struct matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            if(i == j)
            {
                printf("%d ", m.A[i-1]);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayT(struct Tmatrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            if(i >= j)
            {
                printf("%d ", m.A[i*(i-1)/2 + j-1]);
                //printf("%d ",m.A[m.n*(j-1)-((j-1)*(j-2))/2+(i-j)]);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    /*struct matrix m;
    m.n = 4;
    set(&m,1,1,5);
    set(&m,2,2,6);
    set(&m,3,3,7);
    set(&m,4,4,8);
    display(m);*/
    struct Tmatrix m;
    printf("Enter dimension of triangular matrix:");
    scanf("%d", &m.n);
    m.A = new int[m.n*(m.n+1)/2];
    printf("Enter lower triangular elements:\n");
    //for column major mapping upadate loop before using it for row major
    for(int j=1;j<=m.n;j++)
    {
        for(int i=j;i<=m.n;i++)
        {
            int x;
            scanf("%d", &x);
            setT(&m, i, j, x);
        }
    }
    printf("\nLower Triangular Matrix:\n");
    displayT(m);   
}