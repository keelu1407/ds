#include<iostream>
#include<cmath>
using namespace std;
#define size 80
template<class Type>
class stacktype
{
 int top;
 Type stack[size];
 public:
 stacktype()
 {
 top=-1;
 }
 void push(Type x);
 Type pop();
 int isempty();
 int isfull();
 int postfixEvaluation(Type s[]);
 void display();
};
template<class Type>
int stacktype<Type>::postfixEvaluation(Type s[])
{
 stacktype<int> st;
 for(int i=0;s[i]!='\0';i++)
 {
 if(s[i]>='0' && s[i]<='9')
 {
 st.push(s[i]-'0');
 }
 else
 {
 int b=st.pop();
 int a=st.pop();
 switch(s[i])
 {
 case'+':st.push(a+b);
 break;
 case'-':st.push(a-b);
 break;
 case'*':st.push(a*b);
 break;
 case'/':st.push(a/b);
 break;
 case'$':st.push(pow(a,b));
 break;
 case'%':st.push(a%b);
 break;
 default: cout<<"Error in input"<<endl;
 }
 }
 }
 Type s1=st.pop();
 return s1;
}
template<class Type>
int stacktype<Type>::isempty()
{
 if(top==-1)
 {
 return -1;
 }
 else
 {
 return 1;
 }
}
template<class Type>
int stacktype<Type>::isfull()
{
 if(top==size-1)
 {
 return 1;
 }
 else
 {
 return -1;
 }
}
template<class Type>
void stacktype<Type>::push(Type x)
{
 stack[++top]=x;
}
template<class Type>
Type stacktype<Type>::pop()
{
 Type z;
 z=stack[top];
 top--;
 return z;
}
template<class Type>
void stacktype<Type>::display()
{
 if(top==-1)
 {
 cout<<"Stack is empty!!\n";
 return ;
 }
 else
 {
 cout<<"Stack is=> \n";
 for(int i=0;i<size;i++)
 {
 cout<<stack[i]<<" ";
 }
 cout<<endl;
 }
}
int main()
{
 stacktype<char>s1;
 int n;
 char ex[30];
 char ch='y';
 while(ch=='y'||ch=='Y')
 {
 cout<<"Enter the total number of elements of the stack(symbol plus characters)\n";
 cin>>n;
 cout<<"enter the expression"<<endl;
 for(int i=0;i<n;i++)
 {
 cin>>ex[i];
 }
 cout<<"Answer= "<<s1.postfixEvaluation(ex)<<endl;
 cout<<"Do you want to continue\n";
 cin>>ch;
 }
 return 0;
}
