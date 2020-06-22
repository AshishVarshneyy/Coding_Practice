#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}Nodetype;

Nodetype *Insert(int element,Nodetype *head)
{
    Nodetype *tmp=NULL;
    tmp=(Nodetype*)malloc(sizeof(Nodetype));
    if(tmp==NULL)
    {
        cout<<"Memory error\n";
    }
    else
    {
        tmp->data=element;
        tmp->next=NULL;

        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            Nodetype *p=NULL;
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=tmp;
        }
    }
    return (head);
}

Nodetype *deleteNodeByElement(int del, Nodetype * head)
{
    Nodetype *tmp=head;
    if(tmp->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while((tmp->next)->data!=del)
        {
            tmp=tmp->next;
        }
        if((tmp->next)->next==NULL)
            tmp->next=NULL;
        else
            tmp->next=(tmp->next)->next;
    }
    return(head);
}

void displayLinkList(Nodetype *head)
{
    Nodetype *tmp=NULL;
    tmp=head;
    if(tmp==NULL)
    {
        cout<<"list is empty\n";
    }
    else
    {
        while(tmp!=NULL)
        {
            cout<<tmp->data;
            if(tmp->next!=NULL)
                cout<<"->";
            tmp=tmp->next;
        }
        cout<<"\n";
    }
}

int countNode(Nodetype *head)
{
    Nodetype *tmp=NULL;
    tmp=head;
    int ncount=0;
    while(tmp!=NULL)
    {
        ncount++;
        tmp=tmp->next;
    }
    return(ncount);
}

Nodetype *deleteByPos(Nodetype *head,int pos)
{
    Nodetype *tmp=NULL;
    tmp=head;
    int pcount=1;
    while(pcount+1!=pos)
    {
        tmp=tmp->next;
        pcount++;
    }
    tmp->next=(tmp->next)->next;
    return (head);
}

Nodetype *insertByPos(Nodetype *head,int pos,int ele)
{
    Nodetype *tmp=NULL,*p=NULL;
    tmp=(Nodetype*)malloc(sizeof(Nodetype));

    tmp->data=ele;
    tmp->next=NULL;

    p=head;

    int ncount=1;
    while(ncount+1!=pos)
    {
        p=p->next;
        ncount++;
    }
    tmp->next=(p->next);
    p->next=tmp;
    return (head);
}

void dispEvenNodes(Nodetype *head)
{
    Nodetype *tmp=NULL;
    tmp=head;
    while(tmp!=NULL)
    {
        if((tmp->data)%2==0)
        {
            if(((tmp->next)->next)==NULL)
                cout<<(tmp->data);
            else
                cout<<(tmp->data)<<"->";
        }
        tmp=tmp->next;
    }
    cout<<"\n";
}

void dispOddNodes(Nodetype *head)
{
    Nodetype *tmp=NULL;
    tmp=head;
    while(tmp!=NULL)
    {
        if((tmp->data)%2!=0)
        {
            if((tmp->next)==NULL)
                cout<<(tmp->data);
            else
                cout<<(tmp->data)<<"->";
        }
        tmp=tmp->next;
    }
    cout<<"\n";
}

Nodetype *reverseLL(Nodetype *head)
{
    Node *cur_node = head;
    Node *prev_node = NULL, *next_node = NULL;

    if(cur_node==NULL)
        cout<<"Empty list\n";
    else
    {
        while (cur_node != NULL)
        {
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }
        head = prev_node;
    }
    return(head);
}

void rReverse(Nodetype **phead)
{
    Nodetype *first=NULL,*rest=NULL;
    first=*phead;
    rest=first->next;
    if(*phead==NULL)
        return;
    if(rest==NULL)
        return;

    rReverse(&rest);
    (first->next)->next=first;
    first->next=NULL;
    *phead=rest;

}

Nodetype *reverseSecHalf(Nodetype *head)
{
    int count=countNode(head);
    if(count%2!=0)
        count=(count/2);
    else
        count=count/2;
    count++;
    int cur_count=1;
    Nodetype *tmp=head,*tmpp=head;
    while(cur_count!=count)
    {
        cur_count++;
        tmp=tmp->next;
    }
    cur_count=1;
    while(cur_count+1!=count)
    {
        cur_count++;
        tmpp=tmpp->next;
    }
    tmp=reverseLL(tmp);
    tmpp->next=tmp;
    return(head);
}

bool detectLoop(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}

int main()
{
    Nodetype *head = NULL,*phead=NULL;
    int ch=0;
    while(true)
    {
        cout<<"Menu\n1. Insert Node\n2. Delete Node By Element\n3. Display LinkList\n4. Count Number of Nodes\n";
        cout<<"5. Delete Node By Position\n6. Insert node at a position\n7. Display Even Data\n8. Display Odd Data\n";
        cout<<"9. Reverse Link List\n10. Reverse LinkList Recursively\n11. Reverse Second half\n";
        cout<<"12. Detect Loop\n13. Remove Loop\n14. Check Pallindrome\n15. Exit\n";
        cout<<"Choose your operation: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    int ele;
                    cout<<"Enter your element you want to insert: ";
                    cin>>ele;
                    head= Insert(ele,head);
                    break;
                }
            case 2:
                {
                    int del;
                    cout<<"Enter an element you want to delete or position: ";
                    cin>>del;
                    head= deleteNodeByElement(del,head);
                    break;
                }
            case 3:
                {
                    displayLinkList(head);
                    break;
                }
            case 4:
                {
                    int count=countNode(head);
                    cout<<count<<"\n";
                    break;
                }
            case 5:
                {
                    int pos;
                    cout<<"Enter element position of an element you want to delete: ";
                    cin>>pos;
                    head=deleteByPos(head,pos);
                    break;
                }
            case 6:
                {
                    int pos,element;
                    cout<<"Enter element you want to insert: ";
                    cin>>element;
                    cout<<"Enter a position where you want to insert a element: ";
                    cin>>pos;
                    head=insertByPos(head,pos,element);
                    break;
                }
            case 7:
                {
                    dispEvenNodes(head);
                    break;
                }
            case 8:
                {
                    dispOddNodes(head);
                    break;
                }
            case 9:
                {
                    head=reverseLL(head);
                    break;
                }
            case 10:
                {
                    rReverse(&head);
                    break;
                }
            case 11:
                {
                    reverseSecHalf(head);
                    break;
                }
            case 12:
                {
                    bool flag=false;
                    flag=detectLoop(head);
                    if(flag==true)
                        cout<<"Loop Detected"<<"\n";
                    else
                        cout<<"Loop Not Detected"<<"\n";
                    break;
                }
            case 13:
                {
                    break;
                }
            case 14:
                {
                    break;
                }
            case 15:
                exit(0);
            default:
                cout<<"Invalid Option...\n";

        }
    }
    return 0;
}
