/*
 * Ref:
 * - https://en.cppreference.com/w/cpp/language/types
 */

#include <iostream>

using namespace std;

class CustomClass
{
public:
    void print(string message)
    {
        cout << message << endl;
    }
};

int main()
{
    // Non-primitive data types can contain multiple values of primitive data types

    // string
    string string_dt = "String"; // string value is enclosed by "..."
    cout << string_dt << endl;

    // array
    int array_dt[4] = {0, 1, 2, 3};
    for (int item : array_dt)
    {
        cout << item << " ";
    }
    cout << endl;

    // class
    CustomClass class_dt;
    class_dt.print("Class");

    // struct
    struct
    {
        int id;
        string name;
    } CustomStruct;

    CustomStruct.id = 1;
    CustomStruct.name = "Name";
    cout << CustomStruct.id << " " << CustomStruct.name << endl;

    return 0;
}
