//----------------------------------------------------------------------------//
//  ���t�N���X Date ����� Gdate�i�C���^�t�F�[�X���j		"date.h"          //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== ���t�N���X =====//
class Date {

protected:
	int		year;		// ����N
	int		month;		// ��
	int		day;		// ��

public:
	Date(void);								// �f�t�H���g�R���X�g���N�^
	Date(int y, int m = 1, int d = 1);		// �R���X�g���N�^

	int Year(void)	{ return (year); }		// �N��ԋp����
	int Month(void)	{ return (month); }		// ����ԋp����
	int Day(void)	{ return (day); }		// ����ԋp����
};

ostream& operator<<(ostream& s, const Date& x);			// �}�����Z�q

//===== �����œ��t�N���X =====//
class Gdate : public Date {

public:
	enum Geng {Meiji, Taisho, Showa, Heisei};

	Gdate(void) { }

	Gdate(int y) : Date(y) { }

	Gdate(Geng g, int y, int m = 1, int d = 1) : Date(y, m, d)
	{
		switch (g) {
		 case Meiji  : year += 1867;  break;
		 case Taisho : year += 1911;  break;
		 case Showa  : year += 1925;  break;
		 case Heisei : year += 1988;  break;
		}
	}
};

ostream& operator<<(ostream& s, const Gdate& x);		// �}�����Z�q

