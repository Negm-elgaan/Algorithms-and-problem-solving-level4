#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}
struct stDate
{
    short Year;
    short Month;
    short Day;
};
struct sDate
{
    short Year;
    short Month;
    short Day;
};
sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.Year = Year;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
int ReadDaysToAdd()
{
    int days = 0 ;
    cout << "\nPlease enter number of days? ";
    cin >> days ;
    return days ;
}
short DaysPassed(short day = ReadDay() , short month = ReadMonth() , short year = ReadYear())
{
    short DaysPasssed = 0 ;
    for (short i = 1 ; i < month ; i++)
        DaysPasssed += NumberOfDaysInAMonth(i,year);
    return DaysPasssed + day ;
}
sDate GetNewDateAfterAddingDays(int days = ReadDaysToAdd() , short day = ReadDay() , short month = ReadMonth() , short year = ReadYear())
{
    sDate date ;
    float remdays = 0 ;
    short yearstoadd = 0 ;
    float remaining = days ;
    while (true)
    {
        if (remaining >= 365.25)
        {
            yearstoadd++ ;
            remaining -= 365.25 ;
        }
        else
        {
            remdays = DaysPassed(day,month,year) + remaining ;
            if (remdays >= 365.25)
            {
                yearstoadd++ ;
                remdays -= 365.25 ;
            }
            if (remdays == 0)
                remdays++;
            break ;
        }
    }
    date = GetDateFromDayOrderInYear(remdays , year + yearstoadd) ;
    return date ;
}
sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
sDate ReadDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
bool CheckDates1(sDate Date1 , sDate Date2)
{
    return (Date2.Year > Date1.Year) || (Date2.Month > Date1.Month && Date2.Year == Date1.Year) || (Date2.Day > Date1.Day && Date2.Month == Date1.Month && Date2.Year == Date1.Year);
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool CheckDateEquailty1(sDate Date1 , sDate Date2)
{
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ;
}
bool CheckDateEquailty2(sDate Date1 , sDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false ;
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsDateLastDayInMonth(sDate date)
{
    short numofdays = NumberOfDaysInAMonth(date.Month,date.Year);
    return date.Day == numofdays;
}
bool IsDateLastMonthInYear(sDate date)
{
    return date.Month == 12;
}
bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}
sDate AddOneDayToDate(sDate &date)
{
    short num = NumberOfDaysInAMonth(date.Month,date.Year);
    if (++date.Day > num)
    {
        date.Day = 1 ;
        date.Month++;
    }
    if(date.Month > 12)
    {
        date.Month = 1 ;
        date.Year++;
    }
    return date;
}
stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1; Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}
int DifferenceBetweenDates(sDate Date1 = ReadDate() , sDate Date2 = ReadDate())
{
    short Date2Days = DaysPassed(Date2.Day , Date2.Month , Date2.Year);
    short rem = 0 ;
    if (Date1.Year == Date2.Year)
    {
        return rem = DaysPassed(Date2.Day , Date2.Month , Date2.Year) - DaysPassed(Date1.Day , Date1.Month , Date1.Year);
    }
    else
    {
        while (Date2.Year-- > Date1.Year)
        {
            if (isLeapYear(Date2.Year))
                rem += 366;
            else
                rem += 365;
        }
        return (rem = rem + Date2Days) - DaysPassed(Date1.Day , Date1.Month , Date1.Year);
    }
}
int DifferenceBetweenDates2(sDate Date1 = ReadDate() , sDate Date2 = ReadDate())
{
    if(CheckDates1(Date1,Date2))
        return DifferenceBetweenDates(Date1,Date2);
    return DifferenceBetweenDates2(Date2,Date1) * -1 ;
}
void  SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;
    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;
    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SawpFlagValue = 1;
    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        //Swap Dates
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }
    while(IsDate1BeforeDate2(Date1, Date2))
    {
         Days++;
         Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}
int GetAgeInDays(sDate Date = ReadDate() , sDate CurrentDate = ReadDate())
{
    int Age = 0 ;
    short days = 0 ;
    if (Date.Year == CurrentDate.Year)
        return Age = DaysPassed(Date.Day , Date.Month , Date.Year) ;
    if (isLeapYear(Date.Year))
        days = 366 - DaysPassed(Date.Day , Date.Month , Date.Year);
    else
        days = 365 - DaysPassed(Date.Day , Date.Month , Date.Year);
    while(Date.Year++ < CurrentDate.Year)
    {
        if (Date.Year == CurrentDate.Year)
        {
            Age += DaysPassed(CurrentDate.Day , CurrentDate.Month , CurrentDate.Year) + days;
            return Age ;
        }
        if (isLeapYear(Date.Year))
            Age += 366;
        else
            Age += 365 ;
    }
    Age += days ;
    return Age ;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}
void nFacRuntimeFunc(int n)
{
  for(int i=0; i<n; i++)
  {
    nFacRuntimeFunc(n-1);
  }
  cout << "done\n";
}


