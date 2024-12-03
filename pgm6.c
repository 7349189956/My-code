#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int item,queue[size];
int front=-1,rear=-1;

void add()
{
 if(front==(rear+1)%size)
 {
  printf("\nThe Circular Queue is Full and Overflow");
 }
 else
 {
  printf("\nEnter the elements ");
  scanf("%d",&item);
  if(front==-1)
  {
    front=rear=0;
  }
  else
  {
    rear=(rear+1)%size;
  }
  queue[rear]=item;
 }
}

void del()
{
  if(front==-1)
  {
    printf("\nThe Queue is Empty and Underflow");
  }
  else
  {
   item=queue[front];
   if(front==rear)
     front=rear=-1;
   else
     front=(front+1)%size;
     printf("\nThe deleted item is %d\n",item); 
  }
}

void display()
{
  int i;
  if(front==-1)
  {
    printf("\nThe Queue is Empty");
    return;
  }
  i=front;
  while(i!=rear)
  {
    printf("%d\t",queue[i]);
    i=(i+1)%size;
  }
  printf("%d\t",queue[i]);
}

int main()
{
  int choice;
  for(;;)
  {
    printf("\n\n---MENU---");
    printf("\n1:Insert\n2:Delete\n3:display\n4:Exit");
    printf("\nEnter your choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:add();
            break;
      case 2:del();
            break;
      case 3:display();
            break;
      case 4:exit(0);
      default:printf("Invalid choice");
    }
  }
return 0;
}
