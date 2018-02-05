#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	void print() {
		cout << x << ", " << y << endl;
	}
	Point() {
		x = 1;
		y = 2;
	}
	Point(int nx, int ny) {
		x = nx;
		y = ny;
	}
	~Point() {
		cout << "destroyed" << endl;
	}
};