#include	<iostream.h>

int main(void)
{
	int	 a, b;

	cout << "�����l������͂���F";
	cin >> a;

	cout << "�����l������͂���F";
	cin >> b;

	cout << "a <  b : " << (a <  b) << '\n';
	cout << "a >  b : " << (a >  b) << '\n';
	cout << "a <= b : " << (a <= b) << '\n';
	cout << "a >= b : " << (a >= b) << '\n';

	return (0);
}

/*
���s��i1�j
�����l������͂���F7��
�����l������͂���F12��
a <  b : 1
a >  b : 0
a <= b : 1
a >= b : 0
���s��i2�j
�����l������͂���F5��
�����l������͂���F5��
a <  b : 0
a >  b : 0
a <= b : 1
a >= b : 1
*/