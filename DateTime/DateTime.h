#ifndef DATETIME_H
#define DATETIME_H

class DateTime {
public:
    // Default Constructor
    DateTime();

    // Copy Constructor
    DateTime(const DateTime& original);

    // Copy Assignment Operator
    DateTime& operator=(const DateTime& that);

    // Explicit Constructor
    DateTime(int day, int month, int year, int hour, int minute);

    // Destructor
    ~DateTime();

    // Getters (Implicit Inline Functions)
    int getDay() const { return day_; }
    int getMonth() const { return month_; }
    int getYear() const { return year_; }
    int getHour() const { return hour_; }
    int getMinute() const { return minute_; }
    int getId() const { return id_; }

    // Setters with simple time-adjustment for minutes (Implicit Inline Functions & Method Chaining)
    DateTime& setDay(int newDay) { this->day_ = newDay; return *this; }
    DateTime& setMonth(int newMonth) { this->month_ = newMonth; return *this; }
    DateTime& setYear(int newYear) { this->year_ = newYear; return *this; }
    DateTime& setHour(int newHour) { this->hour_ = newHour; return *this; }
    DateTime& setMinute(int newMinute) {
        this->hour_ += newMinute / 60;
        this->minute_ = newMinute % 60;
        return *this; 
    }

    // Additional member function to print DateTime in formatted style
    void print() const;

    // Static member function to return the count of active DateTime objects (Inline Function)
    static int getActiveCount() { return count_; }


protected:


private:
    // Date variables
    int day_;
    int month_;
    int year_;

    // Time variables
    int hour_;
    int minute_;

    // Unique identifier for each DateTime object
    int id_;

    // Static members (belong to class, not individual instances) to generate unique ids and track active objects
    static int nextId_;
    static int count_;
};

// Function Protoypes for non-member helper functions
void modifyDateTime(DateTime& dt);
DateTime createNewDateTime();

#endif
