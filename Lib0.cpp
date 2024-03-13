#include <iostream>
#include <iomanip>


using namespace std;
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month to check? ";
    cin >> Month;
    return Month;
}
bool CheckLeapYear(int num)
{
    return (num % 400 == 0 || (num % 4 == 0 && num % 100 != 0));
}
short numberofdaysinmonthmorethanoneline(short month , int year)
{
    if (month == 2)
        return CheckLeapYear(year) ? 29 : 28 ;
    else if (month == 1 || month  == 3 || month == 8 || month == 5 || month == 7 || month == 10 || month == 12)
        return 31 ;
    return 30 ;
}
short numberofdaysinmonth(short month , int year)
{
    // my solution for question 6 course8 is only 1 line :-)
    return (month == 2) ? CheckLeapYear(year) ? 29 : 28 : (month == 1 || month  == 3 || month == 8 || month == 5 || month == 7 || month == 10 || month == 12) ? 31 : (month < 1 || month > 12) ? 0 : 30 ;
}
short numberofhoursinamonth(short month , int year)
{
    return numberofdaysinmonth(month , year) * 24 ;
}
int numberofminutesinmonth(short month , int year)
{
    return numberofhoursinamonth(month , year) * 60 ;
}
int numberofsecondsinmonth(short month , int year)
{
    return numberofminutesinmonth(month , year) * 60 ;
}
short NumberOfDaysInAYear(short Year)
{
    return  isLeapYear(Year) ? 366 : 365;
}
short NumberOfHoursInAYear(short Year)
{
    return  NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
    return  NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
    return  NumberOfMinutesInAYear(Year) * 60;
}
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return  0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
short NumberOfDaysInAMonth3(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return  0;
    if (Month == 2)
    {
        return  isLeapYear(Year) ? 29 : 28;
    }
    short arr31Days[7] = { 1,3,5,7,8,10,12 };
    for (short i = 1; i <= 7; i++)
        {
            if (arr31Days[i - 1] == Month)
                return 31;
        } //if you reach here then its 30 days.
    return  30;
}
short NumberOfHoursInAMonth(short Month, short Year)
{
    return  NumberOfDaysInAMonth(Month, Year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short Year)
{
    return  NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year)
{
    return  NumberOfMinutesInAMonth(Month, Year) * 60;
}
void days_hours_weeks_seconds(int year)
{
    short DaysInYear = 365 , HoursInYear = DaysInYear * 24 ;
    int MinutesInYear = HoursInYear * 60 , SecondsInYear = MinutesInYear * 60 ;
    if (CheckLeapYear(year))
    {
        cout << "Number of days" << setw(13) << right << " in year [" << year << "] is " << DaysInYear + 1 << endl;
        cout << "Number of hours" << setw(12) << right << " in year [" << year << "] is " << HoursInYear + 24 << endl;
        cout << "Number of minutes" << setw(7) << right << " in year [" << year << "] is " << MinutesInYear + 60 * 24 << endl;
        cout << "Number of seconds" << setw(7) << right << " in year [" << year << "] is " << SecondsInYear + 60 * 24 * 60 << endl;
    }
    else
    {
        cout << "Number of days" << setw(13) << right << " in year [" << year << "] is " << DaysInYear  << endl;
        cout << "Number of hours" << setw(12) << right << " in year [" << year << "] is " << HoursInYear  << endl;
        cout << "Number of minutes" << setw(7) << right << " in year [" << year << "] is " << MinutesInYear << endl;
        cout << "Number of seconds" << setw(7) << right << " in year [" << year << "] is " << SecondsInYear << endl;
    }
}
short ReadDay()
{
    short day = 0 ;
    cout << "\nPlease enter a day to check? ";
    cin >> day ;
    return day ;
}
// my solution for question7
short GetDayOrder(short year , short month , short day)
{
    short a  = (14 - month) / 12 ;
    short y = year - a ;
    short m = month + (a * 12) - 2 ;
    short d = (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12) ) % 7 ;
    return d ;
}
string GetDayName(short DayOrder = GetDayOrder(2003,6,26))
{
    string arr[7] = { "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday"} ;
    return arr[DayOrder];
}
void Date(short year , short month , short day)
{
    short DayOrder = GetDayOrder(year,month,day);
    string DayName = GetDayName(DayOrder);
    cout << "Date" << setw(7) << right << " :" << day << "/" << month << "/" << year << endl;
    cout << "Day order" << setw(2) << right << " :" << DayOrder << endl ;
    cout << "Day name" << setw(3) << right << " :" << DayName << endl;
}
//Abu Hadhoud solution for Question 7
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}
string MonthName(short month = ReadMonth())
{
    string arr[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
    return arr[month - 1] ;
}
void Calender(short month = ReadMonth() , short year = ReadYear())
{
    short days = NumberOfDaysInAMonth(month,year) ;
    string monthname = MonthName(month);
    cout << " _______________" << monthname << "_______________\n\n";
    cout << " Sun" << setw(5) << right << "Mon" << setw(5) << right << "Tue"  << setw(5) << right << "Wed" << setw(5) << right << "Thu" << setw(5) << right << "Fri" << setw(6) << right << "Sat\n";
    for (int i = 1 ; i <= days ; i++)
    {
        short dayofweek = GetDayOrder(year,month,i);
        if (i == 1)
            cout << setw(3) << "" << setw(5 * dayofweek) << right << i ;
        else
            cout << setw(5) << right << i ;
        if (dayofweek == 6)
        {
            cout << endl << setw(4) << right << i + 1 ;
            i++;
        }
    }
}
void YearlyCalender(short year = ReadYear())
{
    cout << " _________________________________\n\n";
    cout << setw(20) <<  right << "Calender - " << year <<endl;
    cout << " _________________________________\n\n";
    for (short i = 1 ; i < 13 ; i++)
    {
        Calender(i,year);
        cout << endl << endl;
    }
}
string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"    };
    return (Months[MonthNumber - 1]);
}
void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays; // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Month, Year);
    // Print the current month name
    printf("\n  _______________%s_______________\n\n",         MonthShortName(Month).c_str());
    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
    printf("\n  _________________________________\n");
}
void PrintYearCalendar(int Year)
{
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf("  _________________________________\n");
    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, Year);
    }
    return;
}
short DaysPassed(short day = ReadDay() , short month = ReadMonth() , short year = ReadYear())
{
    short DaysPasssed = 0 ;
    for (short i = 1 ; i < month ; i++)
        DaysPasssed += NumberOfDaysInAMonth(i,year);
    return DaysPasssed + day ;
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day; return TotalDays;
}



