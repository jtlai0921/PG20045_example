#include	<iostream.h>

int main(void)
{
	int	 a;
	int	 keta = 0;

	cout << "�����l����͂���F";
	cin >> a;

	do {
		a = a / 10;
		keta++;
	} while (a);

	cout << "���̐���" << keta << "���ł��B\n";

	return (0);
}

/*
���s��
�����l����͂���F123��
���̐���3���ł��B
*/