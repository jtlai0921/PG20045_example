#include	<iostream.h>

int main(void)
{
	char c;
	int	 ccount = 0;		// ������
	int	 ncount = 0;		// ���s��

	while (cin.get(c)) {
		ccount++;
		if (c == '\n')
			ncount++;
	}
	cout << "��������" << ccount << '\n';
	cout << "���s����" << ncount << '\n';

	return (0);
}

/*
���s��
Are you ready?��
Yes, OK!��
Ctrl+Z
��������24
���s����2
*/