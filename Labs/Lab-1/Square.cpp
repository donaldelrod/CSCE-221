#include "Shape.cpp"
#include "Square.h"
#include <iostream>

using namespace std;

class Square : public Shape {
private:
	int len, width;
public:
	Square(int nlen, int nwid) : len(nlen), width(nwid) {}
	void print() {
		cout << "A square at point " << p->x << ", " << p->y;
		cout << " with a lenght of " << len << " and a width of " << width << "." << endl;
	}
};