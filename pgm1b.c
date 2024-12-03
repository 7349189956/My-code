#include<stdio.h>
#include<string.h>
struct Day
{
       char name[20];
       int date;
       char activity[100];
};

void create(struct Day calendar[7])
  {
    int i;
    for(i=0;i<7;i++)
    {
     printf("Enter details for %s:\n",calendar[i].name);
     printf("Date: ");
     scanf("%d",&calendar[i].date);
     sdf("Activity: ");
     scanf("%s",&calendar[i].activity);
    }
   }
void read(struct Day calendar[7])
 {
    FILE*file=fopen("calendar.txt","r");
    if(file==NULL)
      {
         printf("Error opening the file");
         return;
      }
   int i;
   for(i=0;i<7;i++)
      {
        fscanf(file,"%d",&calendar[i].date);
        fscanf(file,"%s",&calendar[i].activity);
      }
   fclose(file);
 }
void display(struct Day calendar[7])
 {
   printf("\nCalendar for the week:\n");
   int i;
   for(i=0;i<7;i++)
   {
    printf("%s Date:%d : %s\n",calendar[i].name,calendar[i].date,calendar[i].activity);
   }
 }
int main()
{
    struct Day calendar[7];
    strcpy(calendar[0].name,"Monday");
    strcpy(calendar[1].name,"Tuesday");
    strcpy(calendar[2].name,"Wednesday");
    strcpy(calendar[3].name,"Thursday");
    strcpy(calendar[4].name,"Friday");
    strcpy(calendar[5].name,"Saturday");
    strcpy(calendar[6].name,"Sunday");
    
    int choice;
    printf("1:Create calendar\n2:Read calendar from file\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
      {
        case 1: create(calendar);
        break;
        case 2: read(calendar);
        break;
        default:
        printf("Invalid choice\n");
      }
   display(calendar);
  getch();
  return 0;
  
}

