//---------------------------------------------------------------------- 
// �J�ݓ��t����s�����N���X Kouza�i�C���^�t�F�[�X���j		"kouza.h" 
//

#include	"date.h"

//===== ��s�����N���X =====//
class Kouza {
private:
	long	number;						// �����ԍ�
	long	yokin;						// �a���z
	Date	kaisetsu;					// �J�ݓ�

public:
	Kouza(long no, long yok, int y, int m, int d);		// �R���X�g���N�^

	void Ireru(long okane);								// �����ɂ�����a����
	void Orosu(long okane);								// ������������o��
    
	long KouzaNo(void)      { return (number); }		// �����ԍ�
	long Yokingaku(void)    { return (yokin); }			// �a���z
	Date Kaisetsubi(void)   { return (kaisetsu); }		// �J�ݓ�
};

