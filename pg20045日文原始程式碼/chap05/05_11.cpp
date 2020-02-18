#include	<iostream.h>

//--- �v�f��n�̔z��y��z��x�ɋt���ɃR�s�[ ---//
void rcopy(int x[], int y[], int n)
{
	for (int i = 0; i < n; i++)
		x[i] = y[n - i - 1];
}

int main(void)
{
	const int n = 5;
	int	 i;
	int	 a[n] = { 0 };
	int	 b[n] = {1, 2, 3, 4, 5};

	for (i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << " : "
		     << "b[" << i << "] = " << b[i] << '\n';

	rcopy(a, b, n);										// �R�s�[����
	cout << "�z��b�̑S�v�f���t���ɃR�s�[���܂����B\n";

	for (i = 0; i < n; i++)
		cout << "a[" << i << "] = " << a[i] << " : "
		     << "b[" << i << "] = " << b[i] << '\n';

	return (0);
}

/*
���s����
a[0] = 0 : b[0] = 1
a[1] = 0 : b[1] = 2
a[2] = 0 : b[2] = 3
a[3] = 0 : b[3] = 4
a[4] = 0 : b[4] = 5
�z��b�̑S�v�f���t���ɃR�s�[���܂����B
a[0] = 5 : b[0] = 1
a[1] = 4 : b[1] = 2
a[2] = 3 : b[2] = 3
a[3] = 2 : b[3] = 4
a[4] = 1 : b[4] = 5
*/
