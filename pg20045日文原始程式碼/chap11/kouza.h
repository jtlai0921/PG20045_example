//---------------------------------------------------------------------//
//  ��s�����N���X kouza�i�C���^�t�F�[�X���j				"kouza.h"
//
//--------------------------------------------------------------------//

//===== ��s�����N���X =====//
class kouza {

private:							//===== ���I�� =====//
	long	number;						// �����ԍ�
	long	yokin;						// �a���z

public:								//===== ���J�� =====//
	kouza(long no, long yok);			// �R���X�g���N�^

	void ireru(long okane);				// �����ɂ�����a����

	void orosu(long okane);				// ������������o��

	long kouza_no(void) {				// �����ԍ�
		return (number);
	}

	long yokingaku(void) {				// �a���z
		return (yokin);
	}
};
