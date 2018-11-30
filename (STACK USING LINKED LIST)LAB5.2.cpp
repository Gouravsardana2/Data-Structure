#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
}*top;
node * createnode(int v)
{
    struct node* p=new node();
    p->next=NULL;
    p->data=v;
    return p;
}
void push(int v)
{
    node* p;
    p=createnode(v);
    if(top==NULL)
    {
        top=p;
    }
    else
    {
        p->next=top;
        top=p;
    }
}
void pop()
{
    node* temp=top;
    if(top==NULL)
    {
        cout<<"Empty Stack"<<endl;
    }
    else
    {
        top=temp->next;
        delete temp;
    }
}
void display()
{
    node* temp=top;
    if(top==NULL)
    {
        cout<<"Empty Stack"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data;
            cout<<endl;
            temp=temp->next;
        }
    }
}
int main()
{
    top=NULL;
    cout<<"Enter 1 to push, 2 to pop, 3 to peek & 0 to exit the menu"<<endl;
    int c;
    cin>>c;
    while(c!=0)
    {
        switch(c)
        {
            case 1:
            int v;
            cout<<"Enter the value"<<endl;
            cin>>v;
            push(v);
            break;
            case 2:
            pop();
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
