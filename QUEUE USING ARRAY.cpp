#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class queue1
{
    int f,r,*a,n;
public:
    queue1(int n1)
    {
        n=n1;
        f=r=-1;
    }
    void enqueue(int v)
    {
        if(r==n-1)
            {
                cout<<"OverFlow"<<endl;
                //r=-1;
            }
        else if(f==-1&&r==-1)
        {
            f=r=0;
            a[r]=v;
        }
        else
        {
            a[++r]=v;
        }
    }
    void dequeue()
    {
       // if(f==-1&&r==-1)
       if(f==-1||f>r)
        {
            cout<<"UnderFlow"<<endl;
        }
        else if(f==r)
        {
            f=r=-1;
        }
        else f++;
    }
    int emp()
    {
        if(f==-1&&r==-1)
            return 1;
        else return 0;
    }
    void rev()
    {
        stack<int> s;
        while(!emp())
        {
            s.push(a[f]);
            dequeue();
        }

        while(!s.empty())
        {
            enqueue(s.top());
            s.pop();
        }
    }
    void display()
    {
        cout<<a[f]<<endl;
    }
    void fulldisplay()
    {
        while(f<=r)
        {
            cout<<a[f]<<" ";
            f++;
        }
    }
};
int main()
{
    queue1 q(5);
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
            q.enqueue(v);
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.fulldisplay();
            break;
        }
        cout<<"Enter your choice"<<endl;
        cin>>c;
    }
    return 0;
}
