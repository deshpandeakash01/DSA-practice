#include<iostream>
#define size 100
using namespace std;
int top=-1;
char s[size];
char inf[size],pof[size];
void push(char item)
{
    if(top>=size-1)
    {
        cout<<"overflow!";
        return;
    }
    s[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        cout<<"underflow!";
        return -1;
    }
   return s[top--];
}
void display()
{
    for(int i=0;i<=top;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int sp(char item)
{
    switch(item)
    {
        case '+':
        case '-':
            return 2;
        case '/':
        case '*':
            return 4;
        case '^':
        case '$':
            return 5;
        case '(':
        case '#':
            return 0;
        
    }
    return 8;//impossible case because stack only has operaters
}
int ip(char item)
{
    switch(item)
    {
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
            return 3;
        case '^':
        case '$':
            return 6;
        case '(':
            return 9;
        case ')':
            return 0;
    }
    return 7;
}
void inf_to_pof()
{
    int i=0,j=0;
    char token;
    push('#');
    for(i=0;inf[i]!='\0';i++)
    {
        token=inf[i];
        if(isalnum(token))
        {
            pof[j++]=token;
        }
        else if(token=='(') push(token);
        else if(token==')')
        {
            while(s[top]!='(')
            {
                pof[j++]=pop();
            }
            pop();
        }
        else{
            while(sp(s[top])>=ip(token))
            {
                pof[j++]=pop();
            }
            push(token);
        }
    }
    while(s[top]!='#')
    {
        pof[j++]=pop();
    }
    pof[j]='\0';
}
int main()
{
    cout<<"enter infix expression\n";
    cin>>inf;
    inf_to_pof();
    cout<<"postfix expression is : "<<pof;    
}