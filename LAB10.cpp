#include<iostream>
using namespace std;
struct node
{
    int data;
    node* l,*r;
}*root;
node* createnode(int v)
{
    node* temp=new node;
    temp->data=v;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
node *search(node* root,int v)
{
    if(root==NULL||root->data==v)
        return root;
    else if(v>root->data)
        return search(root->r,v);
    else return search(root->l,v);
}
node* insert1(node* root,int v)
{
    if(root==NULL)
    {
        node* p=createnode(v);
        return p;
    }
    else if(v>root->data)
        root->r=insert1(root->r,v);
    else root->l=insert1(root->l,v);
    return root;
}
node * inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}
int main()
{
    root=NULL;
    int n;
    int c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        root=insert1(root,c);
    }
    node* t=search(root,88);
    if(t)
    {
        cout<<"Found "<<t->data<<endl;
    }
    else
        cout<<"NOT Found"<<endl;
    inorder(root);
}
