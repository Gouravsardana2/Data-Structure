#include<iostream>
using namespace std;
int inserting(int arr[],int l)
{
    int x,n,i=0,t;
    cout<<"Enter element to insert:"<<endl;
    cin>>x;
    if(l==0)
        arr[0]=x;
        cout<<"Enter position of element:"<<endl;
        cout<<"Enter 1 for insertion at the beginning:"<<endl;
        cout<<"Enter 2 for insertion at the end:"<<endl;
        cout<<"Enter 3 for insertion at a position:"<<endl;
        cin>>t;
        switch(t)
        {
            case 1:
        for(int i=l-1;i>=0;i--)
            arr[i+1]=arr[i];
        arr[0]=x;
        l++;
        break;
    case 2:
        arr[l]=x;
        l++;
        break;
    case 3:
        cout<<"Enter position of element in array:"<<endl;
        cin>>n;
        for(int i=l-1;i>=n;i--)
            arr[i+1]=arr[i];
        arr[n]=x;
        l++;
        break;
        }
    return l;
}
int deleting(int arr[],int l)
{
    int x,position;
    int choice;
    cout<<"Enter 1 to delete a given element"<<endl;
    cout<<"Enter 2 to delete a element at a given location"<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter value:"<<endl;
        cin>>x;
        for(int i=0;i<l;i++)
            if(arr[i]==x)
                position=i;
        for(int i=position;i<l;i++)
                arr[i]=arr[i+1];
        l--;
    }
    else if(choice==2)
    {
        cout<<"Enter position of element:"<<endl;
        cin>>position;
        for(int i=position;i<l;i++)
                arr[i]=arr[i+1];
        l--;
    }
    return l;
}
void finding(int arr[],int l)
{
    int x,i=0;
    cout<<"Enter element to search:n"<<endl;
    cin>>x;
    for(i=0;i<l;i++)
        if(arr[i]==x)
        cout<<"Element is found at position "<<i<<endl;
}
void display(int arr[],int l)
{
    cout<<"The array is:";
    for(int i=0;i<l;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}
int main()
{
    int arr[100]={1,2,3,4,5};
    int choice;
    cout<<"Enter 1 to insert an element:"<<endl;
    cout<<"Enter 2 to delete an element:"<<endl;
    cout<<"Enter 3 to find location of element:"<<endl;
    cout<<"Enter 4 to print array:"<<endl;
    cout<<"Enter -1 to exit:"<<endl;
    cin>>choice;
    int l=5;
    while(choice!=-1)
    {
        switch(choice)
    {
        case 1:l=inserting(arr,l);
                break;
        case 2:l=deleting(arr,l);
                break;
        case 3:finding(arr,l);
                break;
        case 4:display(arr,l);
                break;
    }
    cout<<"Enter your choice to select function:"<<endl;
     cin>>choice;
    }
    return 0;
}
