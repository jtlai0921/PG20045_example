#include	<iostream.h>

//--- ����x, y����ꊷ���� ---//
void swap(int& x, int& y)
{
	int	 temp = x;
	x = y;
	y = temp;
}

//--- �R�̈���a, b, c�������ɕ��ׂ� ---//
void sort(int& a, int& b, int& c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main(void)
{
	int		a, b, c;

	cout << "�������̒l����͂��Ă��������F";
	cin >> a;

	cout << "�������̒l����͂��Ă��������F";
	cin >> b;

	cout << "�������̒l����͂��Ă��������F";
	cin >> c;

	sort(a, b, c);

	cout << "������,��,���������ɕ��ъ����܂����B\n";
	cout << "���̒l��" << a << "�ł��B\n";
	cout << "���̒l��" << b << "�ł��B\n";
	cout << "���̒l��" << c << "�ł��B\n";

	return (0);
}

/*
���s��
�������̒l����͂��Ă��������F10��
�������̒l����͂��Ă��������F30��
�������̒l����͂��Ă��������F20��
������,��,���������ɕ��ъ����܂����B
���̒l��10�ł��B
���̒l��20�ł��B
���̒l��30�ł��B
*/
