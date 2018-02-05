#include "Point.cpp"

using namespace std;

int main() {
	Point stack[10];

	for (Point p : stack) {
		p.print();
	}

	cout << "done with stack" << endl;

	Point* heap = new Point[10];

	for (int i = 0; i < 10; i++) {
		heap[i].print();
	}

	delete []heap;
	system("pause");
}