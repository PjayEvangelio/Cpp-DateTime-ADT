#include "DateTime.h"
#include <iostream>

using namespace std;

// Additional Prototype for adjusting date/time overflows (hours, days, months)
static void adjustDateTime(DateTime& dt);

// Initialize static members
int DateTime::nextId_ = 1;
int DateTime::count_ = 0;

// Default Constructor
DateTime::DateTime() {
    // Assign unique id and update active count
    id_ = nextId_++;
    count_++;
    cout << "Default Constructor called for object ID " << id_ << endl;

    // Set default date and time
    day_ = 23;
    month_ = 6;
    year_ = 2004;
    hour_ = 21;
    minute_ = 30;

    // Debug output using print()
    this->print();
}

// Copy Constructor
DateTime::DateTime(const DateTime& original) {
    id_ = nextId_++;
    count_++;
    cout << "Copy Constructor called for object ID " << id_
         << " (copying from object ID " << original.id_ << ")" << endl;

    // Copy data members
    this->day_ = original.day_;
    this->month_ = original.month_;
    this->year_ = original.year_;
    this->hour_ = original.hour_;
    this->minute_ = original.minute_;

    this->print();
}

// Copy Assignment Operator
DateTime& DateTime::operator=(const DateTime& that) {
    cout << "Copy Assignment Operator called for object ID " << this->id_
         << " (assigning from object ID " << that.id_ << ")" << endl;
    if (this != &that) {
        this->day_ = that.day_;
        this->month_ = that.month_;
        this->year_ = that.year_;
        this->hour_ = that.hour_;
        this->minute_ = that.minute_;
    }
    return *this;
}

// Explicit Constructor
DateTime::DateTime(int day, int month, int year, int hour, int minute) {
    id_ = nextId_++;
    count_++;
    cout << "Explicit Constructor called for object ID " << id_ << endl;

    this->day_ = day;
    this->month_ = month;
    this->year_ = year;
    this->hour_ = hour;
    // Adjust minutes if greater than or equal to 60
    if (minute >= 60) {
        this->hour_ += minute / 60;
        this->minute_ = minute % 60;
    }
    else {
        this->minute_ = minute;
    }
    
    // Adjust the DateTime object if hours exceed 23 or day/month fields need to be updated.
    adjustDateTime(*this);

    this->print();
}

// Destructor
DateTime::~DateTime() {
    cout << "Destructor called for object ID " << this->id_
         << ". Active objects before destruction: " << count_ << endl;
    count_--;
}

// Additional Helper Function: outputs formatted date and time
void DateTime::print() const {
    cout << "Object ID " << id_ << " - Date: ";

    if (day_ < 10) std::cout << "0";
    cout << day_ << "/";

    if (month_ < 10) std::cout << "0";
    cout << month_ << "/" << year_ << ", Time: ";

    if (hour_ < 10) std::cout << "0";
    cout << hour_ << ":";

    if (minute_ < 10) std::cout << "0";
    cout << minute_ << "\n" << endl;
}

// Additional Helper Function: modifies a DateTime object passed by reference
void modifyDateTime(DateTime& dt) {

    // Method chaining
    dt.setDay(1).setMonth(1).setYear(2020).setHour(0).setMinute(120); // 120 minutes adjusts to add 2 hours
    
    // Adjust the DateTime object after modifying minutes/hours.
    adjustDateTime(dt);
    
    cout << "After modification in modifyDateTime function:" << endl;
    dt.print();
}

// Additional Helper Function: returns a new DateTime object
DateTime createNewDateTime() {
    // 75 minutes will adjust to 1 hour 15 minutes
    DateTime createdDate(31, 12, 2025, 23, 75);
    return createdDate;
}

// Additional Helper Function: handles hour, day, and month overflows, including leap years.
static void adjustDateTime(DateTime& dt) {
    // Adjust hours into days
    while (dt.getHour() >= 24) {
        dt.setHour(dt.getHour() - 24);
        dt.setDay(dt.getDay() + 1);
    }
    
    // Adjust day overflow for month/year
    bool overflow;
    do {
        overflow = false;
        int currentMonth = dt.getMonth();
        int currentYear = dt.getYear();
        int maxDay = 31; // default

        // Determine the maximum days in the current month
        if (currentMonth == 2) {
            // February: check for leap year
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0))
                maxDay = 29;
            else
                maxDay = 28;
        } else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {
            maxDay = 30;
        }

        if (dt.getDay() > maxDay) {
            dt.setDay(dt.getDay() - maxDay);
            dt.setMonth(currentMonth + 1);
            overflow = true;
        }
        
        // Adjust month overflow for year
        if (dt.getMonth() > 12) {
            dt.setMonth(dt.getMonth() - 12);
            dt.setYear(currentYear + 1);
            overflow = true;
        }
    } while (overflow);
}
