#include<iostream>
int strlen(char A[])
{
    int i=0;
    while(A[i]!='\0')
    i++;
    return i;
}
void change_case(char A[])
{
    int i=0;
    while(A[i]!='\0')
    {
        if(A[i]>=65&&A[i]<=90)
        {
            A[i]=A[i]+32;
        }
        else if(A[i]>=97&&A[i]<=122)
        {
            A[i]=A[i]-32;      
        }
        i++;
    }
}
void merge(char A[],char B[])
{
    int i=0,j=0;
    while(A[i]!='\0') i++;
    while(B[j]!='\0')
    {
        A[i]=B[j];
        i++;
        j++;
    }
    A[i]='\0';
}
void Reverse(char A[])
{
    int i=0,j=0;
    while(A[i]!='\0')
    {
       // INCREASING I VALUE
       i++;
    }
    i--;
    while(j<=i)
    {
        int temp=A[j];
        A[j]=A[i];
        A[i]=temp;
        j++;i--;
    }
} 
bool palindrome(char A[])
{

    int len=strlen(A)-1,i=0;
    while(i<=len/2)
    {
        if(A[i]==A[len-i])
            i++;
        else
            return false;    
    }
    return true;
}
int main()
{
    char A[100],B[100];
    gets(A);
    gets(B);
    printf("length of string A:%d and B:%d\n",strlen(A),strlen(B));
    change_case(A);
    change_case(B);
    printf("case changed string is %s\n",A);
    merge(A,B);
    printf("merged string is: %s\n",A);
    Reverse(A);
    printf("revesed string is:%s\n",A);
    printf("STRING IS PALINDROM? %d",palindrome(A));
}