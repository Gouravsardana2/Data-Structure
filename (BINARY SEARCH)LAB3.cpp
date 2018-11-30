#include<iostream>
using namespace std;
void binary(int arr[],int first,int last,int x)
{
    int mid=(first+last)/2;
    if(arr[mid]>x)
        binary(arr,first,mid-1,x);
    else if(arr[mid]<x)
        binary(arr,mid+1,last,x);
    else if(arr[mid]==x)
    {
        cout<<"Element found at position "<<mid<<" of array."<<endl;
        return ;
    }
    else if(first==last)
    {
        cout<<"The number is not found in the array."<<endl;
        return ;
    }
}
bubble(int arr[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
    {
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
    }
}

int main()
{
    int n,x,i=0;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element to search:"<<endl;
    cin>>x;
    bubble(arr,n);
    int first=0;
    int last=n-1;
    binary(arr,first,last,x);
    return 0;
}
