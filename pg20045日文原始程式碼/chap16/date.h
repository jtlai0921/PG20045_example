//----------------------------------------------------------------------------//
//  日付クラス Date および Gdate（インタフェース部）		"date.h"          //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== 日付クラス =====//
class Date {

protected:
	int		year;		// 西暦年
	int		month;		// 月
	int		day;		// 日

public:
	Date(void);								// デフォルトコンストラクタ
	Date(int y, int m = 1, int d = 1);		// コンストラクタ

	int Year(void)	{ return (year); }		// 年を返却する
	int Month(void)	{ return (month); }		// 月を返却する
	int Day(void)	{ return (day); }		// 日を返却する
};

ostream& operator<<(ostream& s, const Date& x);			// 挿入演算子

//===== 元号版日付クラス =====//
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

ostream& operator<<(ostream& s, const Gdate& x);		// 挿入演算子

