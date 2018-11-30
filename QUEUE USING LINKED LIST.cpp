#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
}*f,*r;
node* createnode(int v)
{
    node* temp=new node();
    temp->data=v;
    temp->next=NULL;
    return temp;
}
void enqueue(int v)
{
    node* p=createnode(v);
    if(f==NULL&&r==NULL)
    {
        f=p;
        r=p;
    }
    else
    {
        r->next=p;
        r=p;
        p->next=NULL;
    }
}
void dequeue()
{
    node* p=f;
    if(f==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }
    else
    {
        f=p->next;
        delete p;
    }
}
void display()
{
    node* t=f;
    while(t!=NULL)
    {
        cout<<t->data<<endl;
        t=t->next;
    }
}
int main()
{
    f=NULL;
    r=NULL;
    cout<<"Enter 1 for insertion, 2 for deletion, 3 to display & 0 to exit the menu"<<endl;
    int c;
    cin>>c;
    while(c!=0)
    {
        switch(c)
        {
            case 1:
            cout<<"Enter the value"<<endl;
            int v;
            cin>>v;
            enqueue(v);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
        }
        cout<<"Enter your choice"<<endl;
        cin>>c;
    }
    return 0;
}
