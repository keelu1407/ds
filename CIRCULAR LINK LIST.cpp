#include<iostream>
using namespace std;
template<class Type>
class cnode
{
public:
 Type info;
cnode* next;
cnode(Type x,cnode* n=0){
info=x;
next=n;
}
};
template<class Type>
class cllist
{
public:
 cnode<Type>* cursor;
cllist()
{
cursor=NULL;
}
void input();
int isempty()
{
 if(cursor==NULL)
 return 1;
 else
 return 0;
}
void addtofront(Type x);
void addtoback(Type x);
void addafter(Type x,Type y);
void add_at_i(int i,Type x);
Type deletefromfront();
Type deletefromback();
void deletenode(Type x);
int Count();
cnode<Type>* isinlist(Type x);
cllist operator+(cllist<Type> l1);
void display();
};
template<class Type>
void cllist<Type>::input()
{
int n;
Type x;
cout<<"Enter the no of nodes in the CLL\n";
cin>>n;
for(int i=0;i<n;i++){
cout<<"Enter the info part of node "<<i+1<<"\n";
cin>>x;
addtoback(x);
}
}
template<class Type>
void cllist<Type>::addtofront(Type x)
{
cnode<Type>* temp=new cnode<Type>(x);
if(isempty())
 {
cursor=temp;
temp->next=cursor;
}
else
{
temp->next=cursor->next;
cursor->next=temp;
}
}
template<class Type>
void cllist<Type>::addtoback(Type x){
cnode<Type>* temp=new cnode<Type>(x);
if(isempty())
 {
cursor=temp;
cursor->next=cursor;
}
else
{
temp->next=cursor->next;
cursor->next=temp;
cursor=temp;
}
}
template<class Type>
void cllist<Type>::add_at_i(int i,Type x)
{
cnode<Type>* temp;
if(i>Count()+1||i<1){
cout<<"Enter the valid position!!!\n";
return;
}
else
 {
 if(i==1)
 {
addtofront(x);
}
else if(i==(Count()+1))
{
addtoback(x);
}
else
{
 temp=cursor->next;
cnode<Type>* nptr=new cnode<Type>(x);
for(int j=1;j<i-1;j++)
 {
 temp=temp->next;
 }//temp is at i-1 position after the loop
nptr->next=temp->next;
temp->next=nptr;
}
}
}
template<class Type>
void cllist<Type>::addafter(Type x ,Type y)
{
cnode<Type>* temp;
for(temp=cursor->next;temp!=cursor;temp=temp->next)
 {
 if(temp->info==x)
 {
 cnode<Type>*nptr=new cnode<Type>(y);
 nptr->next=temp->next;
 temp->next=nptr;
 return;
 }
 }
 if(temp==cursor&&temp->info==x)
 {
 addtoback(y);
 return;
 }
}
template<class Type>
Type cllist<Type>::deletefromfront()
{
cnode<Type>* temp;
Type x;
x=cursor->next->info;
if(cursor->next==cursor)
{
 delete cursor;
cursor=NULL;
}
else
{
temp=cursor->next;
cursor->next=temp->next;
delete temp;
}
return x;
}
template<class Type>
Type cllist<Type>::deletefromback()
{
cnode<Type>* temp;
Type x;
x=cursor->info;
if(cursor->next==cursor)
 {
 delete cursor;
cursor=NULL;
}
else
{
temp=cursor->next;
while(temp->next!=cursor)
{
temp=temp->next;
}
temp->next=cursor->next;
delete cursor;
cursor=temp;
}
return x;
}
template<class Type>
void cllist<Type>::deletenode(Type x)
{
cnode<Type>* previous,*current;
if(cursor->next==cursor&&cursor->info==x)
 {
 delete cursor;
 cout<<cursor->info<<" has been deleted\n";
cursor=NULL;
}
else if(cursor->next->info==x){
Type z=deletefromfront();
cout<<z<<" has been deleted\n";
}
else
{
previous=cursor->next;
current=previous->next;
while(current!=cursor&&current->info!=x){
previous=current;
current=current->next;
}
if(current!=cursor->next)
{
 Type z=current->info;
 cout<<z<<" has been deleted\n";
previous->next=current->next;
 if(current==cursor)
 {
 cursor=previous;
 delete current;
 }
}
else
{
cout<<"\nElement not found\n";
}
}
}
template<class Type>
cnode<Type>* cllist<Type>::isinlist(Type x)
{
cnode<Type>* temp;
temp=cursor->next;
do{
if(temp->info==x)
 {
 return temp;
 }
temp=temp->next;
}while(temp!=cursor->next);
return NULL;
}
template<class Type>
cllist<Type> cllist<Type>::operator+(cllist<Type> l1)
{
cllist<Type> l3;
cnode<Type>* temp;
if(!(*this).isempty())
 {
temp=(*this).cursor->next;
do{
l3.addtoback(temp->info);
temp=temp->next;
}while(temp!=(*this).cursor->next);
}
if(!l1.isempty())
{
temp=l1.cursor->next;
do{
l3.addtoback(temp->info);
temp=temp->next;
}while(temp!=l1.cursor->next);
}
return l3;
}
template<class Type>
int cllist<Type>::Count()
{
int ct=0;
cnode<Type>* temp;
if(isempty())
 {
ct=0;
}
else if(cursor->next==cursor)
{
ct=1;
}
else
{
for(temp=cursor->next;temp!=cursor;temp=temp->next)
{
ct++;
}
if(temp==cursor){
ct++;
}
}
return ct;
}
template<class Type>
void cllist<Type>::display()
{
cnode<Type>*temp;
if(isempty())
 {
cout<<"CIRCULAR LINKED LIST IS EMPTY\n";
}
else
{
cout<<"CLL is=> \n";
 for(temp=cursor->next;temp!=cursor;temp=temp->next)
 {
 cout<<temp->info<<" ";
}
if(temp==cursor)
{
cout<<temp->info<<" ";
}
 cout<<endl;
}
}
int main()
{
cllist<int>l1,l2,l3;
int choice,x,y1,e,del,p;
char ch='y';
cnode<int>* temp;
l1.input();
l1.display();
while(ch=='y'||ch=='Y')
 {
cout<<"MAIN MODULE........\n";
cout<<"1.Insert an element x at the front of the CLL\n";
cout<<"2.Insert an element x after an element y in the CLL\n";
cout<<"3.Insert an element x at the back of the CLL\n";
cout<<"4.Remove an element from the back of CLL\n";
cout<<"5.Remove an element from the front of CLL\n";
cout<<"6.Remove an element x from the CLL\n";
cout<<"7.Search for an element x in the CLL and return its pointer\n";
cout<<"8.Concatenate 2 CLL's\n";
cout<<"9.Insert an element at ith position\n";
cout<<"10.Count the total nodes in CLL\n";
cout<<"Enter your choice\n";
cin>>choice;
switch(choice){
case 1:cout<<"Enter the info part of node to be added at front\n";
 cin>>x;
 l1.addtofront(x);
 l1.display();
 break;
 case 2:cout<<"Enter the info part of node to be added\n";
 cin>>y1;
 cout<<"Enter the info part of node after which given node is to be added\n";
 cin>>x;
 l1.addafter(x,y1);
 l1.display();
 break;
case 3:cout<<"Enter the info part of node to be added at back\n";
 cin>>x;
 l1.addtoback(x);
 l1.display();
 break;
 case 4:e=l1.isempty();
 if(e==1)
 {
 cout<<"CLL is empty\n";
 }
 else
 {
 del=l1.deletefromback();
 cout<<del<<" has been deleted\n";
 l1.display();
 }
 break;
case 5:e=l1.isempty();
 if(e==1)
 {
 cout<<"CLL is empty\n";
 }
 else
 {
 del=l1.deletefromfront();
 cout<<del<<" has been deleted\n";
 l1.display();
 }
 break;
case 6:e=l1.isempty();
 if(e==1)
 {
 cout<<"CLL is empty\n";
 }
 else
 {
 cout<<"Enter the info part of node to be deleted\n";
 cin>>x;
 l1.deletenode(x);
 l1.display();
 }
 break;
case 7:e=l1.isempty();
 if(e==1)
 {
 cout<<"CLL is empty\n";
}
 else
 {
 cout<<"Enter the info part of the node to search in CLL\n";
 cin>>x;
 temp=l1.isinlist(x);
 if(temp==NULL)
 {
 cout<<"ELEMENT NOT FOUND!!!\n";
 }
 else
 {
 cout<<"ELEMENT FOUND\n "<<temp->info<<" IS PRESENT IN CLL\n";
 }
}
break;
case 8:if(l1.isempty()&&l2.isempty())
 {
 cout<<"The List is Empty\n";
 }
 else
 {
 l2.input();
 l3=l1+l2;
 cout<<"Concatenated CLL is =>\n";
 l3.display();
 }
 break;
case 9:cout<<"Enter the position at which node is to be added\n";
 cin>>p;
 cout<<"Enter the info part of node to be at position "<<p<<endl;
 cin>>x;
 l1.add_at_i(p,x);
 l1.display();
 break;
 case 10:cout<<"Total nodes present in the CLL is "<<l1.Count()<<endl;
 break;
 default:cout<<"Error in input\n";
 break;
}
cout<<"Do you want to continue\n";
cin>>ch;
}
return 0;
}

