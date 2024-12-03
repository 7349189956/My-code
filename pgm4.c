#include<stdio.h>
#include<string.h>
#include<conio.h>
int F(char symbol)
{
  switch(symbol)
  {
    case'+':
    case'-':return 2;
    case'*':
    case'/':
    case'%':return 4;
    case'^':
    case'$':return 5;
    case'(':return 0;
    case'#':return -1;
    default:return 8;
  }
}
int G(char symbol)
{
  switch(symbol)
  {
    case'+':
    case'-':return 1;
    case'*':
    case'/':
    case'%':return 3;
    case'^':
    case'$':return 6;
    case'(':return 9;
    case')':return 0;
    default:return 7;
  }
}
void infix_postfix(char infix[],char postfix[])
{
  int top=-1,i,j;
  char symbol,S[30];
  S[++top]='#';
  j=0;
  for(i=0;i<strlen(infix);i++)
  {
   symbol=infix[i];
   while(F(S[top])>G(symbol))
    {
      postfix[j++]=S[top--];
    }
   if(F(S[top])!=G(symbol))
    S[++top]=symbol;
   else
    top--;
  }
  while(S[top]!='#')
    {
      postfix[j++]=S[top--];
    }
  postfix[j]='\0';
}

int main()
{
  char infix[20],postfix[20];
  printf("Enter the Infix Expression:\n");
  scanf("%s",infix);
  infix_postfix(infix,postfix);
  printf("The Postfix Expression is \n");
  printf("%s\n",postfix);
  getch();
}
