#include<iostream>
using namespace std;
template<class T>
class node{
public:
T info;
node<T>* next;
public:
node(){
}
};
template<class T>
class stacktype{
node<T>* top;
public:
 stacktype(){
 top=NULL;
}
node<T>* createnewnode(T);
void push(node<T>*);
T pop();
int isempty();
void clear();
void count(node<T>*);
void topmost();
 void display();
};
template<class T>
node<T>* stacktype<T>::createnewnode(T x){
node<T>* nptr;
nptr=new node<T>();
nptr->info=x;
nptr->next=NULL;
return (nptr);
}
template<class T>
void stacktype<T>::push(node<T>* nptr){
if(top==NULL){
top=nptr;
}
else{
nptr->next=top;
top=nptr;
}
}
template<class T>
T stacktype<T>::pop(){
node<T>* p;
if(top==NULL){
return 1;
}
else{
p=top;
top=top->next;
T d=p->info;
delete p;
return (d);
}
}
template<class T>
void stacktype<T>::clear(){
node<T>* p;
 p=top;
 top=top->next;
for(p=top;p!=NULL;top->next){
delete p;
p=top;
}
}
template<class T>
void stacktype<T>::count(node<T>* temp){
int ct=0;
if(top==NULL){
 cout<<"\n There is no element(i.e. node)in the stack\n"<<"Thus, the no of nodes is:"<<ct;
}
else{
for(temp=top;temp!=NULL;temp=temp->next){
ct++;
}
cout<<"\nThe total numbers of nodes or elements in the stack:"<<"\t"<<ct;
}
}
template<class T>
int stacktype<T>::isempty(){
if(top==NULL){
return 1;
}
else{
return -1;
}
}
template<class T>
void stacktype<T>::topmost(){
node<T>* temp;
if(top==NULL){
cout<<"\nStack is empty\n"<<"So there is no topmost element and hence top=NULL!";
}
else{
temp=top;
cout<<"\nThe top's value or the topmost element is\n"<<temp->info;
}
}
template<class T>
void stacktype<T>::display(){
node<T>* ptr;
 cout<<"\n--------------------------------------------\n";
if(top==NULL){
cout<<"\nStack is empty\nNothing to be display\n";
}
else{
 cout<<"Elements of the stack are as follows:\n";
 for(ptr=top;ptr!=NULL;ptr=ptr->next){
 cout<<ptr->info<<"\t";
 }
}
cout<<"\n---------------------------------------------\n";
}
int main(){
stacktype<int> s;
int x,ch1,e,d;
node<int>* temp;
char ch='y';
while(ch=='y'||ch=='Y'){
cout<<"1.Push operation\n";
cout<<"2.Pop operation\n";
cout<<"3.isempty\n";
cout<<"4.clear\n";
cout<<"5.count\n";
cout<<"6.topmost\n";
cout<<"7.Display\n";
cout<<"Enter your choice\n";
cin>>ch1;
switch(ch1){
 case 1:
 cout<<"Enter the element to be inserted or push in the stack\n";
 cin>>x;
 temp=s.createnewnode(x);
 s.push(temp);
 s.display();
 break;
 case 2:
 d=s.pop();
if(d==1){
cout<<"ERROR!!!\n The stack is empty\nThus, Deletion is not 
possible\n";
}
else{
cout<<"\nThe popped or delete element is"<<"\t"<<d;
}
s.display();
break;
 case 3:
 e=s.isempty();
 if(e==1){
 cout<<"\nThe stack is empty\n";
 }
 else{
 cout<<"\nThe stack is not empty";
 }
 break;
 case 4:
 s.clear();
 s.display();
 break;
 case 5:
 s.count(temp);
 break;
 case 6:
 s.topmost();
 s.display();
 break;
 case 7:
 s.display(); 
}
cout<<"\nDo you want to continue\n";
cin>>ch;
}
return 0;
}

