//----------------------------------------------------------------------------//
//	キュークラス Aqueue										"aqueue.h"        //
//----------------------------------------------------------------------------//


#include	"tary.h"

//===== キュークラス =====//
template <class Type>
class Aqueue : public Ary<Type> {

private:
	int	no;
	int	front;
	int	rear;
	Aqueue(const Aqueue&);					// コピーコンストラクタを無効化
	Aqueue& operator=(const Aqueue&);		// 代入演算子

public:
	//----- 空キューからのRemoveに対する例外 -----//
	class EmptyErr {
	private:
		Aqueue*	ident;
	public:
		EmptyErr(Aqueue* a) : ident(a) { }
		Aqueue* Ptr(void) { return (ident); }
	};

	Aqueue(int a) : Ary<Type>(a) { no = front = rear = 0; }

	int Add(const Type& a) {
		if (no > size)
			return (0);
		no++;
		ptr[rear++] = a;
		if (rear >= size)
			rear = 0;
		return (1);
	}

	Type Remove(void) {
		if (no <= 0)
			throw EmptyErr(this);
		no--;
		Type temp = ptr[front++];
		if (front >= size)
			front = 0;
		return (temp);
	}
};

