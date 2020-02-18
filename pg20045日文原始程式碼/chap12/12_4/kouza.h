//---------------------------------------------------------------------- 
// 開設日付き銀行口座クラス Kouza（インタフェース部）		"kouza.h" 
//

#include	"date.h"

//===== 銀行口座クラス =====//
class Kouza {
private:
	long	number;						// 口座番号
	long	yokin;						// 預金額
	Date	kaisetsu;					// 開設日

public:
	Kouza(long no, long yok, int y, int m, int d);		// コンストラクタ

	void Ireru(long okane);								// 口座にお金を預ける
	void Orosu(long okane);								// 口座から引き出す
    
	long KouzaNo(void)      { return (number); }		// 口座番号
	long Yokingaku(void)    { return (yokin); }			// 預金額
	Date Kaisetsubi(void)   { return (kaisetsu); }		// 開設日
};

