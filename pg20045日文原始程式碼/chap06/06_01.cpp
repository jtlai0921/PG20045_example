#include	<iostream.h>

//--- �Q�̐���a,b�̍ŏ��l��ԋp���� ---//
int minof(int a, int b)
{
	return (a < b ? a : b);
}

//--- �R�̐���a,b,c�̍ŏ��l��ԋp���� ---//
int minof(int a, int b, int c)
{
	int	 min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return (min);
}

//--- �v�f�����̔z�񂘂̍ŏ��l��ԋp���� ---//
int minof(int x[], int n)
{
	int	 min = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] < min)
			min = x[i];
	return (min);
}

int main(void)
{
	int	 x, y, z;

	cout << "���̒l����͂��Ă��������F";
	cin >> x;

	cout << "���̒l����͂��Ă��������F";
	cin >> y;

	cout << "���Ƃ��̏��������̒l��" << minof(x, y) << "�ł��B\n\n";

	cout << "���̒l����͂��Ă��������F";
	cin >> z;

	cout << "��,��,���̍ŏ��l��" << minof(x, y, z) << "�ł��B\n\n";

	const int  max = 5;
	int  a[max];

	cout << max << "�̒l����͂��Ă��������F\n";
	for (int i = 0; i < max; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "�z�񂁂̗v�f�̒l�̍ŏ��l��" << minof(a, max) << "�ł��B\n";

	return (0);
}

/*
���s��
���̒l����͂��Ă��������F10��
���̒l����͂��Ă��������F5��
���Ƃ��̏��������̒l��5�ł��B

���̒l����͂��Ă��������F8��
��,��,���̍ŏ��l��5�ł��B

5�̒l����͂��Ă��������F
a[0] = 10��
a[1] = 20��
a[2] = 50��
a[3] = 30��
a[4] = 5��
�z�񂁂̗v�f�̒l�̍ŏ��l��5�ł��B
*/
