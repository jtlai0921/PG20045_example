#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "���̐����l����͂���F";
	cin >> a;

	while (a >= 0) {
		cout << a << ' ';				// �����o��
		a--;								// �����f�N�������g
	}
	cout << '\n';						// ���s����

	return (0);
}

/*
���s��
���̐����l����͂���F5��
5 4 3 2 1 0
*/