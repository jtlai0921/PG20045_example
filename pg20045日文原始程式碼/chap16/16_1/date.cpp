//----------------------------------------------------------------------------//
//  日付クラス Date および Gdate（実現部）					"date.c"          //
//----------------------------------------------------------------------------//


#include	<time.h>

#include	"date.h"

//--- 【クラスDate】コンストラクタ ---//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//--- 【クラスDate】デフォルトコンストラクタ ---//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);							// 現在の時刻を取得
	local = localtime(&current);			// 構造体に変換
	year  = local->tm_year + 1900;			// 年：tm_yearは年-1900　
	month = local->tm_mon + 1;				// 月：tm_monは0～11
	day   = local->tm_mday;
}

//--- 【クラスDate】ostreamへの挿入 ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return (s << x.Year() << "年" << x.Month() << "月" << x.Day() << "日");
}

//--- 【クラスGdate】ostreamへの挿入 ---//
ostream& operator<<(ostream& s, const Gdate& x)
{
	unsigned long idate = x.Year()*10000UL + x.Month()*100UL + x.Day();

	if (idate < 18680908UL)
		s << x.Year();
	else if (idate < 19120730UL)
		s << "明治" << x.Year() - 1867;
	else if (idate < 19261225UL)
		s << "大正" << x.Year() - 1911;
	else if (idate < 19890108UL)
		s << "昭和" << x.Year() - 1925;
	else
		s << "平成" << x.Year() - 1988;
	return (s << "年" << x.Month() << "月" << x.Day() << "日");
}

