//---------------------------------------------------------------------------
-//
//	���t�N���X Date �i�C���^�t�F�[�X���j					"date.h"          
//
//---------------------------------------------------------------------------
-//

#include	<iostream.h>

//===== ���t�N���X =====//
class Date {
	// ��� (����) ���
public:
	// ��� (����) ���
	int CompY(int y) const { return (y - year);  }	// �N�Ƃ̍���ԋp����
	int CompM(int m) const { return (m - month); }	// ���Ƃ̍���ԋp����
	int CompD(int d) const { return (d - day);   }	// ���Ƃ̍���ԋp����
};

