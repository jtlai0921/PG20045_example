#include	<string.h>
#include	<iostream.h>

//--- ������str�̒�����ԋp���� ---//
size_t strlength(const char* str)
{
	size_t  len = 0;

	while (*str++)
		len++;
	return (len);
}

int main(void)
{
	char  x[100];

	cout << "���������͂��Ă��������F";
	cin >> x;

	cout << "������" << x << "�̒����F" << strlength(x) << '\n';

	return (0);
}

/*
���s��
���������͂��Ă��������FHello��
������Hello�̒����F5
*/
