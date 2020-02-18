//---------------------------------------------------------------------------
-//
//  ���t�N���X Date �i�������j								"date.c"          
//
//---------------------------------------------------------------------------
-//

#include	<time.h>

#include	"date.h"

//--- �N���XDate�̃f�t�H���g�R���X�g���N�^ ---//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);						// ���݂̎������擾
	local = localtime(&current);		// �\���̂ɕϊ�
	year  = local->tm_year + 1900;		// �N�Ftm_year�͔N-1900�@
	month = local->tm_mon + 1;			// ���Ftm_mon��0�`11
	day   = local->tm_mday;
}

//--- �N���XDate�̃R���X�g���N�^ ---//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//--- �o�̓X�g���[��s��x��}�� ---//
ostream& operator<<(ostream& s, Date& x)
{
	return (s << x.Year() << "�N" << x.Month() << "��" << x.Day() << "��");
}

