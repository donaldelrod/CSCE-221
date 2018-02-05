using namespace std;

class Point {
public:
	int x, y;
	Point(int nx, int ny) : x(nx), y(ny) {}
	Point() : x(0), y(0) {}
	void set(int new_x, int new_y) {
		x = new_x;
		y = new_y;
	}
	Point& operator+(const Point new_p) {
		this->x += new_p.x;
		this->y += new_p.y;
	}

	Point& operator=(const Point new_p) {
		this->x = new_p.x;
		this->y = new_p.y;
	}
};