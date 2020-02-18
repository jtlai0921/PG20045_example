/*
	�����z��N���X IntFixedAry �@�| ���p�� �|
*/

//#include	<new.h>
#include	<except.h>
#include	<iomanip.h>
#include	<iostream.h>

#include	"intfixa.h"

void f(void)
{
	try {
		IntFixedAry	x(10);
		for (int i = 0; i < 10; i++)	//�@
			x[i] = i;
	}
	catch (IntFixedAry::RangeErr x) {
		cout << "�Y�����I�[�o�[�t���[ : " << x.Index() << '\n';
		return;
	}
	catch (xalloc) {
		cout << "�������̊m�ۂɎ��s���܂����B\n";
		exit (1);									// �����I��
	}

	cout << "�֐����͖����I�����܂����B\n";
}

void g(void)
{
	try {
		IntFixedAry	x(5);
		IntFixedAry	y(10);	//�A

		x = y;
	}
	catch (IntFixedAry::SizeErr x) {
		cout << "�T�C�Y�G���[         : " << x.Size()  << '\n';
		return;
	}
	catch (xalloc) {
		cout << "�������̊m�ۂɎ��s���܂����B\n";
		exit (1);									// �����I��
	}

	cout << "�֐����͖����I�����܂����B\n";
}

int main(void)
{
	f();
	cout << "�֐�������main�֐��֖߂��Ă��܂����B\n";

	g();
	cout << "�֐�������main�֐��֖߂��Ă��܂����B\n";

	return (0);
}

/*���s���ʈ��
�Y�����I�[�o�[�t���[�F10
�֐�������main�֐��ɖ߂��Ă��܂����B
�T�C�Y�G���[        �F20
�֐�������main�֐��ɖ߂��Ă��܂����B

���s���ʈ��
�֐����͖����I�����܂����B
�֐�������main�֐��ɖ߂��Ă��܂����B
�T�C�Y�G���[        �F20
�֐�������main�֐��ɖ߂��Ă��܂����B

���s���ʈ��
�֐����͖����I�����܂����B
�֐�������main�֐��ɖ߂��Ă��܂����B
�֐����͖����I�����܂����B
�֐�������main�֐��ɖ߂��Ă��܂����B
*/
