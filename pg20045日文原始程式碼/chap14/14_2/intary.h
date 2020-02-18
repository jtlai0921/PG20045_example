//----------------------------------------------------------------------------//
//  整数配列クラス IntAry 第４版（インタフェース部）		"intary.h"        //
//----------------------------------------------------------------------------//


//===== 整数配列クラス =====//
class IntAry {

private:
	static int counter;
	static void CntUp(void) { counter++; }
	static void CntDn(void) { counter--; }

	int		size;				// 配列の要素数
	int*	ptr;					// 先頭要素へのポインタ

public:
	//----- 添え字範囲エラー -----//
	class RangeErr {
	private:
		IntAry* ident;
		int		index;
	public:
		RangeErr(IntAry* p, int i) : ident(p), index(i) { }
		int Index(void)  { return (index); }
	};

	static int GetCount(void) { return (counter); }

	IntAry(int sz)          { ptr = new int[size = sz]; CntUp(); }
	IntAry(const IntAry&);

	~IntAry(void)           { delete[] ptr; CntDn(); }

	int Size(void)          { return (size); }

	IntAry& operator=(const IntAry&);

	int& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);		// 添え字範囲エラー送出
		return (ptr[i]);
	}
};

