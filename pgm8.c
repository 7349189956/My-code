#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
struct node
{
  struct node*link;
  struct node*rlink;
  int info,ssn,phno;
  float sal;
  char name[20],dept[10],desg[20];
};
typedef struct node*NODE;
NODE temp,temp1,cur,first;

void create()
{
  int ssn,phno;
  char name[20],dept[10],desg[20];
  float sal;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->link=NULL;
  temp->rlink=NULL;
  printf("Enter SSN,Name,Department,Designation,Salary,Phno of Employ:\n");
  scanf("%d%s%s%s%f%d",&ssn,name,dept,desg,&sal,&phno);
  temp->ssn=ssn;
  strcpy(temp->name,name);
  strcpy(temp->dept,dept);
  strcpy(temp->desg,desg); 
  temp->sal=sal;
  temp->phno=phno;
  count++;
}
void insertfront()
{
  if(first==NULL)
  {
    create();
    first=temp;
    temp1=first;
  }
  else
  {
   create();
   temp->rlink=first;
   first->link=temp;
   first=temp;
  }
}

void insertrear()
{
  if(first==NULL)
  {
    create();
    first=temp;
    temp1=first;
  }
  else
  {
   create();
   temp->rlink=temp;
   first->link=temp1;
   temp1=temp;
  }
}

void display()
{
  cur=first;
  if(cur==NULL)
  {
    printf("\nList is Empty\n");
    return;
  }
  printf("\nThe elements are: \n");
  while(cur!=NULL)
  {
   printf("\n%d\t%s\t%s\t%s\t%f\t%d\t\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
   cur=cur->rlink;
  }
  printf("No of Employee= %d\n",count);
}

int deleterear()
{
  struct node*temp;
  temp=first;
  if(temp->rlink==NULL)
   {
     free(temp);
     first=NULL;
     return 0;
   }
  else
  {
   cur=temp1->link;
   cur->rlink=NULL;
   printf("\n%d\t%s\t%s\t%s\t%f\t%d\t\n",temp1->ssn,temp1->name,temp1->dept,temp1->desg,temp1->sal,temp1->phno);
   free(temp1);
  }
  count--;
  return 0;
}

int deletefront()
{
  struct node*temp;
  temp=first;
  if(temp->rlink==NULL)
   {
     free(temp);
     first=NULL;
     return 0;
   }
  else
  {
   first=first->rlink;
   printf("\n%d\t%s\t%s\t%s\t%f\t%d\t\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
   free(temp);
  }
  count--;
  return 0;
}

int main()
{
 int ch,n,i;
 first=NULL;
 temp=temp1=NULL;
  printf("\n\n---MENU---\n");
  printf("\n1:Create DLL of employee\n2:Display\n3:Insert Front\n4:Insert Rear\n5:Delete Front\n6:Delete Rear\n7:Exit\n");
  while(1)
  {
  printf("\nEnter your choice:\t");
  scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("\nEnter the no of Employee:\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
              insertrear();
            break;
     case 2:display();
            break;
     case 3:insertfront();
            break;
     case 4:insertrear();
            break;
     case 5:deletefront();
            break;
     case 6:deleterear();
            break;
     case 7:exit(0);
     default:printf("Invalid choice");
    }
}
 return 0;
}
