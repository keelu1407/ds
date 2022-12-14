#include <iostream>
using namespace std;
template<class Type>
struct node
{
 int info;
 node<Type>*next;
};
template<class Type>
class linkedtype
{
 node<Type>*start;
public:
 linkedtype()
 {
 start=NULL;
 }
 node<Type>*createnewnode(Type);
 void createnewlist(node<Type>*);
 void addatend(node<Type>*);
 void addafter(node<Type>*);
 void addbefore(node<Type>*);
 void addatbeg(node<Type>*);
 void addati(node<Type>*,int);
 Type removefrombeg();
 Type removeati(int);
 Type deletion();
 int Count();
 void Search(Type);
 linkedtype<Type> concat(linkedtype<Type> l1);
 void display();
};
template<class Type>
Type linkedtype<Type>::removefrombeg()
{
 if(start==NULL)
 {
 return -1;
 }
 else
 {
 Type del;
 node<Type>*temp;
 temp=start;
 del=temp->info;
 start=start->next;
 delete temp;
 return del;
 }
}
template<class Type>
node<Type>*linkedtype<Type>::createnewnode(Type x)
{
 node<Type>*nptr;
 nptr=new node<Type>;
 nptr->info=x;
 nptr->next=NULL;
 return(nptr);
}
template<class Type>
void linkedtype<Type>::createnewlist(node<Type>*nptr)
{
 node<Type>*temp;
 temp=start;
 start=nptr;
 nptr->next=temp;
}
template<class Type>
void linkedtype<Type>::addafter(node<Type>*nptr)
{
 Type after;
 node<Type>*temp;
 cout<<"Enter the info part of node after which you wish to add\n";
 cin>>after;
 for(temp=start;temp!=NULL;temp=temp->next)
 {
 if(after==temp->info)
 {
 nptr->next=temp->next;
 temp->next=nptr;
 }
 }
}
template<class Type>
void linkedtype<Type>::addbefore(node<Type>*nptr)
{
 int before;
 node<Type>*temp;
 cout<<"Enter the info part of node before which you wish to add\n";
 cin>>before;
 if(start->info==before)
 {
 nptr->next=start;
 start=nptr;
 }
 else
 {
 for(temp=start;temp->next!=NULL;temp=temp->next)
 {
 if(temp->next->info==before)
 {
 nptr->next=temp->next;
 temp->next=nptr;
 return;
 }
 }
 }
}
template<class Type>
void linkedtype<Type>::addatend(node<Type>*nptr)
{
 node<Type>*temp;
 if(start==NULL)
 {
 start=nptr;
 return;
 }
 for(temp=start;temp->next!=NULL;temp=temp->next)
 {
 }
 temp->next=nptr;
}
template<class Type>
void linkedtype<Type>::addatbeg(node<Type>*nptr)
{
 if(start==NULL)
 start=nptr;
 else
 {
 nptr->next=start;
 start=nptr;
 }
 return;
}
template<class Type>
void linkedtype<Type>::addati(node<Type>*nptr,int i)
{
 if(i>(*this).Count()+1||i<1)
 {
 cout<<"Enter valid positions\n";
 return;
 }
 else if(i==1)
 {
 addatbeg(nptr);
 return;
 }
 else if(i==Count()+1)
 {
 addatend(nptr);
 return;
 }
 else
 {
 node<Type>*temp=start;
 for(int j=1;j<i-1;j++)
 {
 temp=temp->next;
 }//temp is at i-1 position;
 nptr->next=temp->next;
 temp->next=nptr;
 return;
 }
}
template<class Type>
Type linkedtype<Type>::removeati(int i)
{
 Type del;
 if(i>(*this).Count()||i<1)
 {
 cout<<"Enter valid positions\n";
 return -1;
 }
 else if(i==1)
 {
 del=removefrombeg();
 return del;
 }
 else if(i==Count())
 {
 del=deletion();
 return del;
 }
 else
 {
 node<Type>*nptr;
 node<Type>*temp=start;
 for(int j=1;j<i-1;j++)
 {
 temp=temp->next;
 }//temp is at i-1 position;
 del=temp->next->info;
 temp->next=temp->next->next;
 return del;
 }
}
template<class Type>
int linkedtype<Type>::Count()
{
 int ct=0;
 node<Type>*temp;
 for(temp=start;temp!=NULL;temp=temp->next)
 {
 ct++;
 }
 return ct;
}
template<class Type>
void linkedtype<Type>::display()
{
 node<Type>*temp;
 if(start==NULL)
 {
 cout<<"Linked list is empty\n";
 }
 else
 {
 cout<<"LINKED LIST is=> \n";
 for(temp=start;temp!=NULL;temp=temp->next)
 {
 cout<<temp->info<<" ";
 }
 cout<<endl;
 }
}
template<class Type>
void linkedtype<Type>::Search(Type x)
{
 int i=0;
 node<Type>*temp;
 if(start==NULL)
 {
 cout<<"Linked list is empty\n";
 }
 else
 {
 for(temp=start;temp!=NULL;temp=temp->next)
 {
 if(temp->info==x)
 {
 cout<<"Element found at"<<i+1<<" position or at "<<i<<" index\n";
 return;
 }
 i++;
 }
 cout<<"Element not found"<<endl;
 }
 return;
}
template<class Type>
Type linkedtype<Type>::deletion()
{
 int p=0;
 node<Type>*temp;
 node<Type>*x;
 for(temp=start;temp->next->next!=NULL;temp=temp->next)
 {
 }
 p=temp->next->info;
 temp->next=NULL;
 return(p);
}
int main()
{
 linkedtype<int>l1,l2,l3;
 int choice,n,in,ct,pos;
 node<int>*nptr;
 cout<<"Creating new linked list l1. Enter number of nodes in new list\n";
 cin>>n;
 for(int i=n-1;i>=0;i--)
 {
 cout<<"Enter the info part of node "<<i+1<<" ";
 cin>>in;
 nptr=l1.createnewnode(in);
 if(nptr==NULL)
 {
 cout<<"Compiler out of memory\n";
 exit(0);
 }
 else
 l1.createnewlist(nptr);
 }
 cout<<"Creating new linked list l2. Enter number of nodes in new list\n";
 cin>>n;
 for(int i=n-1;i>=0;i--)
 {
 cout<<"Enter the info part of node "<<i+1<<" ";
 cin>>in;
 nptr=l2.createnewnode(in);
 if(nptr==NULL)
 {
 cout<<"Compiler out of memory\n";
 exit(0);
 }
 else
 l2.createnewlist(nptr);
 }
 char ch='y';
 while(ch=='y'||ch=='Y')
 {
 cout<<"MAIN MODULE....\n";
 cout<<"1.ADD at END\n";
 cout<<"2.ADD after given NODE\n";
 cout<<"3.ADD before given NODE\n";
 cout<<"4.DELETION at End\n";
 cout<<"5.Count Total number of NODES\n";
 cout<<"6.Display\n";
 cout<<"7.ADD at beginning\n";
 cout<<"8.ADD at ith position\n";
 cout<<"9.Remove from Beginning\n";
 cout<<"10.Remove from ith position\n";
 cout<<"11.Search for an element x\n";
 cout<<"Enter your choice\n";
 cin>>choice;
 switch(choice)
 {
 case 1:cout<<"Enter info part of Node to be added at End\n";
 cin>>n;
 nptr=l1.createnewnode(n);
 if(nptr==NULL)
 {
 cout<<"ERROR,NODE NOT CREATED!!!!\n";
 }
 else
 {
 l1.addatend(nptr);
 l1.display();
 }
 break;
 case 2:cout<<"Enter the info part of node to be added\n";
 cin>>n;
 nptr=l1.createnewnode(n);
 if(nptr==NULL)
 {
 cout<<"ERROR,NODE NOT CREATED!!!!\n";
 }
 else
 {
 l1.addafter(nptr);
 l1.display();
 }
 break;
 case 3:cout<<"Enter the info part of node to be added\n";
 cin>>in;
 nptr=l1.createnewnode(in);
 if(nptr==NULL)
 {
 cout<<"ERROR,NODE NOT CREATED!!!!\n";
 }
 else
 {
 l1.addbefore(nptr);
 l1.display();
 }
 break;
 case 4:in=l1.deletion();
 cout<<in<<" has been deleted\n";
 l1.display();
 break;
 case 5:ct=l1.Count();
 cout<<"No. of nodes="<<ct<<endl;
 break;
 case 6:l1.display();
 break;
 case 7:cout<<"Enter info part of Node to be added at beginning\n";
 cin>>n;
 nptr=l1.createnewnode(n);
 if(nptr==NULL)
 {
 cout<<"ERROR,NODE NOT CREATED!!!!\n";
 }
 else
 {
 l1.addatbeg(nptr);
 l1.display();
 }
 break;
 case 8:cout<<"Enter the position at which node is to be added\n";
 cin>>pos;
 cout<<"Enter info part of Node to be added at ith position\n";
 cin>>n;
 nptr=l1.createnewnode(n);
 if(nptr==NULL)
 {
 cout<<"ERROR,NODE NOT CREATED!!!!\n";
 }
 else
 {
 l1.addati(nptr,pos);
 l1.display();
 }
 break;
 case 9:in=l1.removefrombeg();
 if(in!=-1)
 {
 cout<<in<<" has been deleted\n";
 l1.display();
 }
 break;
 case 10:cout<<"Enter the position from which node is to be deleted\n";
 cin>>pos;
 in=l1.removeati(pos);
 if(in!=-1)
 {
 cout<<in<<" has been deleted\n";
 }
 l1.display();
 break;
 case 11:cout<<"Enter the info part of element to search\n";
 cin>>in;
 l1.Search(in);
 break;
 default:cout<<"Error in Input\n";
 break;
 }
 cout<<"Do you want to continue\n";
 cin>>ch;
 }
 return 0;
}

