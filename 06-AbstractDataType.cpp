/*
 * Abstract Data type (ADT) is a type (or class) for objects whose behavior is
 * defined by a set of values and a set of operations. The definition of ADT only mentions
 * what operations are to be performed but not how these operations will be implemented.
 *
 * Ref:
 * - https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
 */

#include <iostream>

using namespace std;

/*
 * The Abstract Data Type of a Plane
 */
class Plane
{
public:
    virtual double area() = 0;
    virtual double circumference() = 0;
};

/*
 * The Classes that implements the Abstract Data Type of a Plane
 */
class Square : public Plane
{
private:
    double side;

public:
    Square(double side)
    {
        this->side = side;
    }

    double area()
    {
        return this->side * this->side;
    }

    double circumference()
    {
        return this->side * 4;
    }
};

class Rectangle : public Plane
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
    {
        this->width = width;
        this->height = height;
    }

    double area()
    {
        return this->width * this->height;
    }

    double circumference()
    {
        return (this->width + this->height) * 2;
    }
};

int main()
{
    Square square(5);
    cout << square.area() << endl;
    cout << square.circumference() << endl;

    Rectangle rectangle(10, 5);
    cout << rectangle.area() << endl;
    cout << rectangle.circumference() << endl;

    return 0;
}
