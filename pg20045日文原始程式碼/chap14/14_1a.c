//----------------------------------------------------------------------------//
//	整数配列クラス IntFixedAry （実現部）					"IntFixedAry.c"   //
//----------------------------------------------------------------------------//

#include	"IntFixedAry.h"

//--- コピーコンストラクタ ---//
IntFixedAry::IntFixedAry(const IntFixedAry& x)
{
	ptr = new int[x.size];
	size = x.size;
	for (int i = 0; i < size; i++)
		ptr[i] = x.ptr[i];
}

//--- 代入演算子 ---//
IntFixedAry& IntFixedAry::operator=(const IntFixedAry& x)
{
	if (x.size != size)						// 要素数が異なる
		throw SizeErr(this, x.size);		// サイズエラー送出	
	else {
		for (int i = 0; i < size; i++)
			ptr[i] = x.ptr[i];
	}
	return (*this);
}

