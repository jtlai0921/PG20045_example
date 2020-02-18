//-----------------------------------------------------//
//	カウンタクラスファミリ				"vcounter.h"   //
//-----------------------------------------------------//

#include	<limits.h>

//----- カウンタクラス -----//
class VCounter {
protected:
	unsigned  cnt;						// カウンタ値
public:
	VCounter(void) { cnt = 0; }			// コンストラクタ

	virtual void Increment(void) = 0;	// 純粋仮想関数
	virtual void Decrement(void) = 0;	// 純粋仮想関数
	unsigned Value(void) { return (cnt); }
};

//----- UINT_MAXが上限のカウンタクラス -----//
class UnCounter  : public VCounter {
public:
	void Increment(void) { if (cnt < UINT_MAX) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
	unsigned Value(void) { return (cnt); }
};

//----- 上限付カウンタ -----//
class BnCounter : public VCounter {
private:
	unsigned  max;						// 最大値
public:
	BnCounter(unsigned hi = UINT_MAX) { max = hi; }
	void Increment(void) { if (cnt < max) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
};

