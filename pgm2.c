#include<stdio.h>
#include<string.h>
int main() 
{
 int i=0,j=0,k=0,c=0,m=0,flag=0;
 char str[100],pat[20],rep[20],rstr[100];
 printf("Enter any string:\t");
 gets(str);
 printf("Enter character to replace:\t");
 gets(pat);
 printf("Enter character to replace %s with: \t",pat);
 gets(rep);
 printf("\nString before replacing:\n%s\n",str);
 while(str[i]!='\0')
  {
    if(str[m]==pat[j])
     {
      j++;m++;
      if(pat[j]=='\0')
       {
        flag=1;
        for(k=0;rep[k]!='\0';k++,c++)
        {
         rstr[c]=rep[k];
        }
       i=m;j=0;
       }
     }
    else
    {
     rstr[c]=str[i];
     c++;i++;m=i;j=0;
    }
  }
  rstr[c]='\0';
  if(flag=1)
   {
    printf("String after replacing:\n%s\n",rstr); 
   }
  else
   {
    printf("Not Found"); 
   }
 getch();
}
