/*
�_���N���X Boolean�@�| ���p�� �|
*/

#include	<iostream.h>

#include	"boolean.h"

//--- �Q�̐���x, y�����������ǂ��� ---//
Boolean intcmp(int x, int y)
{
	return (x == y);
}

int main(void)
{
	Boolean	a;					// a �� False
	Boolean	b = 100;			// b �� True			b = Boolean(100);
	Boolean	x[8];				// x[0]�`x[7] �� False;
	int		i = 5;

	x[0] = intcmp(i , 5);		// x[0] �� True;
	x[1] = (i != 3);			// x[1] �� True;	x[0] = Boolean(i != 3);
	x[2] = Boolean::False;		// x[2] �� False;
	x[3] = 1000;				// x[3] �� True;	x[3] = Boolean(1000);

	cout << "a�̒l�F" << int(a) << '\n';
	cout << "b�̒l�F" << int(b) << '\n';

	for (i = 0; i < 8; i++)
      		cout << "x[" << i << "] = "<< x[i].String() << '\n';
        return (0);
}

/*
���s����
���̒l�F0
���̒l�F1
x[0] = True
x[1] = True
x[2] = False
x[3] = True
x[4] = False
x[5] = False
x[6] = False
x[7] = False
*/
