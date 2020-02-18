//----------------------------------------------------------------------------//
//	カウンタクラス Counter									"counter.h"       //
//----------------------------------------------------------------------------//


#include	<limits.h>

//===== カウンタクラス =====//
class Counter {

private:
	unsigned	Cnt;								// カウント値

public:
	Counter(void) { Cnt = 0; }						// コンストラクタ

	operator unsigned(void) { return (Cnt); }		// 変換関数   unsigned(op)

	int operator!(void) { return (Cnt == 0); }		// 否定演算子 !op

	Counter operator++(void) {					// 前置インクリメント演算子 ++op
		if (Cnt < UINT_MAX) Cnt++;
			return (*this);
	}

	Counter operator++(int dummy) {				// 後置インクリメント演算子 op++
		Counter x = *this;
		if (Cnt < UINT_MAX) Cnt++;
			return (x);
	}

	Counter operator--(void) {					// 前置デクリメント演算子 --op
		if (Cnt > 0) Cnt--;
			return (*this);
	}

	Counter operator--(int dummy) {				// 後置デクリメント演算子 op--
		Counter x = *this;
		if (Cnt > 0) Cnt--;
			return (x);
	}
};

