#include	<iostream.h>

//--- ����x, y�̍ő���񐔂�ԋp���� ---//
int gcd(int x, int y)
{
	int	 a = (x > y) ? x : y;
	int	 b = (x > y) ? y : x;

	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}

int main(void)
{
	int	 x, y;

	cout << "�����l������͂���F";
	cin >> x;

	cout << "�����l������͂���F";
	cin >> y;

	cout << x << "��" << y << "�̍ő���񐔂�" << gcd(x, y) << "�ł��B\n";

	return (0);
}

/*
���s��
�����l������͂���F22��
�����l������͂���F8��
22��6�̍ő���񐔂�2�ł��B
*/
