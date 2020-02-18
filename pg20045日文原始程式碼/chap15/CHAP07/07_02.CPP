#include	<limits.h>
#include	<iostream.h>

int main(void)
{
	cout << "char      : " << hex << CHAR_MIN << "`" << hex << CHAR_MAX << '\n';
	cout << "short int : " << hex << SHRT_MIN << "`" << hex << SHRT_MAX << '\n';
	cout << "int       : " << hex << INT_MIN  << "`" << hex << INT_MAX  << '\n';
	cout << "long int  : " << hex << LONG_MIN << "`" << hex << LONG_MAX << '\n';

	return (0);
}

/*
ŽÀsŒ‹‰Êˆê—á
char      : 0`ff
short int : 8000`7fff
int       : 8000`7fff
long      : 80000000`7fffffff
*/
