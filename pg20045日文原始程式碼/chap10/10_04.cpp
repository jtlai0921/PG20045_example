#include	<string.h>
#include	<iostream.h>

//--- ������str��\�� ---//
void putstring(const char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
}

//--- ������str����납��t���ɕ\�� ---//
void putreverse(const char str[])
{
	for (int i = strlen(str) - 1; i >= 0; i--)
		cout << str[i];
}

int main(void)
{
	char	str[100];

	cout << "���������͂��Ă��������F";
	cin >> str;

	cout << "�ʏ�̕\���F";		putstring(str);		cout << '\n';
	cout << "�t���̕\���F";		putreverse(str);	cout << '\n';

	return (0);
}

/*
���s��
���������͂��Ă��������F12345��
12345
54321
*/

