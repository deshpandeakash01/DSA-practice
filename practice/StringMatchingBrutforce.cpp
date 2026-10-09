#include<iostream>
#include <cstring>
int match(char t[],char p[],int n,int m)
{
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while(j<m&&p[j]==t[i+j]) j++;
        if(j==m) return i;
    }
    return -1;
}
int main()
{
    char t[501];
    memset(t, 'A', 500);
    t[492] = 'B';
    t[500] = '\0'; // Null-terminator
    // 2. Prepare the p: 15 chars
    char p[] = "AAAAAAAAAAAAAAB";
    int n = 500;
    int m = 15;
    int result = match(t, p, n, m);
    if(result != -1) {
        printf("P found at index: %d\n", result);
    } else {
        printf("P not found.\n");
    }
}