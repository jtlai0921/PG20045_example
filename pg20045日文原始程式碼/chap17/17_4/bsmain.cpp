/*
	�J�E���^�N���X�@�|���p��|					"bsmain.c"
*/

#include	<iostream.h>

#include	"bsco.h"

//--- 10��C���N�������g���Ȃ���\������ ---//
void count(BsCounter& c)
{
	for (int i = 0; i < 10; i++) {
		cout << c.Value() << ' ';
		c.Increment();
	}
}

int main(void)
{
	BsCounter   a;
	BndCounter  b(5);						// ����l��5

	cout << "BsCounter  : ";
	count(a);
	cout << '\n';

	cout << "BndCounter : ";
	count(b);
	cout << '\n';

	return (0);
}

/*���s����
BsCounter  : 0 1 2 3 4 5 6 7 8 9 10
BndCounter : 0 1 2 3 4 5 5 5 5 5 5
*/
