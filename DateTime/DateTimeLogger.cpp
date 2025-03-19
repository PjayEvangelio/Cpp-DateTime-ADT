#include <iostream>
#include "DateTime.h"
#include "DateTimeLogger.h"

// Helper Function: displays DateTime objects in formatted style
void DateTimeLogger::display(const DateTime& dt)
{
    // Ternary operators used for leading zeros logic
    std::cout << "Object ID " << dt.getId() << " - Date: ";
    std::cout << (dt.getDay() < 10 ? "0" : "") << dt.getDay() << "/";
    std::cout << (dt.getMonth() < 10 ? "0" : "") << dt.getMonth() << "/" << dt.getYear() << ", Time: ";
    std::cout << (dt.getHour() < 10 ? "0" : "") << dt.getHour() << ":";
    std::cout << (dt.getMinute() < 10 ? "0" : "") << dt.getMinute() << std::endl;
}
