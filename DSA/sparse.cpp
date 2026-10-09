#include<iostream>
struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};
void create(struct sparse *s)
{
    printf("enter dimensions of sparse matrix\n");
    scanf("%d %d",&s->m,&s->n);
    printf("enter number of non zero elements\n");
    scanf("%d",&s->num);
    s->e=new element[s->num];
    printf("enter all non zero elements\n");
    for(int i=0;i<s->num;i++) 
    {
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}
void display(struct sparse s)
{
    int i,j,k=0;
    printf("sparse matrix is:\n");
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i&&j==s.e[k].j)
            {
                printf("%d ",s.e[k++].x);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct sparse *sum(struct sparse *s,struct sparse *s1)
{
    int i,j,k;
    i=j=k=0;
    sparse *sum;
    if(s->n!=s1->n||s->m!=s1->m)
        return 0;
    sum=new sparse;
    sum->n=s->n;sum->m=s->m;
    sum->e=new element[s->num+s1->num];
    while(i<s->num&&j<s1->num)
    {
        if(s->e[i].i<s1->e[j].i) sum->e[k++]=s->e[i++];
        else if(s->e[i].i>s1->e[j].i) sum->e[k++]=s1->e[j++];
        else
        {
            if(s->e[i].j<s1->e[j].j) sum->e[k++]=s->e[i++];
            else if(s->e[i].j>s1->e[j].j) sum->e[k++]=s1->e[j++];
            else
            {
                sum->e[k]=s->e[i];
                sum->e[k++].x=s->e[i++].x+s1->e[j++].x;
            }
        }
    }
    for(;i<s->num;i++) sum->e[k++]=s->e[i++];
    for(;j<s1->num;j++) sum->e[k++]=s1->e[j++];
    sum->n=s->n;sum->m=s->m;sum->num=k;
    return sum;
}
int main()
{
    struct sparse s;
    struct sparse s1;
    struct sparse *s2;
    create(&s);
    create(&s1);
    display(s);
    display(s1);
    s2=sum(&s,&s1);
    display(*s2);
}