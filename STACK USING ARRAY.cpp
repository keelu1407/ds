#include <iostream>
using namespace std;
const int MAX=5;
template<class Type>
class Stacktype
{
 int top;
 Type s[MAX];
public:
 Stacktype()
 {
 top=-1;
 }
 void push(Type);
 Type pop();
 int isempty();
 int isfull();
 void display();
};
template<class Type>
void Stacktype<Type>::push(Type x)
{
 top++;
 s[top]=x;
 return;
}
template<class Type>
Type Stacktype<Type>::pop()
{
 Type del;
 del=s[top];
 top--;
 return del;
}
template<class Type>
int Stacktype<Type>::isempty()
{
 if(top==-1)
 return 1;
 else
 return -1;
}
template<class Type>
int Stacktype<Type>::isfull()
{
 if(top==MAX-1)
 return 1;
 else
 return -1;
}
template<class Type>
void Stacktype<Type>::display()
{
 int x=isempty();
 if(x==1)
 {
 cout<<"Stack is empty\n";
 return;
 }
 else
 {
 cout<<"Stack is :->\n";
 for(int i=top;i>=0;i--)
 {
 cout<<s[i]<<endl;
 }
 }
}
int main()
{
 Stacktype<double>stck;
 double p,d;
 int e,f,ch1;
 char ch='y';
 while(ch=='y'||ch=='Y')
 {
 cout<<"Main menu........\n";
 cout<<"1.To push\n";
 cout<<"2.To pop\n";
 cout<<"3.Isempty\n";
 cout<<"4.Isfull\n";
 cout<<"5.Display\n";
 cout<<"Enter the choice\n";
 cin>>ch1;
 switch(ch1)
 {
 case 1:f=stck.isfull();
 if(f==1)
 {
 cout<<"Overflow! Stack is full\n";
 }
 else
 {
 cout<<"Enter the Number you want to push\n";
 cin>>p;
 stck.push(p);
 stck.display();
 }
 break;
 case 2:e=stck.isempty();
 if(e==1)
 {
 cout<<"Underflow! Stack is empty,Deletion not possible\n";
 }
 else
 {
 d=stck.pop();
 cout<<d<<" has been deleted\n";
 stck.display();
 }
 break;
 case 3:e=stck.isempty();
 if(e==1)
 cout<<"Stack is empty\n";
 else
 cout<<"Stack is not empty\n";
 break;
 case 4:f=stck.isfull();
 if(f==1)
 cout<<"Stack is full\n";
 else
 cout<<"Stack is not full\n";
 break;
 case 5:e=stck.isempty();
 if(e==1)
 cout<<"Stack is empty\n";
 else
 {
 stck.display();
 }
 break;
 default:cout<<"ERROR IN INPUT.....\n";
 }
 cout<<"Do you want to continue(y/n)\n";
 cin>>ch;
 }
 return 0;
}
