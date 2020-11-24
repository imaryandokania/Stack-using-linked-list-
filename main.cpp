//@AUTHOR:THE INSANE PROGRAMMER
#include<iostream>
#include "lib/services.hpp"
using namespace std;
struct node
{
    int data;
    node*link;
};
node *p,*top,*temp,*l;
void push()
{
  int x;
    p=new node;
    cout<<"ENTER DATA TO INSERT"<<endl;
    cout<<"---> ";
    cin>>x;
    if(top==NULL)
    {
        p->data=x;
        p->link=top;
        top=p;
    }
    else
    {
        p->data=x;
        p->link=top;
        top=p;
    }
    
}
void display()
{
      if(top==NULL) 
      {
    cout<<"Empty"<<endl; 
       }
else
{
    int count=0;
    cout<<endl;
    cout<<endl;
    ColorPalette::add(BOLD);
    cout<<setw(horizWidth)<<"STACK[LIFO]-STATUS DISPLAY"<<endl;
    cout<<endl;
cout<<endl;
ColorPalette::add(CYAN);
 p=new node;
 p=top;
 count=0;
while(p!=NULL)
{
   partition(2,DELIMETER);
   vertiDiv(EMPTY);
   cout<<setw(horizWidth)<<"|";
   cout<<endl;
   vertiDiv(EMPTY);
  cout<<setw(horizWidth)<<p->data;
  vertiDiv(EMPTY);
  cout<<setw(horizWidth)<<p->link;
  vertiDiv(EMPTY);
  cout<<setw(horizWidth)<<"|";
  if(count==0)
  {
    cout<<"<======TOP="<<top;
  }
  count++;
cout<<endl;
p=p->link; 
}
 
partition(2,DELIMETER);
vertiDiv(EMPTY);
cout<<setw(horizWidth)<<"|";
cout<<endl;
ColorPalette::add(BG_BrightYellow);
vertiDiv(EMPTY);
ColorPalette::add(RED);
ColorPalette::add(BOLD);
cout<<setw(horizWidth)<<"DATA";
ColorPalette::clear();
ColorPalette::add(BG_BrightYellow);
ColorPalette::add(CYAN);
vertiDiv(EMPTY);
ColorPalette::add(RED);
ColorPalette::add(BOLD);
cout<<setw(horizWidth)<<"LINK";
ColorPalette::clear();
ColorPalette::add(CYAN);
vertiDiv(EMPTY);
  cout<<setw(horizWidth)<<"V";
cout<<endl;
ColorPalette::add(BG_BrightYellow);
partition(2,DELIMETER);
ColorPalette::clear();
ColorPalette::add(CYAN);
vertiDiv(EMPTY);
ColorPalette::clear();
ColorPalette::add(RED);
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
}
}
void pop()
{
  top=top->link;
}
void rotate()
{
  int k;
  cout<<"Enter Data from where you want to rotate"<<endl;
  cin>>k;
  temp=new node;
  p=new node;
  l=new node;
  temp=top;
  int n=0;
  int count=0;
  p=temp;
  while(p!=NULL)
  {
    count++;
     
    if(p->data==k)
    {
      l->link=NULL;
      top=p;
    }
    if(p->link==NULL)
    {
      p->link=temp;
      break;
    }
    l=p;
    p=p->link;
  }
  

}
int main()
{
    p=new node;
    top=p=NULL;
    char ch='y';
    int n;
    ColorPalette::add(RED);
while(ch=='y'||ch=='Y')
 {
   cout<<endl;
 vertiDiv(DELIMETER);
 horizDiv(DELIMETER);
 vertiDiv(EMPTY);
 cout<<endl;
  vertiDiv(EMPTY);
cout<<setw(horizWidth)<<"1. Insert"; 
 vertiDiv(EMPTY);
  cout<<endl;
  vertiDiv(EMPTY);
cout<<setw(horizWidth)<<"2. Delete"; 
 vertiDiv(EMPTY);
  cout<<endl;
  vertiDiv(EMPTY);
cout<<setw(horizWidth)<<"3. Display"; 
 vertiDiv(EMPTY);
  cout<<endl;
  vertiDiv(EMPTY);
cout<<setw(horizWidth)<<"4. Rotate"; 
 vertiDiv(EMPTY);
  cout<<endl;
   vertiDiv(DELIMETER);
 horizDiv(DELIMETER);
 vertiDiv(EMPTY);
 cout<<endl;
 cout<<endl;
 cout<<"ENTER CHOICE"<<endl;
 cout<<"---> ";
 
cin>>n;
switch(n) {
        case 1:
        push();
        break;
         case 2:
         pop();
         break;
         case 3:
         display();
         break;
         case 4:
          rotate();
          break;

}
cout<<"BACK TO MENU?"<<endl;
cout<<"---> ";
cin>>ch;
}
}