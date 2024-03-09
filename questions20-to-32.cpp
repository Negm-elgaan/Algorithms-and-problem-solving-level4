#include <iostream>
#include "Lib.cpp"
using namespace std;
void Add10DaysToDate(sDate &Date)
{
    short daysofmonth = NumberOfDaysInAMonth(Date.Month,Date.Year);
    short remiandertomonth = daysofmonth - Date.Day;
    if(remiandertomonth < 10)
    {
        if(Date.Month == 12)
        {
            Date.Year++;
            Date.Month = 1 ;
        }
        else
            Date.Month++;
        Date.Day -= Date.Day ;
        Date.Day += 10 - remiandertomonth ;

    }
    else
        Date.Day += 10 ;
}
void Add1WeekToDate(sDate &Date)
{
    short daysofmonth = NumberOfDaysInAMonth(Date.Month,Date.Year);
    short remiandertomonth = daysofmonth - Date.Day;
    if(remiandertomonth < 7)
    {
        if(Date.Month == 12)
        {
            Date.Year++;
            Date.Month = 1 ;
        }
        else
            Date.Month++;
        Date.Day -= Date.Day ;
        Date.Day += 7 - remiandertomonth ;

    }
    else
        Date.Day += 7 ;
}
short WeeksToAdd()
{
    short weeks = 0 ;
    cout << "Enter number of weeks you want to add :";
    cin >> weeks;
    cout << endl;
    return weeks;
}
short MonthsToAdd()
{
    short Months = 0 ;
    cout << "Enter number of months you want to add :";
    cin >> Months;
    cout << endl;
    return Months;
}
short YearsToAdd()
{
    short Years = 0 ;
    cout << "Enter number of years you want to add :";
    cin >> Years;
    cout << endl;
    return Years;
}
short DecadesToAdd()
{
    short Decades = 0 ;
    cout << "Enter number of decades you want to add :";
    cin >> Decades;
    cout << endl;
    return Decades;
}
short CenturiesToAdd()
{
    short Centuries = 0 ;
    cout << "Enter number of centuries you want to add :";
    cin >> Centuries;
    cout << endl;
    return Centuries;
}
void AddWeeksToDate(short Week ,sDate &Date1)
{
    while(Week != 0)
    {
        Add1WeekToDate(Date1);
        Week-- ;
    }
}
void IncreaseDateByOneMonth(sDate &Date1)
{
    if(Date1.Month == 12)
    {
        Date1.Month = 1 ;
        Date1.Year++;
    }
    else
        Date1.Month++;
}
void IncreaseDateByMonths(short Months , sDate &Date)
{
    while(Months != 0)
    {
        IncreaseDateByOneMonth(Date);
        Months--;
    }
}
void IncreaseDateByOneYear(sDate &Date)
{
    Date.Year++;
}
void IncreaseDateByYears0(short Years , sDate &Date)
{
    while(Years != 0)
    {
        IncreaseDateByOneYear(Date);
        Years--;
    }
}
void IncreaseDateByYears1(short Years , sDate &Date)
{
    Date.Year += Years ;
}
void IncreaseDateByOneDecade(sDate &Date)
{
    Date.Year += 10;
}
void IncreaseDateByDecades0(short Decades , sDate &Date)
{
    while (Decades != 0)
    {
        IncreaseDateByOneDecade(Date);
        Decades--;
    }
}
void IncreaseDateByDecades1(short Decades , sDate &Date)
{
    Date.Year += (Decades * 10) ;
}
void IncreaseDateByOneCentury(sDate &Date)
{
    Date.Year += 100 ;
}
void IncreaseDateByOneMillennium(sDate &Date)
{
    Date.Year += 1000 ;
}
stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    } //last check day in date should not exceed max days in the current month// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should// be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
stDate IncreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year += Years;
    return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
    //Period of 10years
    Date.Year += 10;
    return Date;
}
stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year += Decade * 10;
    return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{
    //Period of 100 years
    Date.Year += 100;
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date)
{
    //Period of 1000 years
    Date.Year += 1000;
    return Date;
}
int main()
{
    sDate Date1 = ReadDate();
    cout << "Date after :\n\n";
    AddOneDayToDate(Date1);
    cout << "01-Adding 1 day : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    Add10DaysToDate(Date1);
    cout << "02-Adding 10 days : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    Add1WeekToDate(Date1);
    cout << "03-Adding 1 week : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    AddWeeksToDate(10,Date1);
    cout << "04-Adding 10 week : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByOneMonth(Date1);
    cout << "05-Adding 1 month : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByMonths(5,Date1);
    cout << "06-Adding 5 months : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByOneYear(Date1);
    cout << "07-Adding 1 year : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByYears0(10,Date1);
    cout << "08-Adding 10 years : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByYears1(10,Date1);
    cout << "09-Adding 10 years (faster): " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByOneDecade(Date1);
    cout << "10-Adding 1 decade : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByDecades0(10,Date1);
    cout << "11-Adding 10 decades : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByDecades1(10,Date1);
    cout << "12-Adding 10 decades (faster) : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByOneCentury(Date1);
    cout << "13-Adding 1 century : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    IncreaseDateByOneMillennium(Date1);
    cout << "14-Adding 1 millennium : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
    sDate Date2 = ReadDate();
    return 0;
}

