#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "������͂��Ă��������F";
	cin >> month;

	if (month >= 3 && month <= 5)
		cout << month << "���͏t�ł��B\n";
	else if (month >= 6 && month <= 8)
		cout << month << "���͉Ăł��B\n";
	else if (month >= 9 && month <= 11)
		cout << month << "���͏H�ł��B\n";
	else
		cout << month << "���͓~�ł��B\n";

	return (0);
}

/*
���s��
������͂��Ă��������F3��
3���͏t�ł��B
*/
