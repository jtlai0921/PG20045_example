#include	<iostream.h>

//--- x,y�̑傫�����̒l��ԋp���� ---//
int maxof(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int main(void)
{
	int	 a, b;

	cout << "�����l����͂���F";
	cin >> a;

	cout << "�����l����͂���F";
	cin >> b;

	cout << "�傫������" << maxof(a, b) << "�ł��B\n";

	return (0);
}

/*
���s��
�����l����͂���F10��
�����l����͂���F20��
�傫������20�ł��B
*/
