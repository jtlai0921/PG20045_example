//---------------------------------------------------------------------------
-//
//  日付クラス Date （実現部）								"date.c"          
//
//---------------------------------------------------------------------------
-//

#include	<time.h>

#include	"date.h"

//--- クラスDateのデフォルトコンストラクタ ---//
Date::Date(void)
{
	time_t		current;
	struct tm*	local;

	time(&current);						// 現在の時刻を取得
	local = localtime(&current);		// 構造体に変換
	year  = local->tm_year + 1900;		// 年：tm_yearは年-1900　
	month = local->tm_mon + 1;			// 月：tm_monは0～11
	day   = local->tm_mday;
}

//--- クラスDateのコンストラクタ ---//
Date::Date(int y, int m, int d)
{
	year  = y;
	month = m;
	day   = d;
}

//--- 出力ストリームsにxを挿入 ---//
ostream& operator<<(ostream& s, Date& x)
{
	return (s << x.Year() << "年" << x.Month() << "月" << x.Day() << "日");
}

