//-------------------------------------------------------------//
//	カウンタクラス								"bsco.h"  //
//-------------------------------------------------------------//

#include	<limits.h>

//===== カウンタクラス =====//
class BsCounter {

protected:
	unsigned	cnt;					// カウンタ値

public:
	BsCounter(void) { cnt = 0; }		// コンストラクタ

	virtual void Increment(void) { if (cnt < UINT_MAX) cnt++; }
	virtual void Decrement(void) { if (cnt > 0) cnt--; }
	unsigned Value(void) { return (cnt); }
};

//===== 上限付きカウンタクラス =====//
class BndCounter : public BsCounter {

private:
	unsigned  max;

public:
	BndCounter(unsigned hi = UINT_MAX) { max = hi; cnt = 0; }
	void Increment(void) { if (cnt < max) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
};

