#include <iostream>
#include "DateTime.h"
#include "DateTimeHelper.h"
#include "DateTimeLogger.h"

using namespace std;

// Main Function for testing DateTime ADT Functionalities
int main()
{
    {
        cout << "\n========== TEST CASE 1: Default Constructor ==========\n";
        DateTime myBirthday;
        DateTimeLogger::display(myBirthday);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 2: Copy Constructor ==========\n";
        DateTime myBirthday;
        DateTimeLogger::display(myBirthday);
        DateTime yourBirthday(myBirthday);
        DateTimeLogger::display(yourBirthday);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 3: Copy Assignment Operator ==========\n";
        DateTime myBirthday;
        DateTimeLogger::display(myBirthday);
        DateTime yourBirthday(myBirthday);
        DateTimeLogger::display(yourBirthday);
        DateTime randomDate(5, 5, 2005, 8, 45);
        DateTimeLogger::display(randomDate);
        randomDate = yourBirthday;
        cout << "Object updated using Copy Assignment Operator (Copied values from Object ID 5)\n";
        DateTimeLogger::display(randomDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 4: Explicit Constructor ==========\n";
        DateTime explicitDate(6, 3, 2025, 11, 49);
        DateTimeLogger::display(explicitDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 5: Using Setters ==========\n";
        DateTime explicitDate(6, 3, 2025, 11, 49);
        DateTimeLogger::display(explicitDate);
        explicitDate.setDay(16);
        explicitDate.setMonth(12);
        explicitDate.setYear(1999);
        explicitDate.setHour(13);
        explicitDate.setMinute(1);
        cout << "Object values updated using Setters:\n";
        DateTimeLogger::display(explicitDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 6: Heap Allocated Object ==========\n";
        DateTime* heapDate = new DateTime(10, 10, 2010, 10, 80);
        cout << "Heap allocated object:\n";
        DateTimeLogger::display(*heapDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
        delete heapDate;
        cout << "Active objects after delete: " << DateTime::getActiveCount() << endl;
    }

    {
        cout << "\n========== TEST CASE 7: Passing Object to a Function ==========\n";
        DateTime explicitDate(6, 3, 2025, 11, 49);
        DateTimeLogger::display(explicitDate);
        DateTimeHelper::modifyDateTime(explicitDate);
        DateTimeLogger::display(explicitDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 8: Returning Object from a Function ==========\n";
        DateTime returnedDate = DateTimeHelper::createNewDateTime();
        cout << "Returned DateTime object from Function:\n";
        DateTimeLogger::display(returnedDate);
        cout << "Active objects: " << DateTime::getActiveCount() << endl;
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 9: Creating Objects in a Loop ==========\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "\nLoop " << i + 1 << ":\n";
            DateTime loopDate(1 + i, 2 + i, 2025 + i, 9 + i, 5 + i);
            DateTimeLogger::display(loopDate);
            cout << "Active objects: " << DateTime::getActiveCount() << endl;
        }
    }
    cout << "Active objects after block: " << DateTime::getActiveCount() << endl;

    {
        cout << "\n========== TEST CASE 10: Active Object Count ==========\n";
        cout << "Active DateTime objects count: " << DateTime::getActiveCount() << "\n";
    }

    cout << "\n========== PROGRAM END ==========\n";
    return 0;
}
