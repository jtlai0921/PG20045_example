#include	<iostream.h>

//--- ������str�̒�����ԋp���� ---//
int strlength(char str[])
{
	int  len = 0;

	while (str[len])                                                          
		len++;                                                                 
	return (len);
}

int main(void)
{
	char  x[6] = "ABCDE";
	char  y[]  = "123";

	cout << "������x (\"" << x << "\")�̒����F" << strlength(x) << '\n';
	cout << "������y (\"" << y << "\")�̒����F" << strlength(y) << '\n';

	return (0);
}

/*
���s����
������x ("ABCDE")�̒����F5
������y ("123")�̒����F3
*/
