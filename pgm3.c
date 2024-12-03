#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int stk[SIZE],rev[SIZE],top=-1;
void push()
{
int item;
if(top==SIZE-1)
{
printf("Stack Overflow");
}
else
{
printf("Enter the Element to push\n");
scanf("%d",&item);
top++;
stk[top]=item;
}
}
void pop()
{
if(top=-1)
{
printf("Stack is Underflow");
}
else
{
print("Popped element is %d",stk[top]);
top--;
}
}
void display()
{
int i;
if(top==-1)
{
printf("Stack is empty");
}
else
{
printf("Element in Stack are\n");
for(i=0;i<=top;i++)
{
printf("%d\t",stk[i]);
}
}
}
void palindrome()
{
int i,count=-1,j=-1;
if(top==-1)
{
printf("Stack is Empty");
}
else
{
for(i=top;i>=0;i--)
{
j++;
rev[j]=stk[i];
}
for(i=0;i<=top;i++)
{
count++;
}
}
if(count==top)
{a
printf("\tStack is Palindrome");
}
else
{
printf("\tStack is not Palindrome");
}
}
int main()
{
int choice;
while(1)
{
printf("\n\n---MENU---\n");
printf("\n\n:Push\n2:Pop\n3:Display\n4:Palindrome\n5:Exit\n");
printf("Enter your choice:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:push();
break; 
case 2:pop(0);
break;
case 3:display();
break;
case 4:palindrome();
break;
case 5:exit(0);
break;
default:printf("\tInvalid Choice");
}
}
getch();
}        
