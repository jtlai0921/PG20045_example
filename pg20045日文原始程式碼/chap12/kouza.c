//---------------------------------------------------------------------------
-//
//  �J�ݓ��t����s�����N���X Kouza�i�������j				"kouza.c"         
//
//---------------------------------------------------------------------------
-//

#include	"kouza.h"

//--- �R���X�g���N�^ ---//
Kouza::Kouza(long no, long yok, int y, int m, int d) : kaisetsu(y, m, d)
{
	number = no;
	yokin = yok;
}

//--- �����ɂ�����a���� ---//
void Kouza::Ireru(long okane)
{
	yokin += okane;
}

//--- ������������o�� ---//
void Kouza::Orosu(long okane)
{
	yokin -= okane;
}

