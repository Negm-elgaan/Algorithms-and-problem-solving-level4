#include <iostream>

using namespace std;
//My solution for questions 33 to 46
sDate DecreaseDateByOneDay(sDate Date = ReadDate())
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12 ;
            Date.Year--;
            Date.Day = 31 ;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month,Date.Year);
        }
        return Date;
    }
    Date.Day--;
    return Date;
}
sDate SubXDaysFromDate(short DaysToSubFrom , sDate Date = ReadDate())
{
    short days = DaysPassed(Date.Day,Date.Month,Date.Year) ;
    if (days < DaysToSubFrom)
    {
        while(days <= DaysToSubFrom)
        {

            Date.Year-- ;
            if(isLeapYear(Date.Year))
                days += 366;
            else
                days += 365;
        }
        days -= DaysToSubFrom;
    }
    else
        days -= DaysToSubFrom;
    Date = GetDateFromDayOrderInYear(days,Date.Year);
    return Date;
}
sDate DecreaseDateByOneWeek(sDate Date)
{
    Date = SubXDaysFromDate(7,Date);
    return Date;
}
sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
    Date = SubXDaysFromDate(Weeks * 7 , Date);
    return Date;
}
sDate DecreaseDateByOneMonth(sDate &Date1)
{
    if(Date1.Month == 1)
    {
        Date1.Month = 12 ;
        Date1.Year--;
    }
    else
        Date1.Month--;
    return Date1;
}
sDate DecreaseDateByMonths(short Months , sDate Date)
{
    while(Months != 0)
    {
        DecreaseDateByOneMonth(Date);
        Months--;
    }
    return Date;
}
sDate DecreaseDateByOneYear(sDate &Date)
{
    Date.Year--;
    return Date;
}
sDate DecreaseDateByYears0(short Years , sDate Date)
{
    while(Years != 0)
    {
        DecreaseDateByOneYear(Date);
        Years--;
    }
    return Date;
}
sDate DecreaseDateByYears1(short Years , sDate Date)
{
    Date.Year -= Years ;
    return Date;
}
sDate DecreaseDateByOneDecade(sDate &Date)
{
    Date.Year -= 10;
    return Date;
}
sDate DecreaseDateByDecades0(short Decades , sDate Date)
{
    while (Decades != 0)
    {
        DecreaseDateByOneDecade(Date);
        Decades--;
    }
    return Date;
}
sDate DecreaseDateByDecades1(short Decades , sDate Date)
{
    Date.Year -= (Decades * 10) ;
    return Date;
}
sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100 ;
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000 ;
    return Date;
}
//Abu Hadhoud solution
stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
        Date.Month--;
        //last check day in date should not exceed max days in the current month
        // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should// be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
stDate DecreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
stDate DecreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}
stDate DecreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year -= Years;
    return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
    //Period of 10 years
    Date.Year -= 10;
    return Date;
}
stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year -= Decade * 10;
    return Date;
}
stDate DecreaseDateByOneCentury(stDate Date)
{
    //Period of 100 years
    Date.Year -= 100;
    return Date;
}
stDate DecreaseDateByOneMillennium(stDate Date)
{
    //Period of 1000 years
    Date.Year -= 1000;
    return Date;
}

