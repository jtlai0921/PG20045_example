//----------------------------------------------------------------------------//
//	���t�N���X Date ���Z�q�Ł@�C���^�t�F�[�X��				"date.h"          //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== ���t�N���X =====//
class Date {

private:
	int		year;		// ����N
	int		month;		// ��
	int		day;			// ��

	static int Date::mday[12];			// �e���̓��� {31, 28, 31, 30, ��� }
	static int isLeap(int year);				// year�N�͉[�N���H (0 / 1)
	static int Ydays(int year);					// year�N�̓����i365 / 366�j
	static int Mdays(int year, int month);		// year�Nmonth���̓��� (28
�`31)
	static int Dayof(int y, int m, int d);		// ���U����̌o�ߓ���

public:
	Date(void);									// �f�t�H���g�R���X�g���N�^
	Date(int y, int m = 1, int d = 1);			// �R���X�g���N�^

	int Year(void)  const { return (year); }		// �N��Ԃ�
	int Month(void) const { return (month); }		// ����Ԃ�
	int Day(void)   const { return (day); }			// ����Ԃ�

	Date& operator++(void);							// �P���i�߂�
	Date& operator--(void);							// �P�����ǂ�
	Date operator++(int dmy);						// �P���i�߂�
	Date operator--(int dmy);						// �P�����ǂ�
	Date& operator+=(int dn);						// dn���i�߂�
	Date& operator-=(int dn);						// dn�����ǂ�
	friend Date operator+(const Date& date, int dn);		// dn��������߂�
	friend Date operator-(const Date& date, int dn);		// dn���O�����߂�
	friend long operator-(const Date& d1, const Date& d2);	// ���t�̍�����
�߂�
	friend int operator==(const Date& d1, const Date& d2);	// ���������H
	friend int operator!=(const Date& d1, const Date& d2);	// �Ⴄ�����H
	friend int operator>(const Date& d1, const Date& d2);	// d1 �� d2
	friend int operator>=(const Date& d1, const Date& d2);	// d1 �� d2
	friend int operator<(const Date& d1, const Date& d2);	// d1 �� d2
	friend int operator<=(const Date& d1, const Date& d2);	// d1 �� d2
};

ostream& operator<<(ostream&, const Date& x);				// �}�����Z�q

