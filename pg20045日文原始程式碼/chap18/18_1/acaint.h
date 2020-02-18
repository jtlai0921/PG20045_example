//----------------------------------------------------------------------------//
//	【int】連想配列クラス AcAint （インタフェース部）		"acaint.h"        //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"binnode.h"

//===== 【int】連想配列ノード =====//
class ANint : BinNode {

	friend class AcAint;

private:
	int data;
	ANint(char *kstr) : BinNode(kstr) { data = 0; }
	void PutNode(void)		{ cout << Key() << " " << data << '\n'; }
};

//===== 【int】連想配列 =====//
class AcAint {

private:
	ANint*		tree;

public:
	AcAint(void)	{ tree = NULL; }
	~AcAint(void)	{ if (tree != NULL) delete tree; }
	void Put(void)	{ tree->BinNode::Put(); }
	int& operator[](char*);
};
