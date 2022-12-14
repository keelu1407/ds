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
int linearsearch(Type a[],int n)
{
 Type x;
 int i;
 cout<<"enter the element you want to search";
 cin>>x;
 for( i=0;i<n;i++)
 {
 if(a[i]==x)
 {
 return(i+1);
 }
 }
 if(i==n)
 {
 return -1;
 }
}
 int main()
{
 int n,choice,x;
 double a[20];
 char ch='y';
 while(ch=='y')
 {
 cout<<"Main Module....\n";
 cout<<"1.Input\n";
 cout<<"2.Linear Search\n";
 cout<<"Enter the choice\n";
 cin>>choice;
 switch(choice)
 {
 case 1:cout<<"Enter the number of elements in array \n";
 cin>>n;
 getinput(a,n);
 break;
 case 2:x=linearsearch(a,n);
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

