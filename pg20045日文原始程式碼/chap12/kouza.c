//---------------------------------------------------------------------------
-//
//  開設日付き銀行口座クラス Kouza（実現部）				"kouza.c"         
//
//---------------------------------------------------------------------------
-//

#include	"kouza.h"

//--- コンストラクタ ---//
Kouza::Kouza(long no, long yok, int y, int m, int d) : kaisetsu(y, m, d)
{
	number = no;
	yokin = yok;
}

//--- 口座にお金を預ける ---//
void Kouza::Ireru(long okane)
{
	yokin += okane;
}

//--- 口座から引き出す ---//
void Kouza::Orosu(long okane)
{
	yokin -= okane;
}

