#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5};
    int s=sizeof(a)/sizeof(a[0]);
    int n;
    cout<<"Enter 1 to insert a new element at a specified position "<<endl;
    cout<<"Enter 2 to delete an element either whose value is given or whose position is given "<<endl;
    cout<<"Enter 3 to find the location of a given element "<<endl;
    cout<<"Enter 4 to display the elements of the linear array"<<endl;

    while(true)
    {
    cout<<"Enter Choice"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        {
            cout<<"Enter element and position"<<endl;
            int n1,n2;
            cin>>n1>>n2;
            for(int i=s-1;i>=n2;i--)
            {
                a[i+1]=a[i];
            }
            a[n2]=n1;
            s++;
            break;
        }
    case 2:
        {
            int i,v;
            cout<<"Enter the number you want to delete: "<<endl;
            cin>>v;
            for(i=0;i<5;i++)
            {
                if(a[i]==v)
                    break;
            }
            for(int j=i;j<5;j++)
            {
                a[j]=a[j+1];
            }
            s--;
            break;
        }

    case 3:
        {
            int i,v;
            cout<<"Enter the number you want to locate: "<<endl;
            cin>>v;
            for(i=0;i<5;i++)
            {
                if(a[i]==v)
                    break;
            }
            cout<<"Element found at "<<i<<" Index"<<endl;
            break;
        }
    case 4:
        {
            for(int i=0;i<s;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        break;
    default:
        exit(0);
    }
    }
}
