#include "Point.cpp"
using namespace std;

class Shape {
protected:
	Point p;
public:
	Shape() {
		p = new Point();
	}
	Shape(int nx, int ny) {
		p = new Point(nx, ny);
	}
	virtual void print() = 0;
};
