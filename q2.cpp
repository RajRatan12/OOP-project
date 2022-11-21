//Create a class named anyShape with data member as a width , height of float type and make Constructors and appropriate access modifier then list and draw Base class  and Derived class named as Rectangle , Triangle , Elipse , Square , Circle and  then also show polymorphism with multiple inheritance and implementing abstract class and interface then put the user’s data into a file and display a data from a file 
#include <iostream>
#include <fstream>
using namespace std;
class anyShape
{ 
protected:
    float width;   
    float height; 
public:
    anyShape(float w, float h)
    {
        width = w;
        height = h;
    }
    anyShape(int w, int h)
    {
        width = float(w);
        height = float(h);
    }
    virtual float getArea() = 0; 
};
class Rectangle : public anyShape
{

public:
    Rectangle(float w, float h) : anyShape(w, h)
    {
    }
    Rectangle(int w, int h) : anyShape(w, h)
    {
    }
    float getArea()
    {
        return width * height;
    }
};

class Triangle : public anyShape
{

public:
    Triangle(float w, float h) : anyShape(w, h)
    {
    }
    Triangle(int w, int h) : anyShape(w, h)
    {
    }
    float getArea()
    {
        return 0.5 * width * height;
    }
};
class Elipse : public anyShape
{
public:
    Elipse(float w, float h) : anyShape(w, h)
    {
    }
    Elipse(int w, int h) : anyShape(w, h)
    {
    }
    float getArea()
    {
        return 3.14 * (width / 2) * (height / 2);
    }
};

class Square : public Rectangle
{
public:
    Square(float side) : Rectangle(side, side)
    {
    }
    Square(int side) : Rectangle(side, side)
    {
    }
    float getArea()
    {
        return width * height;
    }
};

class Circle : public Elipse
{
public:
    Circle(float rad) : Elipse(rad * 2, rad * 2)
    {
    }
    Circle(int rad) : Elipse(rad * 2, rad * 2)
    {
    }
    float getArea()
    {
        return 3.14 * width / 2;
    }
};

int main()
{
    Triangle(2, 4);
    Circle c1(6);
    Square sq1(7);

    char path[] = "anyshapes.txt";
    
    ofstream myfile;
    myfile.open(path, ios::app);
    myfile.write((char *)&sq1, sizeof(sq1));
    
    ifstream fileR;
    fileR.open(path, ios::in);
    Square obj(0);
    fileR.read((char *)&obj, sizeof(obj));
    cout << " Area of the written-read Square is " << obj.getArea();
    return 0;
}