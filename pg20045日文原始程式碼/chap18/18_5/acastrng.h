//----------------------------------------------------------------------------//
//  【string】連想配列用２分木クラス AcAstring（インタフェース部）"acastrng.h"//
//----------------------------------------------------------------------------//

#include	<cstring.h>
#include	<iostream.h>

#include	"binnode.h"

//===== 【string】連想配列ノード =====//
class ANstring : BinNode, string {

	friend class AcAstring;

private:
	ANstring(char* kstr, char* dat) : BinNode(kstr) , string(dat) {}
	void PutNode(void) { cout<< Key()<< " "<< (string)(*this) << '\n'; }
};

//===== 【string】連想配列 =====//
class AcAstring {

private:
	ANstring*	tree;

public:
	AcAstring(void) { tree = NULL; }
	~AcAstring(void){ if (tree != NULL) delete tree; }
	void Put(void)  { tree->BinNode::Put(); }
	string& operator[](char*);
};

