#include "DateTime.h"
#include "DateTimeHelper.h"

// Initialize static members
int DateTime::_nextId = 1;
int DateTime::_count = 0;

// Default Constructor creates a DateTime object with pre-defined values
DateTime::DateTime()
{
    _day = 23;
    _month = 6;
    _year = 2004;
    _hour = 21;
    _minute = 30;
    _id = _nextId++;
    _count++;
}

// Copy Constructor creates a DateTime object by copying an existing object
DateTime::DateTime(const DateTime& original)
{
    _day = original._day;
    _month = original._month;
    _year = original._year;
    _hour = original._hour;
    _minute = original._minute;
    _id = _nextId++;
    _count++;
}

// Copy Assignment Operator overrides values of an existing DateTime object by copying values from another object
DateTime& DateTime::operator=(const DateTime& that)
{
    if (this != &that)
    {
        _day = that._day;
        _month = that._month;
        _year = that._year;
        _hour = that._hour;
        _minute = that._minute;
    }
    return *this;
}

// Explicit Constructor creates a DateTime object with user-defined values
DateTime::DateTime(int day, int month, int year, int hour, int minute)
{
    _day = day;
    _month = month;
    _year = year;
    _hour = hour;
    _minute = minute;
    _id = _nextId++;
    _count++;

    DateTimeHelper::adjustDateTime(*this);
}

// Destructor destroys a DateTime object
DateTime::~DateTime()
{
    _count--;
}

// Getters for accessing private variables
int DateTime::getDay() const
{
    return _day;
}

int DateTime::getMonth() const
{
    return _month;
}

int DateTime::getYear() const
{
    return _year;
}

int DateTime::getHour() const
{
    return _hour;
}

int DateTime::getMinute() const
{
    return _minute;
}

int DateTime::getId() const
{
    return _id;
}

int DateTime::getActiveCount()
{
    return _count;
}

// Setters for setting values of private variables
void DateTime::setDay(int newDay)
{
    _day = newDay;
}

void DateTime::setMonth(int newMonth)
{
    _month = newMonth;
}

void DateTime::setYear(int newYear)
{
    _year = newYear;
}

void DateTime::setHour(int newHour)
{
    _hour = newHour;
}

void DateTime::setMinute(int newMinute)
{
    _minute = newMinute;
}
