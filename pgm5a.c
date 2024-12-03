#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
double compute(char symbol,double op1,double op2)
{
  switch(symbol)
  {
    case'+':return(op1+op2);
    case'-':return(op1-op2);
    case'*':return(op1*op2);
    case'/':return(op1/op2);
    case'%':return(abs(op1)%abs(op2));
    case'^':return pow(op1,op2);
    return 0;
  }
}

int main()
{
  double S[20];
  double res;
  double op1;
  double op2;
  int top;
  int i;
  char postfix[20];
  char symbol;
  printf("Enter the Postfix Expression: ");
  scanf("%s",postfix);
  top=-1;
  for(i=0;i<strlen(postfix);i++)
   {
   symbol=postfix[i];
   if(isdigit(symbol))
    {
     S[++top]=symbol-'0';
    }
   else
    {
      op2=S[top--];
      op1=S[top--];
      res=compute(symbol,op1,op2);
      S[++top]=res;
    }
   }
  res=S[top--];
  printf("The Result is %f \n",res);
  //return 0;
  getch();
}
