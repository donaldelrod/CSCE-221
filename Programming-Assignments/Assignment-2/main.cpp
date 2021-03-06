#include <stdio.h>
#include "Deque.h"



void main ( void )
{
	Deque<int> intQ;

	printf ( "isEmpty(1): %d\n", intQ.isEmpty ( ) ? 1 : 0 );
	intQ.insertFirst (4);
	printf ( "removeLast(4): %d\n", intQ.removeLast ( ) );
	intQ.insertFirst ( 5 );
	intQ.insertFirst ( 12 );
	intQ.insertLast ( 7 );
	intQ.insertLast ( 13 );
	printf ( "first(12): %d\n", intQ.first ( ) );
	printf ( "last(13): %d\n", intQ.last() );
	printf ( "size(4): %d\n", intQ.size() );
	printf ( "isEmpty(0): %d\n", intQ.isEmpty ( ) ? 1 : 0 );
	printf ( "removeLast(13) :%d\n", intQ.removeLast ( ) );
	printf ( "removeLast(7) :%d\n", intQ.removeLast ( ) );
	printf ( "removeLast(5) :%d\n", intQ.removeLast ( ) );
	printf ( "removeFirst(12) :%d\n", intQ.removeFirst ( ) );
	printf ( "size(0): %d\n", intQ.size ( ) );
	printf ( "isEmpty(1): %d\n", intQ.isEmpty ( ) ? 1 : 0 );

	cout << endl << endl;

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 1) 
			intQ.insertFirst(i);
		else 
			intQ.insertLast(i);
		intQ.print();
	}
	try {
		for (int i = 0; i < 22; i++) {
			if (i % 2 == 1)
				intQ.removeLast();
			else
				intQ.removeFirst();
			intQ.print();
		}
	}
	catch (DequeException de) {
		cout << de << endl;
	}

	system("pause");
}