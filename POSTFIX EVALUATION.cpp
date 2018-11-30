#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout<<"Enter the postfix expression"<<endl;
    char s[100];
    int x,y,z;
    cin.get(s,100);
    int l=strlen(s);
    int a[100];
    int t=-1;
    for(int i=0;i<l;i++)
    {
        if(isdigit(s[i]))
        {
            t++;
            a[t]=s[i]-'0';
        }
        else
        {
            x=a[t];
            t--;
            y=a[t];
            t--;
            if(s[i]=='*')
                z=(y)*(x);
            else if(s[i]=='+')
                z=(y)+(x);
            else if(s[i]=='-')
                z=(y)-(x);\
            else if(s[i]=='/')
                z=(y)/(x);
            t++;
            a[t]=z;
        }
    }
    cout<<"Answer is= "<<a[t]<<endl;
    return 0;
}
