#include<iostream>
#include<cstring>
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
    int peek()
    {
        //cout<<arr[top]<<endl;
        return arr[top];
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
int prec(char c)
{
    if(c=='^')
        return 7;
    if(c=='*'||c=='%'||c=='/')
        return 5;
    else if(c=='+'||c=='-')
        return 2;
    return 0;
}
void infixtopostfix(char a[],int len)
{
    char tok;
    char pf[100];
    int n=0;
    stackk s(100);
    s.push('(');
    for(int i=0;i<len;i++)
    {
        tok=a[i];
        if(tok=='(')
        {
            s.push(tok);
        }
        else if(tok==')')
        {
            while(s.peek()!='(')
            {
                pf[n++]=s.pop();
            }
            s.pop();
        }
        else if(tok=='+'||tok=='-'||tok=='*'||tok=='/'||tok=='%')
        {
            while(prec(s.peek())>=prec(tok))
            {
                pf[n++]=s.pop();
            }
            s.push(tok);
        }
        else pf[n++]=tok;
    }
        pf[n]='\0';
        cout<<"The postfix expression is "<<pf;

}
int main()
{
    char a[100];
    cout<<"Enter the infix Expression"<<endl;
    cin>>a;
    int len=strlen(a);
    a[len]=')';
    len++;
    a[len]='\0';
    infixtopostfix(a,len);
}

