#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "������͂��ĉ������F";
	cin >> month;

	switch (month) {
	 case  2: cout << month << "����28����29���ł��B\n";
	          break;
	 case  4:
	 case  6:
	 case  9:
	 case 11: cout << month << "����30���ł��B\n";
	          break;
	 case  1:
	 case  3:
	 case  5:
	 case  7:
	 case  8:
	 case 10:
	 case 12: cout << month << "����31���ł��B\n";
	          break;
	 default: cout << month << "���Ȃ�āA����܂����B\n";
	          break;	
	}

	return (0);
}

/*
���s��i1�j
������͂��Ă��������F5��
5����31���ł��B
���s��i2�j
������͂��Ă��������F15��
15���Ȃ�āA����܂����B
*/