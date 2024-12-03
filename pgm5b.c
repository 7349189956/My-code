#include<stdio.h>
#include<conio.h>
void tower(int n,char src,char temp,char dest)
{
 if(n==0)
 {
  return;
 }
 tower(n-1,src,dest,temp);
 printf("\nMove Disc from %d from %c to %c",n,src,dest);
 tower(n-1,temp,src,dest);
}

int main()
{
    int n;
    printf("Enter the number of Discs:\t");
    scanf("%d",&n);
    tower(n,'A','B','C');
    
    getch();
}
