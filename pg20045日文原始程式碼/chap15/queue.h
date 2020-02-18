//----------------------------------------------------------------------------//
//	キュークラステンプレート								"queue.h"         //
//----------------------------------------------------------------------------//


//===== キュークラステンプレート =====//
template <class Type> class Queue {

private:
	int		size;				// 配列の大きさ
	int		no;					// 現在の要素数
	Type*	ptr;				// キュー本体へのポインタ
	Type*	front;				// 先頭要素
	Type*	rear;				// 末尾要素

	Queue(const Queue&);			// コピーコンストラクタを無効化
	Queue& operator=(const Queue&);	// 代入演算子を無効化

public:
	//----- 空キューからの取り出しに対する例外 -----//
	class EmptyErr {
	private:
		Queue*	ident;
	public:
		EmptyErr(Queue* p) : ident(p) { }
		Queue* Ptr(void)  { return (ident); }
	};

	Queue(int sz) {
		front = rear = ptr = new Type[size = sz];
		no = 0;
	}

	~Queue(void)		{ delete[] ptr; }

	int Add(const Type &x) {	// データの追加
		if (no >= size)
			return (0);
		no++;
		*rear++ = x;
		if (rear >= ptr + size) rear = ptr;
		return (1);
	}

	Type Remove(void) {			// データの取りだし
		if (no <= 0)
			throw EmptyErr(this);		// エラー送出
		no--;
		Type temp = *front++;
		if (front >= ptr + size) front = ptr;
		return (temp);
	}

	friend ostream& operator<<(ostream&, Queue<Type>&);
};

//----- 出力 -----//
template <class Type>
ostream& operator<<(ostream& os, Queue<Type>& x)
{
	os << "{ ";
	if (x.no > 0) {
		Type* ptr;
		int   j = 0;

		for (ptr = x.front; ptr < x.ptr+x.size; ptr++) {
			if (++j > x.no) break;
			cout << *ptr << ' ';
		}
		for (ptr = x.ptr; ptr < x.ptr+x.size; ptr++) {
			if (++j > x.no) break;
			cout << *ptr << ' ';
		}
	}
	os << "}\n";
	return (os);
}

