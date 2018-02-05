#pragma once
template <class T, int n>
class Point {
private:
	T data[];
public:
	Point<T, int n>(T d[]);
	T distance(Point a, Point b);
};