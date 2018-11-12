#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m,j;
    for(int i=1;i<n-1;i++)
    {
        m=a[i];
        j=i-1;
        while(j>=0&&a[j]>m)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=m;
    }
    cout<<"Sorted Array is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
