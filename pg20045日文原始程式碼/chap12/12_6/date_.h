//----------------------------------------------------------------------------//
//  日付クラス Date （インタフェース部）					"date.h"          
//
//----------------------------------------------------------------------------//

#include	<iostream.h>

//===== 日付クラス =====//
class Date {

private:
	int		year;		// 西暦年
	int		month;		// 月
	int		day;		// 日

public:
	Date(void);									// デフォルトコンストラクタ
	Date(int y, int m = 1, int d =1);			// コンストラクタ

	int Year(void)  const { return (year); }	// 年を返却
	int Month(void) const { return (month); }	// 月を返却
	int Day(void)   const { return (day); }		// 日を返却
};

ostream& operator<<(ostream& s, Date& x);		// 挿入演算子

