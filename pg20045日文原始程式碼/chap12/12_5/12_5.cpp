/*
	�N���XCar	�|���p��|								"main.c"
*/

#include	<iostream.h>

#include	"car.h"

int main(void)
{
	Car		benz(90.0, 0.0, 0.0);
	char	cont;	// �����𑱍s���邩

	while (1) {
		cout << benz;

		cout << "aaa";
		cin >> cont;

		if (cont == 'N' || cont == 'n') break;

		double  dx, dy;
		cout << "bbb";	cin >> dx;
		cout << "ccc";	cin >> dy;

		if (!benz.Move(dx, dy))
			cout << "dddddd\n";
	}

	return (0);
}

/*
���s��
���ݒn(0,0)�^�c��R��90���b�g��
�ړ����܂����H�i�x�^�m�jy��
�������̈ړ������F30.0��
�������̈ړ������F40.0��
���ݒn(30,40)�^�c��R��40���b�g��
�ړ����܂����H�i�x�^�m�jy��
�������̈ړ������F-20.0��
�������̈ړ������F15.0��
���ݒn(10,55)�^�c��R��15���b�g��
�ړ����܂����H�i�x�^�m�jy��
�������̈ړ������F0��
�������̈ړ������F-12.5��
���ݒn(10,42.5)�^�c��R��2.5���b�g��
�ړ����܂����H�i�x�^�m�jy��
�������̈ړ������F10.0��
�������̈ړ������F-25.5��
�ړ��ł��܂���B
���ݒn(10,42.5)�^�c��R��2.5���b�g��
�ړ����܂����H�i�x�^�m�jn��
*/
