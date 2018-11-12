#include<iostream>
using namespace std;
class stackk
{
    int top;
    int *arr;
    int n;
public:
    stackk(int x)
    {
        n=x;
        top=-1;
        arr=new int(n);
    }
    void push(int v)
    {
        if(top==n-1)
            cout<<"Overflow"<<endl;
        else
        {
            arr[++top]=v;
        }
    }
   int pop()
    {
        if(top==-1)
            cout<<"Underflow"<<endl;
        else
        {
            return arr[top--];
        }
    }
    void peek()
    {
        cout<<arr[top]<<endl;
    }
    void displayAll()
    {
        while(top!=-1)
        {
            peek();
            pop();
        }
    }
};
int main()
{
    stackk s(10);
    cout<<"Enter 'a' to push, 'b' to pop, 'c' to peek & 'x' to exit the menu"<<endl;
    char ch;
    cin>>ch;
    while(ch!='x')
    {
        switch(ch)
        {
            case 'a':
            int v;
            cout<<"Enter the value";
            cin>>v;
            s.push(v);
            break;
            case 'b':
            s.pop();
            break;
            case 'c':
            s.peek();
            break;
        }
        cout<<"Enter your choice"<<endl;
        cin>>ch;
    }
}
