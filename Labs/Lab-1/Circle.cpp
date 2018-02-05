#include "Shape.cpp"
#include <iostream>

using namespace std;

class Circle : public Shape {
private:
	int radius;
public:
	Circle(int nr) : radius(nr) {}
	void print() {
		cout << "A circle at point " << p->x << ", " << p->y;
		cout << " with a radius of " << radius << "." << endl;
	}

};