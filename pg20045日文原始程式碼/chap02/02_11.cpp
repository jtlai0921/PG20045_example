#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "�����l����͂���F";
	cin >> a;

	switch (a) {
	 case  0: cout << "�O�ł��B\n";    break;
	 default: cout << "��O�ł��B\n";  break;
	}

	return (0);
}

/*
���s��i1�j
�����l����͂���F4��
��O�ł��B
���s��i2�j
�����l����͂���F0��
�O�ł��B
*/
