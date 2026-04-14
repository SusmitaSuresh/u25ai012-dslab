#include<stdio.h>
int main()
{
    int month, year, lp, k=1;
    int totalDays, noOfDaysYear, noOfDaysMonth = 0;
    int startingDay;
    int daysInTheMonth;

    printf("01/01/0001 was a sunday\n");
    char days[7][4]= {"sun","mon", "tue", "wed", "thu", "fri", "sat"};
    char months[12][10]= {"january", "february", "march", "april", "may", "june", "july", "august", "september", 
                         "october", "november", "december"};
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("enter the date in mm yyyy: ");
    scanf("%d%d", &month, &year);
    if(month>12 || month<0 || year<0)
    {
        printf("invalid input");
        return 0;
    }
    
    lp = (year-1)/4 - (year-1)/100 + (year-1)/400;      //-1 as current year not counted
    noOfDaysYear = (year-1)*365 + lp;
    for(int i=0; i<month-1; i++)
    {
        {
            noOfDaysMonth = noOfDaysMonth + m[i];
        }
    }
    if((month>2) && ((year%4==0 && year%100!=0) || year%400==0))        //feb is month 2, if leap year and month more than 2 then add one extra day
    {    
        noOfDaysMonth = noOfDaysMonth + 1;
    }
    if((month==2)&& ((year%4==0 && year%100!=0) || year%400==0))
    {
        daysInTheMonth = 29;
    }
    else
    {
        daysInTheMonth = m[month-1];
    }

    totalDays = noOfDaysYear + noOfDaysMonth;
    startingDay = totalDays%7;

    printf("calender of %s %d\n",months[month-1], year);

    for(int i=0; i<7; i++)
    {
        printf("%s\t", days[i]);
    }
    printf("\n");
    for(int i=0; i<6 && k<=daysInTheMonth; i++)
    {
        for(int j=0; j<7 && k<=daysInTheMonth; j++)
        {
            if(i==0 && j<startingDay)
            {
                printf(" \t");
            }
            else
            {
                printf("%d\t", k);
                k++;
            }
        }
        printf("\n");
    }
}
// no. of leap years, lp = years-1/4 -years-1/100 + years-1/400
    // no. of days passed by years: (years-lp-1)*365 + lp*366    
    // no. of days passed by months: for(i=0; i<month-1; i++)
                                //      no.ofdays = no.ofdays  + m[i]  ->if its not a leap year (if it is then add one day)
    //total.days = noyear+nomonth;