#include "DateTime.h"
#include <iostream>

using namespace std;

// Main function - Testing functionalities of DateTime Abstract Data Structure
int main() {
    // Test 1 - Default Constructor Test
    cout << "\n========== TEST CASE 1: Default Constructor ==========\n";
    DateTime myBirthday;

    // Test 2 - Copy Constructor Test
    cout << "\n========== TEST CASE 2: Copy Constructor ==========\n";
    DateTime yourBirthday(myBirthday);

    // Test 3 - Copy Assignment Operator Test
    cout << "\n========== TEST CASE 3: Copy Assignment Operator ==========\n";
    DateTime randomDate(5, 5, 2005, 8, 45);
    randomDate = yourBirthday;
    cout << "After Copy Assignment Operator:\n";
    randomDate.print();

    // Test 4 - Explicit Constructor Test
    cout << "\n========== TEST CASE 4: Explicit Constructor ==========\n";
    DateTime explicitDate(6, 3, 2025, 11, 49);

    // Test 5 - Using Setters to override values (Method Chaining)
    cout << "\n========== TEST CASE 5: Using Setters (Method Chaining) ==========\n";
    explicitDate.setDay(16).setMonth(12).setYear(1999).setHour(13).setMinute(1);
    cout << "After overriding values of object ID 4 using setters:\n";
    explicitDate.print();

    // Test 6 - Creating an object on the heap
    cout << "\n========== TEST CASE 6: Heap Allocated Object ==========\n";
    DateTime* heapDate = new DateTime(10, 10, 2010, 10, 80); // 80 minutes adjusts to 11:20 instead of 10:80
    cout << "Heap allocated object:\n";
    heapDate->print();
    delete heapDate;  // Destructor called for heap object

    // Test 7 - Passing object by reference to a function
    cout << "\n========== TEST CASE 7: Passing Object to a Function ==========\n";
    modifyDateTime(explicitDate);

    // Test 8 - Returning an object from a function
    cout << "\n========== TEST CASE 8: Returning Object from a Function ==========\n";
    DateTime returnedDate = createNewDateTime();
    cout << "Returned DateTime object from function:\n";
    returnedDate.print();

    // Test 9 - Creating objects in a loop
    cout << "\n========== TEST CASE 9: Creating Objects in a Loop ==========\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nLoop " << i + 1 << ":\n";
        DateTime loopDate(1 + i, 2 + i, 2025 + i, 9 + i, 5 + i);
    }

    // Test 10 - Display count of active DateTime objects using static member function
    cout << "\n========== TEST CASE 10: Active Object Count ==========\n";
    cout << "Active DateTime objects count: " << DateTime::getActiveCount() << "\n";

    cout << "\n========== PROGRAM END - Objects Being Destroyed ==========\n";

    return  0;
}
