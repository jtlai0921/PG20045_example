#include	<iostream.h>

int main(void)
{
	int	  asize;
	int	  i;
	int*  a;

	cout << "�v�f������͂��Ă��������F";
	cin >> asize;

	a = new int[asize];

	for (i = 0; i < asize; i++)
		a[i] = i;

	for (i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	delete[] a;

	return (0);
}

/*
���s��
�v�f������͂��Ă��������F5��
a[0] = 0
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 4
*/