#include	<iostream.h>

//--- x,y�̕��ϒl��ԋp���� ---//
double aveof(int x, int y)
{
	return (double(x + y) / 2);
}

int main(void)
{
	int	 a, b;

	cout << "�����l����͂���F";
	cin >> a;

	cout << "�����l����͂���F";
	cin >> b;

	cout << "���ϒl��" << aveof(a, b) << "�ł��B\n";

	return (0);
}

/*
���s��
�����l����͂���F10��
�����l����͂���F29��
���ϒl��19.5�ł��B
*/
