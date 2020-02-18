#include	<iostream.h>

//--- �v�f��n�̔z��y��z��x�ɃR�s�[ ---//
void icopy(int x[], int y[], int n)
{
	for (int i = 0; i < n; i++)
		x[i] = y[i];
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

	icopy(a, b, n);										// �R�s�[���s��

	cout << "�z��b�̑S�v�f���R�s�[���܂����B\n";

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
�z��b�̑S�v�f���R�s�[���܂����B
a[0] = 1 : b[0] = 1
a[1] = 2 : b[1] = 2
a[2] = 3 : b[2] = 3
a[3] = 4 : b[3] = 4
a[4] = 5 : b[4] = 5
*/
