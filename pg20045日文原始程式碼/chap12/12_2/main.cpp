/*
	���W�N���X Position ��Q�� �|���p��P�|					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	const int max = 5;
	Position  a[max];				// Position�̔z���錾

	for (int i = 0; i < max; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
���s����
a[0] = (0, 0)
a[1] = (0, 0)
a[2] = (0, 0)
a[3] = (0, 0)
a[4] = (0, 0)
*/
