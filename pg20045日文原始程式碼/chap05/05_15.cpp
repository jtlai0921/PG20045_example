#include	<iostream.h>

//--- �قȂ邎���炒�����o���g�ݍ��킹�̐���ԋp���� ---//
int combination(int n, int r)
{
	if (r == 0 || r == n)
		return (1);
	else if (r == 1)
		return (n);
	return (combination(n - 1, r - 1) + combination(n - 1, r));
}

int main(void)
{
	int		n, r;

	cout << "�����l������͂���F"; cin >> n;
	cout << "�����l������͂���F"; cin >> r;

	cout << "combination(" << n << ',' << r << ")= " << combination(n, r) << '\n';

	return (0);
}

/*
���s��
�����l������͂���F5��
�����l������͂���F3��
combination(5,3)= 10
*/
