#include   <iostream.h>

int main(void)
{
    int	 i = 777;						//----- ���� -----//

    cout.width(7);							// �t�B�[���h����7�ɂ���
    cout.fill('X');							// �t�B��������'X'���w��
    cout << i << '\n';

    cout.fill(' ');
    cout.setf(ios::showpos);				// �����t��
    cout.setf(ios::left, ios::adjustfield);	// ���l��
    cout << i << '\n';
    cout.unsetf(ios::left);					// ���l�߉���
    cout.unsetf(ios::showpos);				// �����t������

    cout.width(7);							// �t�B�[���h����7�ɂ���
    cout.setf(ios::showbase);				// ��t��
    cout.setf(ios::uppercase);				// �啶����\��
    cout.setf(ios::hex, ios::basefield);	// 16�i��
    cout << i << '\n';
    cout.unsetf(ios::showbase);				// ��t������
    cout.unsetf(ios::uppercase);			// �啶����\���̉���

    double  d = 555.0;					//----- ���������_�� -----//

    cout.setf(ios::showpoint);				// �����_�ȉ����o�͂���
    cout << d << '\n';

    cout.precision(5);						// ���������_���̐��x��5��
    cout << d << '\n';
    cout.unsetf(ios::showpoint);			// �����_�ȉ����o�͂��Ȃ�

    cout.setf(ios::scientific, ios::floatfield);	// �w���t��
    cout << d << '\n';

    return (0);
}

/*
���s����
XXXX777
+777
  0X309
555.000
555.00
5.55000e+02
*/
