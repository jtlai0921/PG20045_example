#include	<iostream.h>

//===== ��s�����N���X =====//
class kouza {

public:					//===== ���J�� =====//
	long  number;			// �����ԍ�
	long  yokin;			// �a���z
};

int main(void)
{
	kouza  nozawa = {1234569, 0};		// ���N�̋�s����

	kouza  miyata;						// �{�c�N�̋�s����
	miyata.number = 3468924;
	miyata.yokin  = 10;

	nozawa.yokin += 100;					// ���N��100�~�a����

	miyata.yokin -= 5;					// �{�c�N��5�~�����o��

	cout << "���N�̌���\n";
	cout << "�����ԍ���" << nozawa.number << '\n';
	cout << "�a �� �z��" << nozawa.yokin  << "�~\n\n";

	cout << "�{�c�N�̌���\n";
	cout << "�����ԍ���" << miyata.number << '\n';
	cout << "�a �� �z��" << miyata.yokin  << "�~\n";

	return (0);
}

/*
���s����
���N�̌���
�����ԍ���1234569
�a �� �z��100�~
�{�c�N�̌���
�����ԍ���3468924
�a �� �z��5�~
*/
