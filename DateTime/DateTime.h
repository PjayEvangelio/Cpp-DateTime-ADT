#ifndef DATETIME_H
#define DATETIME_H

class DateTime
{
public:
    DateTime();
    DateTime(const DateTime& original);
    DateTime& operator=(const DateTime& that);
    DateTime(int day, int month, int year, int hour, int minute);
    ~DateTime();

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;
    int getId() const;

    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setHour(int newHour);
    void setMinute(int newMinute);

    static int getActiveCount();

private:
    int _day;
    int _month;
    int _year;
    int _hour;
    int _minute;
    int _id;

    static int _nextId;
    static int _count;
};

#endif // DATETIME_H
