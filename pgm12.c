#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#define MAX 10 
struct rec 
{
int num;
}r,s;
 void main()
{
 int i,ans=1,done=0,flag=0,ret;
 int num,n, *p,key;
char *data=NULL; 
FILE *fp;
fp=fopen("f2.dat","w+b");
printf("Collision Handling by Linear Probing:\n");
 for(i=0;i<MAX;i++)
{
printf("%ld\t",ftell(fp));
r.num=999; 
fwrite(&r,1,sizeof(struct rec),fp);
}
do{
done=0;
rewind(fp);
printf("\nEnter the Number:\t");
scanf("%d",&s.num); 
if(s.num<1000&&s.num>9999) break; 
key=(s.num)%10; 
printf("Hash key %d\n",key);
if(flag==0)
{
 fseek(fp,key *sizeof(struct rec),0);
 } 
else 
fseek(fp,key *sizeof(struct rec),0);
printf("Insert Pos {%ld}\n",ftell(fp));
ret = fread(&r,1,sizeof(struct rec),fp);
 if(r.num<1000) 
{
 if(flag==0) 
{ 
fseek(fp,key *sizeof(struct rec),SEEK_SET);
flag=1; 
fwrite(&s,1,sizeof(struct rec),fp);
}
else 
{ 
fseek(fp,-ret,SEEK_CUR);
fwrite(&s,1,sizeof(struct rec ),fp);
}
}
else 
{
 printf("%d",r.num);
 printf("\nCollision Deleted....!!!!!\n");
 fseek(fp,0,SEEK_CUR);
while(!done) 
{
fread(&r,1,sizeof(struct rec),fp);
if(r.num<1000) 
{
fseek(fp,-4,SEEK_CUR);
fwrite(&s,1,sizeof(struct rec),fp);
done=1;
}
}
}
 printf("\nDo you Wish to Continue?(1/0)\t");
 scanf("%d",&ans);
}
while(ans);
rewind(fp);
printf(" File Contents are \n");
for(i=0;i<MAX;i++)
{
fread(&r,1,sizeof(struct rec),fp);
printf("%d\t",r.num);
}
getch();
}
