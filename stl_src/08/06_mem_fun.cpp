#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Shape
{
public:
    virtual void display() = 0;
};

class Rect : public Shape
{
public:
    void display() { cout << "Rect" << endl; }
};

class Circle : public Shape
{
public:
    void display() { cout << "Circle" << endl; }
};

class Square : public Shape
{
public:
    void display() { cout << "Square" << endl; }
};

int main()
{
    vector<Shape*> vs;

    vs.push_back(new Rect);
    vs.push_back(new Circle);
    vs.push_back(new Square);
    vs.push_back(new Circle);
    vs.push_back(new Rect);

    for (auto &s : vs)
        s->display();
    cout << endl;

    for_each(vs.begin(), vs.end(), mem_fun(&Shape::display));
    cout << endl;

    for_each(vs.begin(), vs.end(), &Shape::display);
    cout << endl;

    return 0;
}
