#include "Shape.cpp"
#include "Circle.cpp"
#include "Square.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	Square* sq = new Square(5, 1);
	Circle* cir = new Circle(5);

	sq->print();
	cir->print();
}