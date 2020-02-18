//----------------------------------------------------------------------------//
//	スタッククラス Astack									"astack.h"        //
//----------------------------------------------------------------------------//


//#include	"tary.h"  // tary.hは14章にない。
#include	"intary.h" // 野沢変更

//===== スタッククラス =====//
template <class Type>
class Astack : public Ary<Type> {

private:
	int	top;
	Astack(const Astack&);					// コピーコンストラクタを無効化
	Astack& operator=(const Astack&);		// 代入演算子

public:
	//----- 空スタックからのポップに対する例外 -----//
	class EmptyErr {
	private:
		Astack*	ident;
	public:
		EmptyErr(Astack* a) : ident(a) { }
		Astack* Ptr(void) { return (ident); }
	};

	Astack(int a) : Ary<Type>(a) { top = 0; }
	
	int Push(const Type& a) {
		if (top - 1 < size) {
			ptr[top++] = a;
			return (1);
		}
		return (0);
	}
	
	Type Pop(void) {
		if (top < 1)
			throw EmptyErr(this);
		return (ptr[--top]);
	}
};

