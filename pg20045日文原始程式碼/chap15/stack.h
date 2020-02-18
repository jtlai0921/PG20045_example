//----------------------------------------------------------------------------//
//	スタッククラステンプレート Stack						"stack.h"         //
//----------------------------------------------------------------------------//


//===== スタッククラステンプレート =====//
template <class Type> class Stack {

private:
	int		size;				// 配列の要素数
	Type*	ptr;					// 先頭要素へのポインタ
	Type*	top;					// スタックポインタ

	Stack(const Stack&);				// コピーコンストラクタを無効化
	Stack& operator=(const Stack&);		// 代入演算子を無効化

public:
	//----- 空スタックからのポップに対する例外 -----//
	class EmptyErr {
	private:
		Stack*	ident;
	public:
		EmptyErr(Stack* p) : ident(p) { }
		Stack* Ptr(void)  { return (ident); }
	};

	Stack(int sz) { ptr = top = new Type[size = sz]; }
	~Stack(void)  { delete[] ptr; }

	int Push(const Type &x) {			// プッシュ
		if (ptr - top < size) {
			*top++ = x;
			return (1);
		}
		return (0);
	}

	Type Pop(void) {					// ポップ
		if (top <= ptr)
			throw EmptyErr(this);		// エラー送出
		return (*--top);
	}
};

