#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "��������͂��Ă��������F";

	cin >> a;

	int* x = new int(a);

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
���s��
��������͂��Ă��������F8��
*x = 8
*/
