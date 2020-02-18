//----------------------------------------------------------------------------//
//	連想配列用２分木ノードクラス BinNode （実現部）				"binnode.c"   //
//----------------------------------------------------------------------------//

#include	<string.h>

#include	"binnode.h"

//--- コンストラクタ ---//
BinNode::BinNode(char* kstr)
{
	left = right = NULL;
	strcpy(key = new char[strlen(kstr) + 1], kstr);
}

//--- デストラクタ ---//
BinNode::~BinNode(void)
{
	if (this != NULL) {
		delete left;			// 左の部分木を解放
		delete[] key;			// 文字列keyを解放
		delete right;			// 右の部分木を解放
	}
}

//--- 部分木上の全ノードを順に出力 ---//
void BinNode::Put(void)
{
	if (this != NULL) {
		left->Put();			// 左の部分木を出力
		PutNode();				// ノードの内容を出力
		right->Put();			// 右の部分木を出力
	}
}

//--- 探索 (friend関数) ---//
BinNode** Search(BinNode** t, char *kstr)
{
	int cmp;

	while (*t != NULL && (cmp = strcmp(kstr, (*t)->key)) != 0)
		t = (cmp < 0) ? &(*t)->left : &(*t)->right;
	return (t);
}

