//----------------------------------------------------------------------------//
//	日付クラス Date 演算子版　実現部						"date.c"		  //
//----------------------------------------------------------------------------//


#include	<time.h>

#include	"date.h"

//--- 各月の日数 ---//
int Date::mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//--- year年は閏年か？ (0･･･非閏年 / 1･･･閏年) ---//
int Date::isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

//--- year年の日数 (365･･･非閏年 / 366･･･閏年) ---//
int Date::Ydays(int year)
{
	return (365 + isLeap(year));
}

//--- year年month月の日数 (28～31) ---//
int Date::Mdays(int year, int month)
{
	if (month-- != 2)						// monthが２月でないとき
		return (mday[month]);
	return (mday[month] + isLeap(year));	// monthが２月であるとき
}

//--- 元旦からの経過日数 ---//
int Date::Dayof(int year, int month, int day)
{
	for (int m = 1; m < month; m++)
		day += Mdays(year, m);
	return (day);
}

//----- クラスDateのコンストラクタ -----//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//----- クラスDateのデフォルトコンストラクタ -----//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);						// 現在時刻を取得
	local = localtime(&current);		// 構造体に変換
	year  = local->tm_year + 1900;		// 年：tm_yearは年-1900
	month = local->tm_mon + 1;			// 月：tm_monは0～11
	day   = local->tm_mday;
}

//--- 日付をdn日進める ( Date += int ) ---//
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

//--- 日付をdn日前を求める ( Date -= int ) ---//
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

//--- dateのdn日後を求める ( Date + int ) ---//
Date operator+(const Date& date, int dn)
{
	Date temp = date;
	return (temp += dn);
}

//--- dateのdn日前を求める ( Date - int ) ---//
Date operator-(const Date& date, int dn)
{
	Date temp = date;
	return (temp -= dn);
}

//--- 日付の差 d1 - d2 を求める ( Date - Date ) ---//
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

//--- １日進める ( ++Date ) ---//
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

//--- １日進める ( Date++ ) ---//
Date Date::operator++(int n)
{
	Date temp = *this;
	++(*this);
	return (temp);
}

//--- １日もどす ( --Date ) ---//
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

//--- １日もどす ( Date-- ) ---//
Date Date::operator--(int n)
{
	Date temp = *this;
	--(*this);
	return (temp);
}

//--- d1とd2は同じ日か？ ( d1 == d2 ) ---//
int operator==(const Date& d1, const Date& d2)
{
	return (d1.year == d2.year  &&  d1.month == d2.month  &&  d1.day == d2.day);
}

//--- d1とd2は違う日か？ ( d1 != d2 ) ---//
int operator!=(const Date& d1, const Date& d2)
{
	return ( !(d1 == d2) );
}

//--- 日付の比較：d1 ＞ d2か？ ( d1 > d2 ) ---//
int operator>(const Date& d1, const Date& d2)
{
	if (d1.year  > d2.year) return (1);		// 年が異なる
	if (d1.year  < d2.year) return (0);		//               

	if (d1.month > d2.month) return (1);	// 年が等しい　－ 月が異なる
	if (d1.month < d2.month) return (0);	// 

	return (d1.day > d2.day);				//             － 月も等しい
}

//--- 日付の比較：d1 ＜ d2か？ ( d1 < d2 ) ---//
int operator<(const Date& d1, const Date& d2)
{
	if (d1.year  < d2.year) return (1);		// 年が異なる
	if (d1.year  > d2.year) return (0);		//               

	if (d1.month < d2.month) return (1);	// 年が等しい　－ 月が異なる
	if (d1.month > d2.month) return (0);	// 

	return (d1.day < d2.day);				//             － 月も等しい
}

//--- 日付の比較：d1 ≧ d2か？ ( d1 >= d2 ) ---//
int operator>=(const Date& d1, const Date& d2)
{
	return (d1 > d2 || d1 == d2);
}

//--- 日付の比較：d1 ≦ d2か？ ( d1 <= d2 ) ---//
int operator<=(const Date& d1, const Date& d2)
{
	return (d1 < d2 || d1 == d2);
}

//--- 挿入演算子 ---//
ostream& operator<<(ostream &s, const Date& x)
{
	return (s << x.Year() << "年" << x.Month() << "月" << x.Day() << "日");
}

