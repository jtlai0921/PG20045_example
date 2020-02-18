//-------------------------------------------------------------//
//	配列リストクラス FixedList					"fixedlist.h"  //
//-------------------------------------------------------------//

//===== 配列リストクラスのノード =====//
template<class Type>
class FixedNode {
	friend class FixedList<Type>;

private:
	Type  data;		// データ
	int	  next;
	int	  dnext;

public:
	Type Data(void) const { return (data); }	// データを返却
	int Next(void)  const { return (next); }
};

//===== 配列リストクラス =====//
template<class Type>
class FixedList {

private:
	FixedNode<Type>	*ptr;
	int	 size;				// リストを格納する配列の要素数
	int	 top;				// 線形リストの先頭要素へのポインタ
	int	 deleted;			// 削除リストの先頭要素へのポインタ
	int	 max;				// 現在登録されているノードの個数

	int GetIndex(void)		// 挿入すべき位置の添え字を返却
	{
		if (deleted == Null)
			return (++max);
		else {
			int  rec = deleted;
			deleted = ptr[rec].dnext;
			return (rec);
		}
	}

	void DeleteIndex(int idx)	// レコードidxを削除リストに登録
	{
		if (deleted == Null) {
			deleted = idx;
			ptr[idx].dnext = Null;
		} else {
			int  p = deleted;
			deleted = idx;
			ptr[idx].dnext = p;
		}
	}
	
public:

	enum { Null = -1 };					// ヌルポインタ
	FixedList(int sz)					// コンストラクタ
	{
		ptr = new FixedNode<Type>[size = sz];
		top = deleted = max = Null;
	}

	~FixedList(void) { Clear(); delete[] ptr; }	// デストラクタ
	int Top(void)    { return (top); }

	void InsertNode(Type data)			// 先頭にノードを挿入
	{
		int  p = top;
		top = GetIndex();
		ptr[top].next = p;
        ptr[top].data = data;
	}

	void AppendNode(Type data)			// 末尾にノードを追加
	{
		if (top == Null)
			InsertNode(data);
		else {
			int  p = top;
			while (ptr[p].next != Null)
				p = ptr[p].next;
			p = ptr[p].next = GetIndex();
			ptr[p].next = Null;
			ptr[p].data = data;
		}
	}

	void DeleteNode(void)				// 先頭ノードの削除
	{
		if (top != Null) {
			int  p = ptr[top].next;
			DeleteIndex(top);
			top = p;
		}
	}

	void Clear(void)					// 全てのノードを削除
	{
		while (top != Null)
			DeleteNode();
	}

	FixedNode<Type>& operator[](int i)	// 添え字演算子
	{
		return (ptr[i]);
	}
};

