#include	<iostream.h>

//===== ��s�����N���X =====//
class kouza {
private:							//===== ���I�� =====// 
	long    number;						// �����ԍ�
	long    yokin;						// �a���z

public:								//===== ���J�� =====//
	kouza(long no, long yok) {			// �R���X�g���N�^
		number = no;
		yokin = yok;
	}
	void ireru(long okane) { yokin += okane; }		// ������a����
	void orosu(long okane) { yokin -= okane; }		// �����������o��
	long kouza_no(void)    { return (number); }		// �����ԍ�
	long yokingaku(void)   { return (yokin); }		// �a���z
};

int main(void)
{
	kouza  nozawa(1234569,  0);	// ���N�̋�s����
	kouza  miyata(3468924, 10);	// �{�c�N�̋�s����

	nozawa.ireru(100);				// ���N��100�~�a����
	miyata.orosu(5);					// �{�c�N��5�~�����o��

	cout << "���N�̌���\n";
	cout << "�����ԍ���" << nozawa.kouza_no()  << '\n';
	cout << "�a �� �z��" << nozawa.yokingaku() << "�~\n\n";

	cout << "�{�c�N�̌���\n";
	cout << "�����ԍ���" << miyata.kouza_no()  << '\n';
	cout << "�a �� �z��" << miyata.yokingaku() << "�~\n";

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
