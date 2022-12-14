#include <iostream>
using namespace std;
const int MAX=50;
template<class Type>
class Sort
{
public:
 Type arr[MAX];
 int n;
 void input();
 void insertionsort();
 void bubblesort();
 void selectionsort();
 void display();
};
template<class Type>
void Sort<Type>::input()
{
 cout<<"Enter the number of elements in array\n";
 cin>>n;
 if(n>MAX)
 {
 cout<<"Error!! Exceeding MAX value\n";
 exit(0);
 }
 cout<<"Enter the elements in array\n";
 for(int i=0;i<n;i++)
 {
 cin>>arr[i];
 }
}
template<class Type>
void Sort<Type>::display()
{
 cout<<"Elements in array are:=> ";
 for(int i=0;i<n;i++)
 {
 cout<<arr[i]<<" ";
 }
 cout<<endl;
}
template<class Type>
void Sort<Type>::insertionsort()
{
 Type key;
 int i,j;
 for(i=1;i<n;i++)
 {
 key=arr[i];
 j=i-1;
 while(j>=0 && arr[j]>key)
 {
 arr[j+1]=arr[j];
 j=j-1;
 }
 arr[j+1]=key;
 }
}
template<class Type>
void Sort<Type>::bubblesort()
{
 Type temp;
 char Switch='T';
 for(int i=0;i<n-1 && Switch=='T';i++)
 {
 Switch='F';
 for(int j=0;j<n-1;j++)
 {
 if(arr[j]>arr[j+1])
 {
 Switch='T';
 temp=arr[j];
 arr[j]=arr[j+1];
 arr[j+1]=temp;
 }
 }
 }
}
template<class Type>
void Sort<Type>::selectionsort()
{
 Type small,temp;
 int pos;
 for(int i=0;i<n-1 ;i++)
 {
 small=arr[i];
 pos=i;
 for(int j=i+1;j<n;j++)
 {
 if(arr[j]<small)
 {
 small=arr[j];
 pos=j;
 }
 }
 temp=arr[i];
 arr[i]=arr[pos];
 arr[pos]=temp;
 }
}
int main()
{
 Sort<int>s1;
 char ch='y';
 int choice;
 while(ch=='y'||ch=='Y')
 {
 cout<<"Main Module............\n";
 cout<<"1.Input the Array\n";
 cout<<"2.InsertionSort\n";
 cout<<"3.BubbleSort\n";
 cout<<"4.SelectionSort\n";
 cout<<"Enter the choice\n";
 cin>>choice;
 switch(choice)
 {
 case 1:s1.input();
 s1.display();
 break;
 case 2:s1.insertionsort();
 s1.display();
 break;
 case 3:s1.bubblesort();
 s1.display();
 break;
 case 4:s1.selectionsort();
 s1.display();
 break;
 default:cout<<"Error in Input\n";
 break;
 }
 cout<<"Do you want to continue\n";
 cin>>ch;
 }
 return 0;
}

