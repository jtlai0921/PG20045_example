//----------------------------------------------------------------------------//
//  カウンタクラス Counter									"counter.h"       //
//----------------------------------------------------------------------------//


#include	<limits.h>

//===== カウンタクラス =====//
class Counter {

private:
	unsigned  Cnt;					// カウント値

public:
	Counter(void) { Cnt = 0; }		// コンストラクタ

	void Increment(void) { if (Cnt < UINT_MAX) Cnt++; }		// カウントアップ
	void Decrement(void) { if (Cnt > 0) Cnt--; }			// カウントダウン
	unsigned Value(void) { return (Cnt); }					// カウント値を返却
};

