//----------------------------------------------------------------------------//
//  ���t�N���X Date �i�C���^�t�F�[�X���j					"date.h"          
//
//----------------------------------------------------------------------------//

#include	<iostream.h>

//===== ���t�N���X =====//
class Date {

private:
	int		year;		// ����N
	int		month;		// ��
	int		day;		// ��

public:
	Date(void);									// �f�t�H���g�R���X�g���N�^
	Date(int y, int m = 1, int d =1);			// �R���X�g���N�^

	int Year(void)  const { return (year); }	// �N��ԋp
	int Month(void) const { return (month); }	// ����ԋp
	int Day(void)   const { return (day); }		// ����ԋp
};

ostream& operator<<(ostream& s, Date& x);		// �}�����Z�q

