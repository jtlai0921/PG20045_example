//----------------------------------------------------------------------------//
//	偶数カウントアップクラス Bcounter						"bcounter.h"      //
//----------------------------------------------------------------------------//


#include	"counter.h"

//===== 偶数カウントアップクラス =====//
class Bcounter : private Counter {

public:
	Bounter(void) { }					// コンストラクタ

	Counter::Value;						// 関数Value ･･･アクセス宣言

	void Increment(void) {				// ２つ進める･･･再定義
		if (Value() < UINT_MAX - 1) {
			Counter::Increment();
			Counter::Increment();
		}
	}
};

