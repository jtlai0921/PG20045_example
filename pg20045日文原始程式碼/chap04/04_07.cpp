#include	<iostream.h>
#include	<iomanip.h>

int main(void)
{
	int	 a, base;

	do {														// ��ǂݍ���
		cout << "���i���ł̓��͂ł����i�W/10/16�j�F";
		cin >> dec >> base;
	} while (base != 8 && base != 10 && base != 16);

	cout << "�����l����͂��Ă��������F";
	cin >> setbase(base) >> a;								// �����l����

	do {														// ��ǂݍ���
		cout << "���i���ŕ\�����܂����i�W/10/16�j�F";
		cin >> dec >> base;
	} while (base != 8 && base != 10 && base != 16);

	cout << setbase(base) << a << '\n';					// �����l�o��

	return (0);
}

/*
���s����
���i���ł̓��͂ł����i�W/10/16�j�F16��
�����l����͂��Ă��������Fff
���i���ŕ\�����܂����i�W/10/16�j�F10��
255
*/
