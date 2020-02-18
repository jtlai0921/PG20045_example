//----------------------------------------------------------------------------//
//  �ystring�z�A�z�z��p�Q���؃N���X AcAstring�i�C���^�t�F�[�X���j"acastrng.h"//
//----------------------------------------------------------------------------//

#include	<cstring.h>
#include	<iostream.h>

#include	"binnode.h"

//===== �ystring�z�A�z�z��m�[�h =====//
class ANstring : BinNode, string {

	friend class AcAstring;

private:
	ANstring(char* kstr, char* dat) : BinNode(kstr) , string(dat) {}
	void PutNode(void) { cout<< Key()<< " "<< (string)(*this) << '\n'; }
};

//===== �ystring�z�A�z�z�� =====//
class AcAstring {

private:
	ANstring*	tree;

public:
	AcAstring(void) { tree = NULL; }
	~AcAstring(void){ if (tree != NULL) delete tree; }
	void Put(void)  { tree->BinNode::Put(); }
	string& operator[](char*);
};

