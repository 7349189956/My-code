#include<stdio.h>
#include<string.h>

struct day
{
       char name[20];
       int date;
       char activity[100];
};
   int main()
   {
       struct day calender[7];
       strcpy(calender[0].name,"Monday");
       calender[0].date=1;
       strcpy(calender[0].activity,"Work from 9am to 5pm");
       strcpy(calender[1].name,"Tuesday");
       calender[1].date=2;
       strcpy(calender[1].activity,"Meeting at 10am");
       strcpy(calender[2].name,"Wednesday");
       calender[2].date=3;
       strcpy(calender[2].activity,"Gym at 6pm");
       strcpy(calender[3].name,"Thursday");
       calender[3].date=4;
       strcpy(calender[3].activity,"Dinner with friends at 7pm");
       strcpy(calender[4].name,"Friday");
       calender[4].date=5;
       strcpy(calender[4].activity,"Go to Market");
       strcpy(calender[5].name,"Saturday");
       calender[5].date=6;
       strcpy(calender[5].activity,"Weekend gate way");
       strcpy(calender[6].name,"Sunday");
       calender[6].date=7;
       strcpy(calender[6].activity,"Relax and Recharge");
       
       printf("Calender for the week:\n");
       int i;
       for(i=0;i<7;i++)
        {
           printf("%s Date: %d: %s\n",calender[i].name,calender[i].date,calender[i].activity);
        }
        getch();
        return 0;
    }
       
