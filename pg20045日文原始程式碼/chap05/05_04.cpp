#include	<iostream.h>

//--- ����x, y�̒l����ꊷ���� ---//
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(void)
{
	int a; 
	int b;

	cout << "�������̒l����͂��Ă��������F";
	cin >> a;

	cout << "�������̒l����͂��Ă��������F";
	cin >> b;

	swap(a, b);

	cout << "�������Ƃ��̒l����ꊷ���܂����B\n";
	cout << "���̒l��" << a << "�ł��B\n";
	cout << "���̒l��" << b << "�ł��B\n";

	return (0);
}

/*
���s��
����������͂��Ă��������F10��
����������͂��Ă��������F25��
�������Ƃ��̒l����ꊷ���܂����B
���̒l��25�ł��B
���̒l��10�ł��B
*/
