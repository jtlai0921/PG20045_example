#include	<iostream.h>

int main(void)
{
	int		x   = 100;
	int		y   = 200;
	int*	ptr =  &x;		// ptr��x���w��

	cout << "x�F" << x << " (&x�F" << &x << "�Ԓn)\n";
	cout << "y�F" << y << " (&y�F" << &y << "�Ԓn)\n\n";

	cout << "ptr �� &x\n";
	cout << "ptr �F" <<  ptr << "�Ԓn\n";
	cout << "*ptr�F" << *ptr << "\n\n";

	ptr = &y;				// ptr��y���w��

	cout << "ptr �� &y\n";
	cout << "ptr �F" <<  ptr << "�Ԓn\n";
	cout << "*ptr�F" << *ptr << "\n\n";

	*ptr = 300;				// *ptr��300����

	cout << "*ptr �� 300\n";
	cout << "ptr �F" <<  ptr << "�Ԓn\n";
	cout << "*ptr�F" << *ptr << "\n";
	cout << "x�F" << x << " (&x�F" << &x << "�Ԓn)\n";
	cout << "y�F" << y << " (&y�F" << &y << "�Ԓn)\n";

	return (0);
}

/*
���s���ʈ��
x�F100 (&x�F500�Ԓn)
y�F200 (&y�F510�Ԓn)

ptr �� &x
ptr �F500�Ԓn
*ptr�F100

ptr �� &y
ptr �F510�Ԓn
*ptr�F200

*ptr �� 300
ptr �F510�Ԓn
*ptr�F300
x�F100 (&x�F500�Ԓn)
y�F300 (&y�F510�Ԓn)
*/
