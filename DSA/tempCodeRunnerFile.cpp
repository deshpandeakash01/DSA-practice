void reverse_LL(struct node *p)
{
    struct node *temp;
    while(p!=NULL)
    {
        /*r=q;
        q=p;
        p=p->next;
        q->prev=p;
        q->next=r; ---------MY LOGIC IS CORRECT BUT NOT ROBUST----------*/
        temp=p->next;
        p->next=p->prev;
        p->next=temp;
        p=p->prev;
        if(p->next=NULL) first=head;
    }