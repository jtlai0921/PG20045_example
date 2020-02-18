//----------------------------------------------------------------------------//
//	配列クラステンプレート Ary （実現部）					"tary.c"          //
//----------------------------------------------------------------------------//


#include	"tary.h"

//--- コピーコンストラクタ ---//
template <class Type> Ary <Type>::Ary(const Ary& x)
{
	ptr = new Type[x.size];
	size = x.size;
	for (int i = 0; i < size; i++)
		ptr[i] = x.ptr[i];
}

//--- 代入演算子 ---//
template <class Type> Ary<Type>& Ary<Type>::operator=(const Ary& x)
{
	if (&x != this) {				// 自分自身へは代入しない
		delete[] ptr;
		ptr = new Type[x.size];
		size = x.size;
		for (int i = 0; i < size; i++)
			ptr[i] = x.ptr[i];
	}
	return (*this);
}

