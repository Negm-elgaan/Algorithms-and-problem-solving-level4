#include <iostream>
#include <iomanip>

using namespace std;
int ReadYear()
{
    int Year;
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
    if (Month < 1 || Month>12)
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
int main()
{
    int x = ReadYear() ;
    days_hours_weeks_seconds(x);
    short y = ReadMonth();
    cout << "Number of days" << setw(13) << right << " in month [" << y << "] is " << numberofdaysinmonth(y,x) << endl;
    cout << "Number of hours" << setw(12) << right << " in month [" << y << "] is " << numberofhoursinamonth(y,x)  << endl;
    cout << "Number of minutes" << setw(7) << right << " in month [" << y << "] is " << numberofminutesinmonth(y,x) << endl;
    cout << "Number of seconds" << setw(7) << right << " in month [" << y << "] is " << numberofsecondsinmonth(y,x) << endl;
    return 0;
}

