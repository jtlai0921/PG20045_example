#include	<iostream.h>

int main(void)
{
	int		x   = 100;
	int		y   = 200;
	int*	ptr =  &x;		// ptrはxを指す

	cout << "x：" << x << " (&x：" << &x << "番地)\n";
	cout << "y：" << y << " (&y：" << &y << "番地)\n\n";

	cout << "ptr ← &x\n";
	cout << "ptr ：" <<  ptr << "番地\n";
	cout << "*ptr：" << *ptr << "\n\n";

	ptr = &y;				// ptrはyを指す

	cout << "ptr ← &y\n";
	cout << "ptr ：" <<  ptr << "番地\n";
	cout << "*ptr：" << *ptr << "\n\n";

	*ptr = 300;				// *ptrに300を代入

	cout << "*ptr ← 300\n";
	cout << "ptr ：" <<  ptr << "番地\n";
	cout << "*ptr：" << *ptr << "\n";
	cout << "x：" << x << " (&x：" << &x << "番地)\n";
	cout << "y：" << y << " (&y：" << &y << "番地)\n";

	return (0);
}

/*
実行結果一例
x：100 (&x：500番地)
y：200 (&y：510番地)

ptr ← &x
ptr ：500番地
*ptr：100

ptr ← &y
ptr ：510番地
*ptr：200

*ptr ← 300
ptr ：510番地
*ptr：300
x：100 (&x：500番地)
y：300 (&y：510番地)
*/
