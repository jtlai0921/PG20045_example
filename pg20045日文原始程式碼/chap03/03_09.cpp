#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 a[10];

	for (i = 0; i < 10; i++)	// �擪���珇��1, 2, �c������
		a[i] = i + 1;

	for (i = 0; i < 10; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
���s��
a[0] = 1
a[1] = 2
    �F
 �y�����z
    �F
a[9] = 10
*/
