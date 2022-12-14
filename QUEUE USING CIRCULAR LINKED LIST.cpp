#include <iostream>
using namespace std;
template<class T>class node
{
 public:
 T info;
 node<T> *next;
 public:
 node(T x, node<T>*n=NULL)
 {
 info = x;
 next = n;
 }
};
template<class T>class queuetype
{
 node<T> *f,*r;
public :
 queuetype()
 {
 f = r = NULL;
 }
 void enqueue(T x);
 int dequeue();
 int isempty();
 void count(node<T> *);
 void rearmost();
 void display();
 };
template<class T>int queuetype<T> :: isempty()
{
 if(f==NULL)
 return 1;
 else
 return -1;
}
template<class T>void queuetype<T> :: count(node<T> *temp)
{
 int ct = 0;
 if(f == NULL)
 {
 cout<<"\n Queue is empty "<<" Nodes are : "<<ct;
 }
 else
 {
 for(temp = f ; temp != NULL ; temp = temp -> next)
 {
 ct++;
 }
 cout<<"\n Total No. of Nodes in Queue : "<<ct;
 }
}
template<class T>void queuetype<T> :: rearmost()
{
 node<T>* temp;
 if(r == NULL)
 {
 cout<<"\n Queue is empty ";
 }
 else
 {
 temp = r;
 cout<<"\n Rearmost is : "<<temp -> info;
 }
}
template<class T>int queuetype<T> :: dequeue()
{
 int x;
 node<T> *temp;
 x = f->info;
 temp = f;
 f = f->next;
 delete(temp);
 if(f == NULL)
 f=r=NULL;
 return(x);
 }
template<class T>void queuetype<T> :: enqueue(T x)
{
 node<T> *temp;
 temp = new node<T>(x);
 if(f==NULL)
 {
 f = r = temp;
 }
 else
 {
 r->next = temp;
 r = temp;
 }
}
template<class T>void queuetype<T> :: display()
{
 if(f==NULL)
 {
 cout<<"\n Queue is empty ! Nothing to display ";
 }
 else
 {
 cout<<"\n Contents of the stack starting from rearmost point are : ";
 node<T> *temp;
 for(temp=f; temp!=NULL; temp=temp->next)
 {
 cout<<temp->info<<"\t";
 }
}
}
int main()
{
 queuetype<int> queue;
 int e,a,d,choice;
 node<int> *temp;
 char c ='y';
 while(c=='y'||c=='Y')
 {
 cout<<"\n Main Menu"<<"\n 1.Enqueue"<<"\n 2.Dequeue"<<"\n 3.isempty"<<"\n 4.Count"<<"\n 5.Rearmost"<<"\n 6.Display";
 cout<<"\n Enter your Choice(1-6) : ";
 cin>>choice;
 switch(choice)
 {
 case 1 : cout<<"\n Enter a value : ";
 cin>>a;
 queue.enqueue(a);
 queue.display();
 break;
 case 2 : d = queue.dequeue();
 if(d==1)
 {
 cout<<"\n Queue is empty! Underflow ";
 }
 else
 {
 cout<<d<<" "<<"has been deleted";
 }
 queue.display();
 break;
 case 3 : e = queue.isempty();
 if(e==1)
 {
 cout<<"\n Queue is empty ";
 }
 else
 {
 cout<<"\n Queue is not empty ";
 }
 break;
 case 4 : queue.count(temp);
 break;
 case 5 : queue.rearmost();
 queue.display();
 break;
 case 6 : queue.display();
 break;
 }
 cout<<"Do u want to continue (y/n) : ";
 cin>>c;
 }
 return 0;
}
