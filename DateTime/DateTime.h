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
    void setDay(int newDay);

    int getMonth() const;
    void setMonth(int newMonth);

    int getYear() const;
    void setYear(int newYear);

    int getHour() const;
    void setHour(int newHour);

    int getMinute() const;
    void setMinute(int newMinute);

    int getId() const;

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
