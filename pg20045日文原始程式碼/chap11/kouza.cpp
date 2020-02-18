//---------------------------------------------------------------------//
//  銀行口座クラス kouza（実現部）							"kouza.c"     
//
//---------------------------------------------------------------------//

#include	"kouza.h"

kouza::kouza(long no, long yok) {		// コンストラクタ
	number = no;
	yokin = yok;
}

void kouza::ireru(long okane) {			// 口座にお金を預ける
	yokin += okane;
}

void kouza::orosu(long okane) {			// 口座から引き出す
	yokin -= okane;
}

