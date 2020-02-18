/*
	�J�E���^�N���X�t�@�~���@�|���p��|
									"vcmain.c"
*/

#include    <iostream.h>

#include    "vcounter.h"

//--- 10��C���N�������g���Ȃ���\������ ---//
void count(VCounter& c)
{
	for (int i = 0; i < 10; i++) {
		cout << c.Value() << ' ';
		c.Increment();
	}
}

int main(void)
{
	UnCounter  a;
	BnCounter  b(5);		// ����l��5

	cout << "UnCounter  : ";
	count(a);
	cout << '\n';

	cout << "BnCounter : ";
	count(b);
	cout << '\n';

	return (0);
}

/*
���s����
UnCounter  : 0 1 2 3 4 5 6 7 8 9 10
BnCounter : 0 1 2 3 4 5 5 5 5 5 5
*/
