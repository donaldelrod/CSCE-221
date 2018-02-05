#include <iostream>
#include "Stack1.cpp"
#include "Stack2.cpp"
#include "Stack3.cpp"

using namespace std;

int main2345() {
	Stack1<int> a;
	Stack2<int> b;
	Stack3<int> c;
	
	a.push(100);
	b.push(100);
	c.push(100);
	c.push(20);

	for (int i = 0; i < 200; i++) {
		if (i % 5 == 0) {
			a.pop();
			b.pop();
			c.pop();
		}
		else {
			a.push(i);
			b.push(i);
			c.push(i);
			cout << "i = " << i << endl;
		}
		c.print();
	}
	a.push(50);
	b.push(50);
	a.push(19);
	b.push(19);
	cout << "a.pop(): " << a.pop() << endl;


	

	cout << "current size: " << a.csize << "\tmaxsize: " << a.maxsize << endl;
	a.print();


	cout << "current size: " << b.csize << "\tmaxsize: " << b.maxsize << endl;
	b.print();

	cout << "current size: " << c.csize << "\tmaxsize: " << c.maxsize << endl;
	c.print();

	system("pause");
	return 0;
}