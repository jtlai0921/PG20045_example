#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "������͂��Ă��������F";
	cin >> month;

	cout << month << "����";

	if (month == 2)
		cout << "28����29���ł��B\n";
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		cout << "30���ł��B\n";
	else
		cout << "31���ł��B\n";

	return (0);
}

/*
���s��i1�j
������͂��Ă��������F2��
2����28����29���ł��B
���s��i2�j
������͂��Ă��������F5��
5����31���ł��B
*/