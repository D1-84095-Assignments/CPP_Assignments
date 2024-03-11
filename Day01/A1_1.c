#include<stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};

int menu();
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);

int main()
{
struct Date d1;
int choice;
while((choice=menu())!=0)
{
    switch(choice)
    {
        case 1: initDate(&d1);
                break;
        case 2: printDateOnConsole(&d1);
                break;
        case 3: acceptDateFromConsole(&d1);
                break;
        default:printf("Invalid choice");
    }
}
        return 0;
}
int menu()
{
    int choice;
    printf("Enter your choice.\n");
    printf("0.Exit\n1.Initialise Date\n2.Print Date on console\n3.Accept Date on console\n");
    scanf("%d",&choice);
    return choice;
}
void initDate(struct Date* ptrDate)
{
    ptrDate->day=1;
    ptrDate->month=1;
    ptrDate->year=2001;
}
void printDateOnConsole(struct Date* ptrDate)
{
    printf("Date is: %d-%d-%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}
void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter day, month and year.");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
}


