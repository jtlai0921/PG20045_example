//---------------------------------------------------------------------//
//  ��s�����N���X kouza�i�������j							"kouza.c"     
//
//---------------------------------------------------------------------//

#include	"kouza.h"

kouza::kouza(long no, long yok) {		// �R���X�g���N�^
	number = no;
	yokin = yok;
}

void kouza::ireru(long okane) {			// �����ɂ�����a����
	yokin += okane;
}

void kouza::orosu(long okane) {			// ������������o��
	yokin -= okane;
}

