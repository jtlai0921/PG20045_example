#include	<iostream.h>

//--- n�̊K������߂� ---//
int factorial(int n)
{
	if (n != 0)
		return (n * factorial(n-1));
	return (1);
}

int main(void)
{
	int x;

	cout << "����������͂���F";
	cin >> x;

	cout << "���̊K���" << factorial(x) << "�ł��B\n";

	return (0);
}

/*
���s��i1�j
����������͂���F5��
���̊K���120�ł��B

���s��i2�j
����������͂���F0��
���̊K���1�ł��B
*/
