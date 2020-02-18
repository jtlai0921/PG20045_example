//----------------------------------------------------------------------------//
//	配列クラステンプレート Ary（インタフェース部）			"tary.h"          //
//----------------------------------------------------------------------------//


//===== 配列クラステンプレート =====//
template <class Type> class Ary {

private:
	int		size;				// 配列の要素数
	Type*	ptr;					// 先頭要素へのポインタ

public:
	//----- 添え字範囲エラー -----//
	class RangeErr {
	private:
		Ary*	 ident;
		int	 index;
	public:
		RangeErr(Ary* p, int i) : ident(p), index(i) {}
		int Index(void)	{ return (index); }
	};

	Ary(int sz)			{ ptr = new Type[size = sz]; }	// コンストラクタ
	Ary(const Ary&);									// コピーコンストラクタ

	~Ary(void)			{ delete[] ptr; }				// デストラクタ

	Ary& operator=(const Ary&);							// 代入演算子

	Type& operator[](int i)								// 添え字演算子
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);			// 添え字範囲エラー送出
		return (ptr[i]);
	}
};

