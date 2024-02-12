#include <iostream>
#include <string>

using namespace std;
string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return  arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return  arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
}
int readnumber()
{
    int num = 0 ;
    cout << "Enter a number ?";
    cin >> num ;
    return num ;
}
bool checkleapyear(int num)
{
    int century = 100 + (num % 10) + (num % 100) ;
    if (num % 4 == 0 && century != 100)
        return true ;
    if (num % 4 == 0 && century == 100)
        return ((num % 400) == 0) ;
    return false ;
}
bool IsLeapYear(short Year)
{
    // leap year if perfectly divisible by 400
    if (Year % 400 == 0)
    {
        return true;
    }
    // not a leap year if divisible by 100// but not divisible by 400
    else if (Year % 100 == 0)
    {
        return false;
    }
    // leap year if not divisible by 100// but divisible by 4
    else if (Year % 4 == 0)
    {
        return true;
    } // all other years are not leap years
    else
    {
        return false;
    }
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}
// my solution for question 3 is same as Abu-Hadhoud gj :-)
bool CheckLeapYear(int num)
{
    return (num % 400 == 0 || (num % 4 == 0 && num % 100 != 0));
}
int main()
{
    int num = readnumber();
    if(CheckLeapYear(num))
        cout << "Yes , " << num << " is a leap year\n";
    else
        cout << "No , " << num << " isn't a leap year";
    return 0;
}

