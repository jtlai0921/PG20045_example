#include	<iostream.h>

//--- ������src��dst�ɕ��ʂ��� ---//
void strcopy(char dst[], const char src[])
{
    for (int len = 0; dst[len] = src[len]; len++)                            
		;                                                                      
}

int main(void)
{
	char  x[100];
	char  y[100];

	cout << "������x����͂��Ă��������F";
	cin >> x;

	strcopy(y, x);
	cout << "������y��" << y << "�ł��B\n";

	return (0);
}

/*
���s��
������x����͂��Ă��������Fshibata��
������y��shibata�ł��B
*/
