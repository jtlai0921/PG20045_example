//----------------------------------------------------------------------------//
//	連想配列用２分木ノードクラス BinNode（インタフェース部 ）"binnode.h"      //
//----------------------------------------------------------------------------//

//=====  連想配列用２分木ノードクラス =====/
class BinNode {

	friend BinNode** Search(BinNode**, char*);

private:
	char*     key;					// キー
	BinNode*  left;					// 左の子へのポインタ
	BinNode*  right;					// 右の子へのポインタ

public:
	BinNode(char*);
	~BinNode(void);

	const char* Key(void)		{ return (key); }
	BinNode* Left(void)			{ return (left); }
	BinNode* Right(void)			{ return (right); }

	virtual void PutNode(void) = 0;		// 純粋仮想関数

	void Put(void);						// 部分木上の全ノードを順に出力
};

