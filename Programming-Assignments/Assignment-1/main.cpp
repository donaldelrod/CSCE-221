#include "StopWatch.h"
#include <stdio.h>
#include "Stack1.cpp"
#include "Stack2.cpp"
#include "Stack3.cpp"

int fib ( int i )
{
	if ( i == 1 )
		return 1;
	if ( i <= 0 )
		return 0;
	return fib ( i - 1 ) + fib ( i - 2 );
}

void main ( void )
{
	StopWatch t;
	Stack3<int> a;
	t.start ( );
	for (int i = 0; i < 100000; i++) {
		a.push(i);
		if (i % 10000 == 0)
			printf("%f ms\n", t.ms());
	}
	t.stop ( );

	printf ( "Took %f milliseconds\n", t.ms ( ) );

	system("pause");
}