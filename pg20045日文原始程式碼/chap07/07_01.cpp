#include	<limits.h>
#include	<iostream.h>

int main(void)
{
	cout << "char      : " << CHAR_MIN << "`" << CHAR_MAX << '\n';
	cout << "short int : " << SHRT_MIN << "`" << SHRT_MAX << '\n';
	cout << "int       : " << INT_MIN  << "`" << INT_MAX  << '\n';
	cout << "long int  : " << LONG_MIN << "`" << LONG_MAX << '\n';

	return (0);
}

/*
ŽÀsŒ‹‰Êˆê—á
char      :0`255
short int :-32768`32767
int       :-32768`32767
long int  :-2147483648`2147483647
*/
