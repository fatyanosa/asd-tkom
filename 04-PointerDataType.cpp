/*
 * Ref:
 * - https://www.w3schools.com/cpp/cpp_pointers.asp
 */

#include <iostream>

using namespace std;

int main()
{
    // A pointer is a variable that stores the memory address
    string string_dt = "First String";
    string *ptr_string_dt = &string_dt; // ptr_string_dt is a pointer to string_dt

    // string_dt and ptr_string_dt have their own memory address.
    cout << &string_dt << endl;
    cout << &ptr_string_dt << endl;
    cout << "-------------------" << endl;

    // While string_dt contain a string, ptr_string_dt contains the memory address of string_dt
    cout << string_dt << endl;
    cout << ptr_string_dt << endl;
    cout << "-------------------" << endl;

    // We can display the value of the memory address pointed by ptr_string_dt using '*' operator
    cout << string_dt << endl;
    cout << *ptr_string_dt << endl;
    cout << "-------------------" << endl;

    // Thus, when displaying *ptr_string_dt, the result always identical to string_dt
    string_dt = "Second String";
    cout << string_dt << endl;
    cout << *ptr_string_dt << endl;
    cout << "-------------------" << endl;

    *ptr_string_dt = "Third String";
    cout << string_dt << endl;
    cout << *ptr_string_dt << endl;

    return 0;
}
