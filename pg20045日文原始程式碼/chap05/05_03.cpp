#include	<iostream.h>

//--- ���������_��x��n���ԋp���� ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)				// n��0���傫���ꍇ
		for (int i = 0 ; i < n ; i++)
			a *= x;
	else					// n��0�ȉ��̏ꍇ
		for (int i = 0 ; i > n ; i--)
			a /= x;

	return (a);
}

int main(void)
{
	double	a;
	int		b;

	cout << "�����l����͂���F";
	cin >> a;

	cout << "�����l����͂���F";
	cin >> b;

	cout << a << "��" << b << "���" << power(a, b) << "�ł��B\n";

	return (0); 
}

/*
���s��i1�j
�����l����͂���F3.3��
�����l����͂���F2��
3.3��2���10.89�ł��B

���s��i2�j
�����l����͂���F5.0��
�����l����͂���F-2��
5.0��-2���0.04�ł��B

���s��i3�j
��������͂���F2.5��
�����l����͂���F0��
2.5��0���1�ł��B
*/
