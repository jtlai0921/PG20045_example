#include	<iostream.h>

//--- �z��x�̊e�v�f�ɐ擪����0, 1, �c, n-1�����ɑ�� ---//
void fill_num(int* x, int n)
{
	for (int i = 0; i < n; i++)
		x[i] = i;
}

int main(void)
{
	const int  asize = 10;
	int		   a[asize];

	fill_num(a, asize);
	for (int i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
���s����
a[0] = 0
a[1] = 1
a[2] = 2
a[3] = 3
a[4] = 4
a[5] = 5
a[6] = 6
a[7] = 7
a[8] = 8
a[9] = 9
*/
