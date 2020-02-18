//----------------------------------------------------------------------------//
//  整数配列クラス IntFixedAry （インタフェース部）			"IntFixedAry.h"   //
//----------------------------------------------------------------------------//


//===== 整数配列クラス =====//
class IntFixedAry {

private:
	int	  size;				// 配列の要素数
	int*  ptr;				// 先頭要素へのポインタ

public:

	//----- 添え字範囲エラー -----//
	class RangeErr {
	private:
		IntFixedAry*  ident;
		int			  index;
	public:
		RangeErr(IntFixedAry* p, int i) : ident(p), index(i) { }
		int Index(void)  { return (index); }
	};

	//----- サイズエラー -----//
	class SizeErr {
	private:
		IntFixedAry*  ident;
		int			  size;
	public:
		SizeErr(IntFixedAry* p, int i) : ident(p), size(i) { }
		int Size(void)  { return (size); }
	};

	IntFixedAry(int sz)          { ptr = new int[size = sz]; }

	IntFixedAry(const IntFixedAry&);

	~IntFixedAry(void)           { delete[] ptr; }			// デストラクタ

	int Size(void)               { return (size); }

	IntFixedAry& operator=(const IntFixedAry&);

	int& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);		// 添え字範囲エラー送出
		return (ptr[i]);
	}
};

