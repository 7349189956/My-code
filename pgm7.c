#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
struct node
{
  int sem;
  int phno;
  char name[20],branch[10],usn[20];
  struct node*next;
}*first=NULL,*last=NULL,*temp=NULL,*temp1;

void create()
{
  int sem;
  int phno;
  char name[20],branch[10],usn[20];
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter USN,Name,Branch,Sem,Phno of student:\n");
  scanf("%s%s%s%d%d",usn,name,branch,&sem,&phno);
  strcpy(temp->usn,usn);
  strcpy(temp->name,name);
  strcpy(temp->branch,branch);
  temp->sem=sem;
  temp->phno=phno;
  temp->next=NULL;
  count++;
}

void insertfirst()
{
  if(first==NULL)
  {
    create();
    first=temp;
    last=first;
  }
  else
  {
   create();
   temp->next=first;
   first=temp;
  }
}

void insertlast()
{
 if(first==NULL)
  {
    create();
    first=temp;
    last=first;
  }
  else
  {
   create();
   last->next=temp;
   last=temp;
  }
}

void display()
{
  temp1=first;
  if(temp1==NULL)
  {
    printf("\nList is Empty\n");
    return;
  }
  printf("\nLinked list element from the begining: \n");
  while(temp1!=NULL)
  {
    printf("%s\n%s\n%s\n%d\n%d\n\n",temp1->usn,temp1->name,temp1->branch,temp1->sem,temp1->phno);
    temp1=temp1->next;
  }
  printf("No of students: %d\n",count);
}

void deleteend()
{
  struct node*temp;
  temp=first;
  if(temp->next==NULL)
   {
     free(temp);
     first=NULL;
   }
  else
  {
    while(temp->next!=last)
    temp=temp->next;
    printf("%s\n%s\n%s\n%d\n%d\n",last->usn,last->name,last->branch,last->sem,last->phno);
    free(last);
    temp->next=NULL;
    last=temp;
  }
  count--;
}

void deletefront()
{
  struct node*temp;
  temp=first;
  if(temp->next==NULL)
   {
     free(temp);
     first=NULL;
   }
  else
  {
   first=temp->next;
   printf("%s\n%s\n%s\n%d\n%d\n\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
   free(temp);
  }
  count--;
}

int main()
{
 int ch,n,i;
 first=NULL;
 temp=temp1=NULL;
 while(1)
 {
  printf("\n\n---MENU---\n");
  printf("\n1:Create SLL\n2:Display\n3:Insert at End\n4:Delete at End\n5:Insert at Front\n6:Delete at Front\n7:Exit\n");
  printf("\nEnter your choice:\t");
  scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("\nEnter the no of Students:\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
              insertfirst();
            break;
     case 2:display();
            break;
     case 3:insertlast();
            break;
     case 4:deleteend();
            break;
     case 5:insertfirst();
            break;
     case 6:deletefront();
            break;
     case 7:exit(0);
     default:printf("Invalid choice");
    }
 }
 return 0;
}
