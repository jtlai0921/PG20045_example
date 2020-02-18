/*
	複素数クラス Complex　－ 利用例 －
*/

#include	<iostream.h>

#include	"complex.h"

int main(void)
{
	Complex  a(1.0);
	Complex  b(2.0, 3.0);
	Complex  c = -a + b;

	b += 2.0;
	c -= 1.0;
	Complex  d(Imag(c), Real(c));

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	cout << "c = " << c << '\n';
	cout << "d = " << d << '\n';

	return (0);
}

/*
実行結果
a = (1,0)
b = (4,3)
c = (0,3)
d = (3,0)
*/

