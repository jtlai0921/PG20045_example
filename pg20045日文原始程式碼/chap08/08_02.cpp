#include	<iostream.h>

//--- �z��a��x�ȏ�y�ȉ��̗v�f�����ɔz��b�ɃR�s�[���� ---//
int int_rcpy(int a[], int b[], int n, int x, int y)
{
	int	 num = 0;
	for (int i = 0; i < n; i++)
		if (b[i] >= x && b[i] <= y)
			a[num++] = b[i];
	return (num);
}

int main(void)
{
	const int	max = 5;
	int		a[max], b[max];
	int		i, x, y;	

	for (i = 0; i < max; i++) {	
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}
	cout << "�����l�F";		cin >> x;
	cout << "����l�F";		cin >> y; 

	int	 num = int_rcpy(a, b, max, x, y);

	cout << x << "�ȏ�" << y << "�ȉ��̗v�f�F\n";
	for (i = 0; i < num; i++)
		cout << i + 1 << "�ԖځF" << a[i] << '\n';

	return (0);
}

/*
���s��
b[0] = 3��
b[1] = 9��
b[2] = 5��
b[3] = 7��
b[4] = 10��
�����l�F4
����l�F8
4�ȏ�8�ȉ��̗v�f�F
1�ԖځF5
2�ԖځF7
*/
