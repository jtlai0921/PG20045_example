#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "���̐����l����͂���F";
	cin >> a;

	switch (a % 2) {
	 case  0: cout << "�����ł��B\n";  break;
	 default: cout << "��ł��B\n";  break;
	}

	return (0);
}

/*
���s��i1�j
���̐����l����͂���F7��
��ł��B
���s��i2�j
���̐����l����͂���F4��
�����ł��B
*/
