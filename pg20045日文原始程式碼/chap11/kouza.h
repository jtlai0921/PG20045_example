//---------------------------------------------------------------------//
//  銀行口座クラス kouza（インタフェース部）				"kouza.h"
//
//--------------------------------------------------------------------//

//===== 銀行口座クラス =====//
class kouza {

private:							//===== 私的部 =====//
	long	number;						// 口座番号
	long	yokin;						// 預金額

public:								//===== 公開部 =====//
	kouza(long no, long yok);			// コンストラクタ

	void ireru(long okane);				// 口座にお金を預ける

	void orosu(long okane);				// 口座から引き出す

	long kouza_no(void) {				// 口座番号
		return (number);
	}

	long yokingaku(void) {				// 預金額
		return (yokin);
	}
};
