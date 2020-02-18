//----------------------------------------------------------------------------//
//	�yint�z�A�z�z��N���X AcAint �i�C���^�t�F�[�X���j		"acaint.h"        //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"binnode.h"

//===== �yint�z�A�z�z��m�[�h =====//
class ANint : BinNode {

	friend class AcAint;

private:
	int data;
	ANint(char *kstr) : BinNode(kstr) { data = 0; }
	void PutNode(void)		{ cout << Key() << " " << data << '\n'; }
};

//===== �yint�z�A�z�z�� =====//
class AcAint {

private:
	ANint*		tree;

public:
	AcAint(void)	{ tree = NULL; }
	~AcAint(void)	{ if (tree != NULL) delete tree; }
	void Put(void)	{ tree->BinNode::Put(); }
	int& operator[](char*);
};
