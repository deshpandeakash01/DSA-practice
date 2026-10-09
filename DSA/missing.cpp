 #include<iostream>
 int main()
 {
    int i=0,sum=0,index;
    int A[11]={1,2,3,4,5,6,8,9,10,11,12};
    //Approach 1
    for(;i<11;i++){
        sum+=A[i];
    }
    index=A[10]*(A[10]+1)/2 -sum;
    printf("missing element is = %d\n",index);
    //Approach 2
    int B[10]={6,7,8,9,11,13,15,17,18,21};
    int temp=B[0],j=0;
    printf("missing elements are :");
    for(;j<10;j++)
    {
        if((B[j]-j)!=temp)
        {
            while(temp<B[j]-j){
            printf("%d ",temp+j);
            temp++;}
        }
    }
    printf("\n");
    //Approach 3(Hash-table)
    int C[10]={9,7,10,6,4,11,13,2,14,15};
    int H[16]={0};
    int k;
    printf("missing elements are :");
    for(k=0;k<10;k++)
    {
        H[C[k]]++;
    }
    for(k=1;k<16;k++)
    {
        if(H[k]==0)
        printf("%d ",k);
    }
 }