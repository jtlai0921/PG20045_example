#include	<iostream.h>

//--- �v�f�����̔z�񂘂̒�����l�������������A���̓Y������ԋp ---//
int search(int x[], int n, int k)
{
	for (int i = 0; i < n; i++)
		if (x[i] == k)
			return (i);
	return (-1);
}

int main(void)
{
	const int n = 5;
	int a, x[n];

	cout << "�z�񂘂̊e�v�f�̒l����͂���F\n";
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "] = ";
		cin >> x[i];
	}
	cout << "�T���������l����͂���F";
	cin >> a;

	int pos = search(x, n, a);
	if (pos == -1)
		cout << "���̐��͔z�񂘒��ɂ���܂���B\n";
	else
		cout << "���̐���x[" << pos << "]�Ɠ������ł��B\n";

	return (0);
}

/*
���s��
�z�񂘂̊e�v�f�̒l����͂���F
x[0] = 10��
x[1] = 50��
x[2] = 60��
x[3] = 25��
x[4] = 50��
�T���������l����͂���F50
���̐���x[1]�Ɠ������ł��B
*/
