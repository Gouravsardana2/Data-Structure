#include <iostream>
using namespace std;
struct node
{
    int v;
    struct node *n;
    struct node *p;
}*start=NULL;
struct node *create_node(int val)
{
    struct node *temp;
    temp=new(struct node);
    temp->v=val;
    temp->n=NULL;
    temp->p=NULL;
    return temp;
}

void insert_beg()
{
    cout<<"Enter the value to insert at the beginning"<<endl;
    int val;
    cin>>val;
    struct node *b=create_node(val);
    if(start==NULL)
    {
        start=b;
        b->p=NULL;
        b->n=NULL;
    }
    else
    {
        b->n=start;
        start->p=b;
        start=b;
        b->p=NULL;
    }
}

void insert_end()
{
    cout<<"Enter the value to insert at the end"<<endl;
    int val;
    cin>>val;
    struct node *b=create_node(val);
    struct node *t=start;
    if(start==NULL)
    {
        start=b;
        b->n=NULL;
        b->p=NULL;
    }
    else
    {
        while(t->n!=NULL)
        {
            t=t->n;
        }
        t->n=b;
        b->p=t;
        b->n=NULL;
    }
}

void del_given()
{
    int val;
    cin>>val;

    struct node *b,*t=start;
    int c=1;
    if(start==NULL)
    {
        cout<<"No List";
    }
    else
    {
        while(t->v!=val && t->n!=NULL)
        {
            t=t->n;
            c++;
        }
        if(t->v==val && c==1 && t->n==NULL)
        {
            b=start;
            start=NULL;
            b->p=NULL;
            b->n=NULL;
            b->v=NULL;
        }
        else if(t->v==val && c==1 && t->n!=NULL)
        {
            b=start;
            start=b->n;
            start->p=NULL;
            b->n=NULL;
            b->p=NULL;
            b->v=NULL;
        }
        else if(t->v==val && c!=1 && t->n==NULL)
        {
            b=t;
            t->p->n=NULL;
            b->p=NULL;
            b->n=NULL;
            b->v=NULL;
        }
        else if(t->v==val && c!=1 && t->n!=NULL)
        {
            b=t;
            t->p->n=t->n;
            t->n->p=t->p;
            b->p=NULL;
            b->n=NULL;
            b->v=NULL;
        }
        else
        {
            cout<<"NO NODE WITH SUCH VALUE";
        }
    }
}

void search_node()
{
cout<<"Enter the element to search"<<endl;
int val,c=0;
cin>>val;
struct node *t=start;

while(t!=NULL)
{
if(t->v==val)
{
c++;
cout<<"Element exists"<<endl;
break;
}
t=t->n;
}

if(c==0)
cout<<"Element does not exist"<<endl;

}

void display()
{
    struct node *s=start;
    while(s->n!=NULL)
    {
        cout<<s->v<<" ";
        s=s->n;
    }
    cout<<s->v<<endl;
}

int main()
{
    cout<<"Enter 'a' to insert, 'b' to delete, 'c' to search, 'd' to display all the elements & 'x' to exit the menu"<<endl;
    char ch;
    cin>>ch;
    while(ch!='x')
    {
        switch(ch)
        {
            case 'a':
            insert_beg();
            insert_end();
            break;
            case 'b':
            del_given();
            break;
            case 'c':
            search_node();
            break;
            case 'd':
            display();
            break;
        }
        cout<<"Enter your choice"<<endl;
        cin>>ch;
    }
    return 0;
}
