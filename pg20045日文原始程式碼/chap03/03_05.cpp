#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "�����l����͂���F";
	cin >> a;

	int	 pow2 = a * a;					// �Q��l
	int	 pow4 = pow2 * pow2;			// �S��l

	cout << a << "�̂Q���" << pow2 << "�ł��B\n";		// �Q���\��
	cout << a << "�̂S���" << pow4 << "�ł��B\n";		// �S���\��

	return (0);
}

/*
���s��
���̐����l����͂���F3��
3�̂Q���9�ł��B
3�̂S���81�ł��B
*/