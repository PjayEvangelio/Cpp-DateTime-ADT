#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H

#include "DateTime.h"

class DateTimeHelper
{
public:
    static void adjustDateTime(DateTime& dt);
    static void modifyDateTime(DateTime& dt);
    static DateTime createNewDateTime();
};

#endif // DATETIMEHELPER_H
