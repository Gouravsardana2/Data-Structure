#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}

int partition(int a[], int l, int h)
{
int pi=a[h];
int i=l-1;
for(int j=l;j<h;j++)
{
if(a[j]<=pi)
{
i++;
if(i!=j)
swap(&a[i],&a[j]);
}
}
swap(&a[i+1],&a[h]);
return i+1;
}

void quicksort(int a[], int l, int h)
{
if(l<h)
{
int p=partition(a,l,h);
quicksort(a,l,p-1);
quicksort(a,p+1,h);
}
}

int main()
{
cout<<"Enter the number of elements"<<endl;
int n;
cin>>n;
int a[n];
cout<<"Enter the elements"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];

quicksort(a,0,n-1);

cout<<"Sorted array is"<<endl;

for(int i=0;i<n;i++)
cout<<a[i]<<" ";
return 0;
}
