//----------------------------------------------------------------------------//
//	���t�N���X Date ���Z�q�Ł@������						"date.c"		  //
//----------------------------------------------------------------------------//


#include	<time.h>

#include	"date.h"

//--- �e���̓��� ---//
int Date::mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//--- year�N�͉[�N���H (0�����[�N / 1����[�N) ---//
int Date::isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

//--- year�N�̓��� (365�����[�N / 366����[�N) ---//
int Date::Ydays(int year)
{
	return (365 + isLeap(year));
}

//--- year�Nmonth���̓��� (28�`31) ---//
int Date::Mdays(int year, int month)
{
	if (month-- != 2)						// month���Q���łȂ��Ƃ�
		return (mday[month]);
	return (mday[month] + isLeap(year));	// month���Q���ł���Ƃ�
}

//--- ���U����̌o�ߓ��� ---//
int Date::Dayof(int year, int month, int day)
{
	for (int m = 1; m < month; m++)
		day += Mdays(year, m);
	return (day);
}

//----- �N���XDate�̃R���X�g���N�^ -----//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//----- �N���XDate�̃f�t�H���g�R���X�g���N�^ -----//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);						// ���ݎ������擾
	local = localtime(&current);		// �\���̂ɕϊ�
	year  = local->tm_year + 1900;		// �N�Ftm_year�͔N-1900
	month = local->tm_mon + 1;			// ���Ftm_mon��0�`11
	day   = local->tm_mday;
}

//--- ���t��dn���i�߂� ( Date += int ) ---//
Date& Date::operator+=(int dn)
{
	if (dn < 0) return ((*this) -= -dn);

	day += dn;
	while (day > Mdays(year, month)) {
		day -= Mdays(year, month);
		if (++month > 12) {
			year++;
			month = 1;
		}
	}

	return (*this);
}

//--- ���t��dn���O�����߂� ( Date -= int ) ---//
Date& Date::operator-=(int dn)
{
	if (dn < 0)  return ((*this) += -dn);

	day -= dn;
	while (day < 1) {
		if (--month < 1) {
			year--;
			month = 12;
		}
		day += Mdays(year, month);
	}

	return (*this);
}

//--- date��dn��������߂� ( Date + int ) ---//
Date operator+(const Date& date, int dn)
{
	Date temp = date;
	return (temp += dn);
}

//--- date��dn���O�����߂� ( Date - int ) ---//
Date operator-(const Date& date, int dn)
{
	Date temp = date;
	return (temp -= dn);
}

//--- ���t�̍� d1 - d2 �����߂� ( Date - Date ) ---//
long operator-(const Date& d1, const Date& d2)
{
	long count = 0;
	long count1 = Date::Dayof(d1.year, d1.month, d1.day);
	long count2 = Date::Dayof(d2.year, d2.month, d2.day);

	if (d1.year == d2.year)
		count = count1 - count2;
	else if (d1.year > d2.year) {
		count = Date::Ydays(d2.year) - count2 + count1;
		for (int y = d2.year + 1; y < d1.year; y++)
			count += Date::Ydays(y);
	} else {
		count = -(Date::Ydays(d1.year) - count1 + count2);
		for (int y = d1.year + 1; y < d2.year; y++)
			count -= Date::Ydays(y);
	}

	return (count);
}

//--- �P���i�߂� ( ++Date ) ---//
Date& Date::operator++(void)
{
	if (day < Mdays(year, month))
		day++;
	else { 
		if (++month >=  12) {
			year++;
			month = 1;
		}
		day = 1;
	}

	return (*this);
}

//--- �P���i�߂� ( Date++ ) ---//
Date Date::operator++(int n)
{
	Date temp = *this;
	++(*this);
	return (temp);
}

//--- �P�����ǂ� ( --Date ) ---//
Date& Date::operator--(void)
{
	if (day >= 2)
		day--;
	else {
		if (--month <=1) {
			year--;
			month = 12;
		}
		day = Mdays(year, month);
	}

	return (*this);
}

//--- �P�����ǂ� ( Date-- ) ---//
Date Date::operator--(int n)
{
	Date temp = *this;
	--(*this);
	return (temp);
}

//--- d1��d2�͓��������H ( d1 == d2 ) ---//
int operator==(const Date& d1, const Date& d2)
{
	return (d1.year == d2.year  &&  d1.month == d2.month  &&  d1.day == d2.day);
}

//--- d1��d2�͈Ⴄ�����H ( d1 != d2 ) ---//
int operator!=(const Date& d1, const Date& d2)
{
	return ( !(d1 == d2) );
}

//--- ���t�̔�r�Fd1 �� d2���H ( d1 > d2 ) ---//
int operator>(const Date& d1, const Date& d2)
{
	if (d1.year  > d2.year) return (1);		// �N���قȂ�
	if (d1.year  < d2.year) return (0);		//               

	if (d1.month > d2.month) return (1);	// �N���������@�| �����قȂ�
	if (d1.month < d2.month) return (0);	// 

	return (d1.day > d2.day);				//             �| ����������
}

//--- ���t�̔�r�Fd1 �� d2���H ( d1 < d2 ) ---//
int operator<(const Date& d1, const Date& d2)
{
	if (d1.year  < d2.year) return (1);		// �N���قȂ�
	if (d1.year  > d2.year) return (0);		//               

	if (d1.month < d2.month) return (1);	// �N���������@�| �����قȂ�
	if (d1.month > d2.month) return (0);	// 

	return (d1.day < d2.day);				//             �| ����������
}

//--- ���t�̔�r�Fd1 �� d2���H ( d1 >= d2 ) ---//
int operator>=(const Date& d1, const Date& d2)
{
	return (d1 > d2 || d1 == d2);
}

//--- ���t�̔�r�Fd1 �� d2���H ( d1 <= d2 ) ---//
int operator<=(const Date& d1, const Date& d2)
{
	return (d1 < d2 || d1 == d2);
}

//--- �}�����Z�q ---//
ostream& operator<<(ostream &s, const Date& x)
{
	return (s << x.Year() << "�N" << x.Month() << "��" << x.Day() << "��");
}

