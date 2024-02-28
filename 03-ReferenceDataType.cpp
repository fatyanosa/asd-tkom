/*
 * Ref:
 * - https://www.w3schools.com/cpp/cpp_pointers.asp
 */

#include <iostream>

using namespace std;

int main() {
    // A reference variable is a 'reference' to an existing variable, and it is created with the '&' operator
    string string_dt = "First String";
    string &ref_string_dt = string_dt;  // ref_string_dt is a reference variable of string_dt

    // The "&" operator can also be used to show the memory address of a variable
    // In this example, we can see that both variable has the same address 
    cout << &string_dt << endl;
    cout << &ref_string_dt << endl;
    cout << "-------------------" << endl;

    // Thus, both variables contain identical value
    cout << string_dt << endl;
    cout << ref_string_dt << endl;
    cout << "-------------------" << endl;

    string_dt = "Second String";
    cout << string_dt << endl;
    cout << ref_string_dt << endl;
    cout << "-------------------" << endl;

    ref_string_dt = "Third String";
    cout << string_dt << endl;
    cout << ref_string_dt << endl;

    return 0;
}
