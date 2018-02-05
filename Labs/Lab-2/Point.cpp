#include "Point.h"
template <class T, int n>
T Point<T, int n>::distance(Point a, Point b) {
	T total;
	for (i = 0; i < n; i++) {
		T temp = (a.data[i] - b.data[i])^2;
		total = i == 0 ? temp : total + temp;
	}
	total = total ^ (0.5);

	return total;
}

template<class T>
Point<T, int n>::Point(T[] d) {
	data = d;
}