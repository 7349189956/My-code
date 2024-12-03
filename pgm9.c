#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int flag;
struct node
{
  int cf;
  int px,py,pz;
  struct node*link;
};
typedef struct node*NODE;
NODE getnode()
{
 NODE x;
 x=(struct node*) malloc(sizeof(struct node));
 if(x==NULL)
 {
   printf("\nOut of memory\n");
   exit(0);
 }
 return x;
}

NODE insertrear(int cf,int x,int y,int z, NODE head)
{
  NODE temp,cur;
  temp=getnode();
  temp->cf=cf;
  temp->px=x;
  temp->py=y;
  temp->pz=z;
  cur=head->link;
  while(cur->link!=head)
  cur=cur->link;
  cur->link=temp;
  temp->link=head;
}

NODE readpoly(NODE head)
{
 int i;
 int cf;
 int px,py,pz;
 printf("\nEnter the coed as-999 to end the polynomial");
 for(i=1;;i++)
 {
  printf("\nEnter the %d term:",i);
  printf("Coef=");
  scanf("%d",&cf);
  if(cf==-999)
  break;
  printf("Pow x=");
  scanf("%d",&px);
  printf("Pow y=");
  scanf("%d",&py);
  printf("Pow z=");
  scanf("%d",&pz);
  head=insertrear(cf,px,py,pz,head);
 }
 return head;
}

int evaluate(NODE head)
{
 int x,y,z,sum=0;
 NODE poly;
 printf("Enter the value of x,y,z:\t");
 scanf("%d%d%d",&x,&y,&z);
 poly=head->link;
 while(poly!=head)
 {
  sum=sum+poly->cf*pow(x,poly->px)*pow(y,poly->py)*pow(z,poly->pz);
  poly=poly->link;
 }
 return sum;
}

void display(NODE head)
{
     NODE temp;
     if(head->link==head)
     {
      printf("\nPoly does not Exist\n");
      return;
     }
     temp=head->link;
      while(temp!=head)
      {
       printf("+%dx^%dy^%dz^%d",temp->cf,temp->px,temp->py,temp->pz);
       temp=temp->link;
      }
     printf("\n");
}

NODE addpoly(NODE h1,NODE h2,NODE h3)
{
 NODE p1,p2;
 int x1,x2,y1,y2,z1,z2,cf1,cf2,cf;
 int flag;
 p1=h1->link;
 while(p1!=h1)
 {
  x1=p1->px;
  y1=p1->py;
  z1=p1->pz;
  cf1=p1->cf;
  p2=h2->link;
  while(p2!=h2)
  {
   x2=p2->px;
   y2=p2->py;
   z2=p2->pz;
   cf2=p2->cf;
   if(x1==x2&&y1==y2&&z1==z2)
     break;
   p2=p2->link;
  }
  if(p2!=h2)
  {
    cf=cf1+cf2;
    if(cf!=0)
     h3=insertrear(cf,x1,y1,z1,h3);
  }
  else
   h3=insertrear(cf1,x1,y1,z1,h3);
   p1=p1->link;
 }
p2=h2->link;
while(p2!=h2)
 {
  if(p2!=h2)
  {
    h3=insertrear(p2->cf,p2->px,p2->py,p2->pz,h3);
  }
 p2=p2->link;
 }
 return h3;
}


int main()
{
 NODE h1,h2,h3,head;
 int sum,ch;
 head=getnode();
 head->link=head;
 h1=getnode();
 h2=getnode();
 h3=getnode();
 h1->link=h1;
 h2->link=h2;
 h3->link=h3;
 for(;;)
 {
  printf("\n1:Read polynomial\n2:Evaluate\n3:Display\n4:Add Poly\n5:Exit\n");
  printf("Enter your choice:\t");
  scanf("%d",&ch);

  switch(ch) 
  {
   case 1:printf("Enter the Polynomial:\n");
          head=readpoly(head);
          break;
   case 2:sum=evaluate(head);
          printf("The given Polynomial is\n");
          printf("The Result= %d\n",sum);
          break;
   case 3:printf("The given Polynomial is\n");
          display(head);
          break;
   case 4:printf("Enter the first Poly\n");
          h1=readpoly(h1);
          printf("Enter the second Poly\n");
          h2=readpoly(h2);
          h3=addpoly(h1,h2,h3);
          printf("The first Poly is\n");
          display(h1);
          printf("The second Poly is\n");
          display(h2);
          printf("The Sum of two Poly is\n");
          display(h3);
          break;
   case 5:exit(0);
   default:printf("Invalid choice\n");
           break;
        }
    }
    return 0;
}
 
