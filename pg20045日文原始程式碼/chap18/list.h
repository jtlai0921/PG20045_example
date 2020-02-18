//-------------------------------------------------------------//
//	線形リスト・ノードクラス（インタフェース部）	"list.h"   //
//-------------------------------------------------------------//

//----- ノードクラス -----//
class Node {

	friend class List;

protected:
	Node*  next;					// 後続ノードへのポインタ

public:
	Node(void) { next = NULL};		// コンストラクタ
	Node* Next(void) const 	{ return (next); }	// 後続ノード
};

//----- 線形リストクラス -----//
class List {
private:
	Node*  top;				// 先頭ノードへのポインタ
	Node*  bottom;			// 末尾ダミーノードへのポインタ

public:
	List(void);				// コンストラクタ
	~List(void);			// デストラクタ

	Node* Top(void) const { return ((top == bottom) ? NULL : top); }
	Node* Bottom(void) const;

	List& Insert(Node*);		// 先頭へのノード挿入
	List& Append(Node*);		// 末尾へのノード追加
	List& Delete(void);		// 先頭ノードの削除
	List& Remove(void);		// 末尾ノードの削除
	List& Clear(void);		// 全ノードの削除
};

