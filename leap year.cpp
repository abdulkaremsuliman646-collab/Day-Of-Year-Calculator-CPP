#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short ReadDay(short Month, short Year)
{
    short day;
    short maxDays = NumberOfDaysInAMonth(Month, Year);

    do
    {
        cout << "Enter a Day (1 to " << maxDays << "): ";
        cin >> day;

        if (day < 1 || day > maxDays)
        {
            cout << "Invalid day! This month only has " << maxDays << " days. Try again.\n";
        }

    } while (day < 1 || day > maxDays);

    return day;
}

short ReadMonth()
{
    short month;
    cout << "Enter a Month (1-12): ";
    cin >> month;
    return month;
}

short ReadYear()
{
    short year;
    cout << "Enter a Year: ";
    cin >> year;
    return year;
}

short NumberOfDaysFromTheBeginningOfTheYear(short Year, short Month, short Day)
{
    short TotalDays = 0;
    for (short m = 1; m < Month; m++)
    {
        TotalDays += NumberOfDaysInAMonth(m, Year);
    }
    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay(month, year); 

    cout << "\nNumber of Days from the beginning of the year is: "
        << NumberOfDaysFromTheBeginningOfTheYear(year, month, day) << "\n";

    system("pause>0");
    return 0;
}