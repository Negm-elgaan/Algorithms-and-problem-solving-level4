#include <iostream>
#include "Lib1.cpp"
#include "Lib2.cpp"
#include "Lib3.cpp"

using namespace std;
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short NumberOfDaysInAYear(short Year)
{
    return  isLeapYear(Year) ? 366 : 365;
}
short DayOfWeekOrder(sDate Date = ReadDate())
{
    short a, y, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string GetDayName(short DayOrder)
{
    string arr[7] = { "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday"} ;
    return arr[DayOrder];
}
bool IsEndOfWeek0(sDate date)
{
    if (DayOfWeekOrder(date) == 6)
        return true ;
    return false ;
}
bool IsEndOfWeek1(sDate date)
{
    return (DayOfWeekOrder(date) == 6) ? true : false ;
}
bool IsWeekend0(sDate date)
{
    if (DayOfWeekOrder(date) == 5 || DayOfWeekOrder(date) == 6)
        return true ;
    return false ;
}
bool IsWeekend1(sDate date)
{
    return (DayOfWeekOrder(date) == 5) ? true : DayOfWeekOrder(date) == 6 ? true : false ;
}
bool IsBusinessDay(sDate date)
{
    if (!IsWeekend0(date))
        return true ;
    return false ;
}
short DaysUntilEndofWeek(sDate date)
{
    return 6 - DayOfWeekOrder(date);
}
short DaysUntilEndOfMonth(sDate date)
{
    return NumberOfDaysInAMonth(date.Month , date.Year) - (date.Day - 1) ;
}
short DaysUntilEndOfYear(sDate date)
{
    return NumberOfDaysInAYear(date.Year) - (DaysPassed(date.Day , date.Month , date.Year) - 1);
}
sDate GetSystemDate1()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}
short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}
short IsEndOfWeek(stDate Date)
{
    return  DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(stDate Date)
{ //Weekends are Fri and Sat
    short DayIndex = DayOfWeekOrder(Date);
    return  (DayIndex == 5 || DayIndex == 6);
}
bool IsBusinessDay(stDate Date)
{
    //Weekends are Sun,Mon,Tue,Wed and Thur
    /*
    short DayIndex = DayOfWeekOrder(Date);
    return  (DayIndex >= 5 && DayIndex <= 4);
    */

    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(stDate Date1)
{
    stDate EndOfMontDate;
    EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
    EndOfMontDate.Month = Date1.Month;
    EndOfMontDate.Year = Date1.Year;
    return GetDifferenceInDays(Date1, EndOfMontDate, true);
}
short DaysUntilTheEndOfYear(stDate Date1)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date1.Year;
    return GetDifferenceInDays(Date1, EndOfYearDate, true);
}
short Vacation(stDate Datefrom , stDate Dateto)
{
    short vacationdays = 0 ;
    while (!IsDate1EqualDate2(Datefrom,Dateto))
    {
        if (IsBusinessDay(Datefrom))
            vacationdays++;
        IncreaseDateByOneDay(Datefrom);
    }
    return vacationdays;
}
short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}
stDate ReturnDate(short VacationDays , stDate start)
{
    while (VacationDays != 0)
    {
        if(IsBusinessDay(start))
            VacationDays--;
        IncreaseDateByOneDay(start);
    }
    return start;
}
stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{

    short WeekEndCounter = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //here we increase the vacation dates to add all weekends to it.

    for (short i = 1; i <= VacationDays+ WeekEndCounter; i++)
    {

        if (IsWeekEnd(DateFrom))
            WeekEndCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //in case the return date is week end keep adding one day util you reach business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}
short ReadVacationDays()
{
    short Days;
    cout << "\nPlease enter vacation days? ";
    cin >> Days;
    return Days;
}
bool IsDate1AfterDate2F(sDate Date1 , sDate Date2)
{
    return Date1.Year > Date2.Year ? true : Date1.Year == Date2.Year ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day > Date2.Day ? true : false) : false)) : false ;
}
bool IsDate1AfterDate2S(stDate Date1 , stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1,Date2));
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
short compare(stDate Date1 , stDate Date2)
{
    if (IsDate1BeforeDate2(Date1,Date2))
        return -1 ;
    if (IsDate1EqualDate2(Date1,Date2))
        return 0 ;
    return 1 ;
}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    /*  if (IsDate1AfterDate2(Date1,Date2))
            return enDateCompare::After;*/
            //this is faster
    return enDateCompare::After;
}
// my solution for question 58 course 8
struct Period
{
    stDate StartDate ;
    stDate EndDate ;
};
Period ReadPeriod()
{
    Period P1 ;
    cout << "Enter start date:\n\n";
    P1.StartDate = ReadFullDate();
    cout << "Enter end date:\n\n";
    P1.EndDate = ReadFullDate();
    return P1;
}
bool Overlap(Period P1 , Period P2)
{
    return !IsDate1BeforeDate2(P1.EndDate , P2.StartDate) ? true : !IsDate1BeforeDate2(P2.EndDate,P1.StartDate) && (IsDate1BeforeDate2(P2.StartDate,P1.EndDate) || IsDate1EqualDate2(P2.StartDate,P1.EndDate) )? true : false;
}
bool Overlap2(Period P1 , Period P2)
{
    return !IsDate1BeforeDate2(P1.EndDate , P2.StartDate) ? true : (IsDate1BeforeDate2(P2.StartDate,P1.EndDate))? true : false;
}
// Abu Hadhoud solution for question 58 course 8
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before     ||  CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}
//
short LengthOfPeriod(Period p1 , bool GetEndDay = false)
{
    return GetDifferenceInDays(p1.StartDate , p1.EndDate , GetEndDay);
}
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}
//if ((CompareDates(p1.StartDate,date1) == Before || CompareDates(p1.StartDate , date1) == Equal ) && (CompareDates(p1.EndDate,date1) == After || CompareDates(p1.EndDate,date1) == Equal));
bool CheckIfDateIsInPeriod(Period p1 = ReadPeriod() , stDate date1 = ReadFullDate())
{
    return  (IsDate1BeforeDate2(date1,p1.EndDate) || IsDate1EqualDate2(date1 , p1.EndDate)) && (IsDate1BeforeDate2(p1.StartDate,date1) || IsDate1EqualDate2(p1.StartDate,date1));
}
bool IsDateInPeriod(Period p1 = ReadPeriod() , stDate date1 = ReadFullDate())
{
    return (CompareDates(date1,p1.StartDate) == After && CompareDates(date1,p1.EndDate) == Before ) || CompareDates(date1,p1.StartDate) == Equal || CompareDates(date1,p1.EndDate) == Equal;
}
bool isDateInPeriod(stDate Date, stPeriod Period) 
{ 
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before    ||    CompareDates(Date, Period.EndDate) == enDateCompare::After); 
}
int main()
{
    cout << IsDateInPeriod() << endl;
    cout << CheckIfDateIsInPeriod() <<endl;
    Period p1 = ReadPeriod();
    cout << "Period length is:" << LengthOfPeriod(p1) << endl;
    cout << "Period length is (with end day):" << LengthOfPeriod(p1,true) << endl;
    Period p2 = ReadPeriod();
    if (Overlap2(p1,p2))
        cout << "Yes periods overlap\n";
    else
        cout << "No periods don't overlap\n";
    stDate DateFrom = ReadFullDate();
    stDate DateTO = ReadFullDate();
    //cout << "Vacation starts:\n";

    cout << "Compare result = "<< compare(DateFrom,DateTO) << endl;
    sDate Date1 = ReadDate();
    sDate Date2 = ReadDate();
    cout << IsDate1AfterDate2F(Date1,Date2) << endl;

    cout << IsDate1AfterDate2S(DateFrom,DateTO) << endl;
    stDate dateto = CalculateVacationReturnDate(DateFrom,13);
    cout << "Vacation ends: " << GetDayName(DayOfWeekOrder(dateto)) << " , " << dateto.Day << "/" << dateto.Month << "/" << dateto.Year << endl;
    stDate Dateto = ReturnDate(13,DateFrom);
    cout << "Vacation ends: " << GetDayName(DayOfWeekOrder(Dateto)) << " , " << Dateto.Day << "/" << Dateto.Month << "/" << Dateto.Year << endl;
    cout <<"\nVacation ends:\n";
    stDate DateTo = ReadFullDate();
    cout << "Vacation from: " << GetDayName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << "Vacation ends: " << GetDayName(DayOfWeekOrder(DateTo)) << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;
    cout << "\n\n\nActual vacation days is :" << Vacation(DateFrom,DateTo);
    /*sDate Date = GetSystemDate1();
    cout << DayOfWeekOrder(Date) << " " << DayOfWeekOrder(Date.Day,Date.Month,Date.Year) << endl;
    cout << "Today is " << GetDayName(DayOfWeekOrder(Date))<< " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    cout << "Is it end of week ?\n";
    if (IsEndOfWeek0(Date))
        cout << "Yes it is end of week\n\n";
    else
        cout << "No it isn't end of week\n\n";
    cout << "Is it weekend?\n";
    if (IsWeekend0(Date))
        cout << "Yes it is weekend\n\n";
    else
        cout << "No it is not weekend\n\n";
    cout << "Is it a business day?\n";
    if (IsBusinessDay(Date))
        cout << "Yes it is a business day\n\n";
    else
        cout << "No it is not a business day\n\n";
    cout << "Days until end of week(including today) :" << DaysUntilEndofWeek(Date) << endl ;
    cout << "Days until end of month(including today) :" << DaysUntilEndOfMonth(Date) << endl ;
    cout << "Days until end of year(including today) :" << DaysUntilEndOfYear(Date) << endl;*/
    return 0;
}

