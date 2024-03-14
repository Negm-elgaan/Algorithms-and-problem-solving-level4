#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "Lib4.cpp"

using namespace std;
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1=S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}
int GetOverlapDays(Period p1 , Period p2)
{
    Period p3;
    if (Overlap2(p1,p2))
    {
        if (CompareDates(p1.EndDate,p2.EndDate) == After || CompareDates(p1.EndDate,p2.EndDate) == Equal)
        {

            p3.EndDate = p2.EndDate;
            if (CompareDates(p1.StartDate,p2.StartDate) == Before ||  CompareDates(p1.StartDate,p2.StartDate) == Equal)
            {
                p3.StartDate = p2.StartDate ;
                int s = LengthOfPeriod(p3);
                if (s == 0)
                    s++;
                return s;
            }
            else
            {
                p3.StartDate = p1.StartDate ;
                int s = LengthOfPeriod(p3);
                if (s == 0)
                    s++;
                return s;
            }
        }
        else
        {
            p3.EndDate = p1.EndDate;
            if (CompareDates(p1.StartDate,p2.StartDate) == Before ||  CompareDates(p1.StartDate,p2.StartDate) == Equal)
            {
                p3.StartDate = p2.StartDate ;
                int s = LengthOfPeriod(p3);
                if (s == 0)
                    s++;
                return s;
            }
            else
            {
                p3.StartDate = p1.StartDate ;
                int s = LengthOfPeriod(p3);
                if (s == 0)
                    s++;
                return s;
            }
        }
    }
    return -1 ;
}
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
}
stPeriod ReadPeriod1()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}
bool ValidateDate(sDate Date1)
{
    if (Date1.Month > 12 || Date1.Month < 1)
        return false;
    short days = NumberOfDaysInAMonth(Date1.Month,Date1.Year) ;
    if (Date1.Day > 31 || Date1.Day <= 0)
        return false;
    if (Date1.Day > days)
        return false;
    return true;
}
bool IsValidDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day > 31)
        return false;
    if (Date.Month < 1 || Date.Month > 12)
        return false;
    if (Date.Month == 2)
    {
        if (isLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }
    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
        return false;
    return true;
}
vector <string> splitstring(string S1,string Delim)
{
    vector <string> vString ;
    string sWord = "" ;
    short pos = 0 ;
    while ((pos = S1.find(Delim)) != std :: string :: npos)
    {
        sWord =S1.substr(0, pos); // store the word
        if (sWord !="")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }
    if (S1!="")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
sDate StringToDate0(string s1)
{
    vector <string> vString = splitstring(s1,"/");
    sDate date ;
    date.Day = stoi(vString[0]);
    date.Month = stoi(vString[1]);
    date.Year = stoi(vString[2]);
    cout << "Day:" << date.Day << endl;
    cout << "Month:" << date.Month << endl;
    cout << "Year:" << date.Year << endl;
    return date;
}
string DateToString(sDate date)
{
    string DateStringer = "" ;
    DateStringer = to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
    return DateStringer;
}
string DateToString(stDate Date)
{
    return  to_string(Date.Day) +"/"+ to_string(Date.Month) +"/"+ to_string(Date.Year);
}
stDate StringToDate(string DateString)
{
    stDate Date;
    vector <string> vDate;
    vDate = splitstring(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout <<Message;
    getline(cin >> ws, DateString);
    return DateString;
}
void DateFormat(string Datestring = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? "))
{
    string dateformat = Datestring;
    cout << "\n\n" << dateformat << endl;
    vector <string> vString = splitstring(Datestring,"/");
    dateformat = "" ;
    dateformat += vString[2] + "/" + vString[1] + "/" + vString[0] ;
    cout << dateformat << endl;
    dateformat = "" ;
    dateformat += vString[1] + "/" + vString[0] + "/" + vString[2] ;
    cout << dateformat << endl;
    dateformat = "" ;
    dateformat += vString[1] + "-" + vString[0] + "-" + vString[2] ;
    cout << dateformat << endl;
    dateformat = "" ;
    dateformat += vString[0] + "-" + vString[1] + "-" + vString[2] ;
    cout << dateformat << endl;
    dateformat = "" ;
    dateformat += "Day:" + vString[0] + ", " + "Month:" + vString[1] + ", " + "Year:" + vString[2] ;
    cout << dateformat << endl;
}
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return  FormattedDateString;
}
int main()
{
    DateFormat();
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(DateString);
    cout <<"\nDay:"<< Date.Day << endl;
    cout <<"Month:"<< Date.Month << endl;
    cout <<"Year:"<< Date.Year << endl;
    cout <<"\nYou Entered: "<< DateToString(Date) <<"\n";
    string datestring ;
    cin >> datestring;
    sDate date = StringToDate0(datestring);
    if (ValidateDate(date))
        cout << "Yes , date is valid\n";
    else
        cout << "No , date is not valid\n";
    Period p1 = ReadPeriod();
    Period p2 = ReadPeriod();
    auto start = std::chrono::steady_clock::now();
    cout << GetOverlapDays(p1,p2) << endl;
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Execution time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms\n";
    /*cout << "\nEnter Period 1 :";
    stPeriod Period1 = ReadPeriod1();
    cout << "\nEnter Period 2 :";
    stPeriod Period2 = ReadPeriod1();
    auto start = std::chrono::steady_clock::now();
    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Execution time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms\n";*/
    return 0;
}

