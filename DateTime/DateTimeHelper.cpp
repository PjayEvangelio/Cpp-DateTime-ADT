#include <iostream>
#include "DateTime.h"
#include "DateTimeHelper.h"

using namespace std;

// Helper Function: handles hour, day, and month overflows, including leap years.
void DateTimeHelper::adjustDateTime(DateTime& dt)
{
    while (dt.getMinute() >= 60)
    {
        dt.setMinute(dt.getMinute() - 60);
        dt.setHour(dt.getHour() + 1);
    }

    while (dt.getHour() >= 24)
    {
        dt.setHour(dt.getHour() - 24);
        dt.setDay(dt.getDay() + 1);
    }

    while (true)
    {
        bool adjusted = false;
        int currentMonth = dt.getMonth();
        int currentYear = dt.getYear();
        int maxDay = 31;

        if (currentMonth == 2)
        {
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0))
                maxDay = 29;
            else
                maxDay = 28;
        }
        else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11)
        {
            maxDay = 30;
        }

        if (dt.getDay() > maxDay)
        {
            dt.setDay(dt.getDay() - maxDay);
            dt.setMonth(currentMonth + 1);
            adjusted = true;
        }

        if (dt.getMonth() > 12)
        {
            dt.setMonth(dt.getMonth() - 12);
            dt.setYear(currentYear + 1);
            adjusted = true;
        }

        if (!adjusted)
            break;
    }
}

// Helper Function: modifies a DateTime object passed by reference
void DateTimeHelper::modifyDateTime(DateTime& dt)
{
    dt.setDay(1);
    dt.setMonth(1);
    dt.setYear(2020);
    dt.setHour(0);
    dt.setMinute(120);
    adjustDateTime(dt);

    cout << "Object values modified by a Function:\n";
}

// Helper Function: returns a new DateTime object
DateTime DateTimeHelper::createNewDateTime()
{
    DateTime createdDate(31, 12, 2025, 23, 75);
    return createdDate;
}
