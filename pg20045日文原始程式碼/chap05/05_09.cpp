#include	<iostream.h>

//--- �v�f�����̔z�񂘂̍ŏ��l��ԋp���� ---//
int minof(int x[], int n)
{
	int	 min = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] < min) min = x[i];
	return (min);
}

int main(void)
{
	const int  max = 5;						// �z��a�̗v�f��
	int a[max];

	for (int i = 0; i < max; i++) {			// �z��a�ɒl��ǂݍ���
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "�ŏ��l�F" << minof(a, max) << '\n';

	return (0);
}

/*
���s��
a[0] = 10��
a[1] = 12��
a[2] = 100��
a[3] = 95��
a[4] = 82��
�ŏ��l�F10
*/
