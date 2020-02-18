//----------------------------------------------------------------------------//
//	日付クラス Date 演算子版　インタフェース部				"date.h"          //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== 日付クラス =====//
class Date {

private:
	int		year;		// 西暦年
	int		month;		// 月
	int		day;			// 日

	static int Date::mday[12];			// 各月の日数 {31, 28, 31, 30, ･･･ }
	static int isLeap(int year);				// year年は閏年か？ (0 / 1)
	static int Ydays(int year);					// year年の日数（365 / 366）
	static int Mdays(int year, int month);		// year年month月の日数 (28
～31)
	static int Dayof(int y, int m, int d);		// 元旦からの経過日数

public:
	Date(void);									// デフォルトコンストラクタ
	Date(int y, int m = 1, int d = 1);			// コンストラクタ

	int Year(void)  const { return (year); }		// 年を返す
	int Month(void) const { return (month); }		// 月を返す
	int Day(void)   const { return (day); }			// 日を返す

	Date& operator++(void);							// １日進める
	Date& operator--(void);							// １日もどす
	Date operator++(int dmy);						// １日進める
	Date operator--(int dmy);						// １日もどす
	Date& operator+=(int dn);						// dn日進める
	Date& operator-=(int dn);						// dn日もどす
	friend Date operator+(const Date& date, int dn);		// dn日後を求める
	friend Date operator-(const Date& date, int dn);		// dn日前を求める
	friend long operator-(const Date& d1, const Date& d2);	// 日付の差を求
める
	friend int operator==(const Date& d1, const Date& d2);	// 同じ日か？
	friend int operator!=(const Date& d1, const Date& d2);	// 違う日か？
	friend int operator>(const Date& d1, const Date& d2);	// d1 ＞ d2
	friend int operator>=(const Date& d1, const Date& d2);	// d1 ≧ d2
	friend int operator<(const Date& d1, const Date& d2);	// d1 ＜ d2
	friend int operator<=(const Date& d1, const Date& d2);	// d1 ≦ d2
};

ostream& operator<<(ostream&, const Date& x);				// 挿入演算子

