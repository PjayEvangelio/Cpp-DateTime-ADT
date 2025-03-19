#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H

class DateTime;

class DateTimeHelper
{
public:
    static void adjustDateTime(DateTime& dt);
    static void modifyDateTime(DateTime& dt);
    static DateTime createNewDateTime();
};

#endif // DATETIMEHELPER_H
