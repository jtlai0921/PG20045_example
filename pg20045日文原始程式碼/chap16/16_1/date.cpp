//----------------------------------------------------------------------------//
//  ���t�N���X Date ����� Gdate�i�������j					"date.c"          //
//----------------------------------------------------------------------------//


#include	<time.h>

#include	"date.h"

//--- �y�N���XDate�z�R���X�g���N�^ ---//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//--- �y�N���XDate�z�f�t�H���g�R���X�g���N�^ ---//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);							// ���݂̎������擾
	local = localtime(&current);			// �\���̂ɕϊ�
	year  = local->tm_year + 1900;			// �N�Ftm_year�͔N-1900�@
	month = local->tm_mon + 1;				// ���Ftm_mon��0�`11
	day   = local->tm_mday;
}

//--- �y�N���XDate�zostream�ւ̑}�� ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return (s << x.Year() << "�N" << x.Month() << "��" << x.Day() << "��");
}

//--- �y�N���XGdate�zostream�ւ̑}�� ---//
ostream& operator<<(ostream& s, const Gdate& x)
{
	unsigned long idate = x.Year()*10000UL + x.Month()*100UL + x.Day();

	if (idate < 18680908UL)
		s << x.Year();
	else if (idate < 19120730UL)
		s << "����" << x.Year() - 1867;
	else if (idate < 19261225UL)
		s << "�吳" << x.Year() - 1911;
	else if (idate < 19890108UL)
		s << "���a" << x.Year() - 1925;
	else
		s << "����" << x.Year() - 1988;
	return (s << "�N" << x.Month() << "��" << x.Day() << "��");
}

