#include	<iostream.h>

//--- year���[�N�ł����1���A�����łȂ����0��ԋp���� ---//
int isleap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main(void)
{
	int	 year;

	cout << "�N�𐼗�œ��͂��ĉ������F";
	cin >> year;

	if (isleap(year))
		cout << year << "�N�͉[�N�ł��B\n";
	else
		cout << year << "�N�͉[�N�ł͂���܂���B\n";

	return (0);
}

/*
���s��i1�j
�N�𐼗�œ��͂��ĉ������F1997��
1997�N�͉[�N�ł͂���܂���B
���s��i2�j
�N�𐼗�œ��͂��ĉ������F1992��
1992�N�͉[�N�ł��B
*/
