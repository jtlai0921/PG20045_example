/*
	�z��N���X�e���v���[�g�@�| ���p�� �|
*/

#include	<new.h>
#include	<iomanip.h>
#include	<iostream.h>

#include	"tary.h"

void f(void)
{
	try {
		Ary<int>	x(20);
		Ary<double>	y(10);
		for (int i = 0; i < 10; i++) {
			x[i] = i;
			y[i] = i;
		}
	}
	catch (Ary<int>::RangeErr x) {
		cout << "�Y�����I�[�o�[�t���[<int> : " << x.Index() << '\n';
		return;
	}
	catch (Ary<double>::RangeErr x) {
		cout << "�Y�����I�[�o�[�t���[<double> : " << x.Index() << '\n';
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

	return (0);
}

/*
���s���ʈ��
�֐����͖����I�����܂����B
�֐�������main�֐��֖߂��Ă��܂����B
*/