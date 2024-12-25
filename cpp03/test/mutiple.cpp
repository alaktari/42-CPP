// multiple inheritence

#include <iostream>
#include <string>

using namespace std;

class X
{
    private:
        int x;
    public:
        X(int x) : x(x) {};
        int get_x(void) { return this->x; }
};

class Y
{
    private:
        int y;
    public:
        Y(int y) : y(y) {};
        int get_y(void) { return this->y; }
};

class Z
{
    private:
        int z;
    public:
        Z(int z) : z(z) {};
        int get_z(void) { return this->z; }
};

class Coordinates : public X, public Y, public Z
{
    public:
        Coordinates(int x, int y, int z) : X(x), Y(y), Z(z) {};
        void display(void)
        { cout << "(x: " << get_x() << ", y: " << get_y() << ", z: " << get_z() << ")"; }
};

int main()
{
    Coordinates point(5, 2, 6);
    point.display();
}