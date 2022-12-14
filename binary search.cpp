#include <iostream>
using namespace std;
template<class Type>
void getinput(Type x[],int m)
{
 cout<<"Enter the elements in array\n";
 for(int i=0;i<m;i++)
 cin>>x[i];
}
template<class Type>
void sort(Type a[],int x)
{
 int i,j;
 Type temp=0;
 for(i=0;i<x;i++)
 {
 for(j=i+1;j<x;j++)
 {
 if(a[i]>a[j])
 {
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 }
 }
 }
 cout<<"Array after sorting is\n";
 for(i=0;i<x;i++)
 {
 cout<<a[i]<<" ";
 }
 cout<<endl;
}
template<class Type>
int binarysearch(Type x[],int m)
{
 Type p;
 int low=0;
 int high=m-1;
 int mid=0;
 cout<<"enter the number you want to search\n";
 cin>>p;
 while(low<=high)
 {
 mid=(low+high)/2;
 if(x[mid]==p)
 {
 return(mid+1);
 }
 else if(x[mid]>p)
 {
 high=mid-1;
 }
 else
 {
 low=mid+1;
 }
 }
 if(low>high)
 {
 return -1;
 }
}
 int main()
{
 int n,choice,x;
 char ch='y';
 double a[20];
 while(ch=='y')
 {
 cout<<"Main Module....\n";
 cout<<"1.Input\n";
 cout<<"2.Binary Search\n";
 cout<<"Enter the choice\n";
 cin>>choice;
 switch(choice)
 {
 case 1:cout<<"Enter the number of elements in array \n";
 cin>>n;
 getinput(a,n);
 break;
 case 2:sort(a,n);
 x=binarysearch(a,n);
 if(x!=-1)
 cout<<"Element found at "<<x<<" position.\n";
 else
 cout<<"Element not found\n";
 break;
 default:cout<<"Error in input\n";
 break;
 }
 cout<<"Do you want to continue\n";
 cin>>ch;
 }
 return 0;
}

