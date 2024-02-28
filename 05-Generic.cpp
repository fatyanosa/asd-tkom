/*
 * Generics means parameterized types.
 * The idea is to allow data type (Integer, String, … etc., and user-defined types) to be a parameter to methods, classes, and interfaces.
 * Using Generics, it is possible to create classes that work with different data types.
 *
 * Ref:
 * - https://www.geeksforgeeks.org/generics-in-c/
 */

#include <iostream>

using namespace std;

/*
 * A generic type is a generic class or interface that is parameterized over types.
 */
template <typename T> 
class Message {
    public:
        void print(T input) {
            cout << input << endl;
        }
};

/*
* A generic method is a method that introduce their own type parameters.
* This is similar to declaring a generic type, but the type parameter's scope
* is limited to the method where it is declared.
*/
template <typename T> 
void print(T input) {
    cout << input << endl;
}

int main() {
    print("Hello");
    print('C');
    print(9223372036854775807);
    print(1234567e-7f);

    Message<string> string_class;
    string_class.print("Hello");

    Message<char> char_class;
    char_class.print('C');

    Message<long> long_class;
    long_class.print(9223372036854775807);
    
    Message<float> float_class;
    float_class.print(1234567e-7f);

    return 0;
}
