#include	<iostream.h>

int main(void)
{
	int*  x = new int;

	cout << "��������͂��Ă��������F";

	cin >> *x;

	cout << "*x = " << *x << '\n';

	delete x;

	return (0);
}

/*
���s��
��������͂��Ă��������F5��
*x = 5
*/
