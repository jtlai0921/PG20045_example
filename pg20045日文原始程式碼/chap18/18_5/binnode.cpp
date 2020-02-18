//----------------------------------------------------------------------------//
//	�A�z�z��p�Q���؃m�[�h�N���X BinNode �i�������j				"binnode.c"   //
//----------------------------------------------------------------------------//

#include	<string.h>

#include	"binnode.h"

//--- �R���X�g���N�^ ---//
BinNode::BinNode(char* kstr)
{
	left = right = NULL;
	strcpy(key = new char[strlen(kstr) + 1], kstr);
}

//--- �f�X�g���N�^ ---//
BinNode::~BinNode(void)
{
	if (this != NULL) {
		delete left;			// ���̕����؂����
		delete[] key;			// ������key�����
		delete right;			// �E�̕����؂����
	}
}

//--- �����؏�̑S�m�[�h�����ɏo�� ---//
void BinNode::Put(void)
{
	if (this != NULL) {
		left->Put();			// ���̕����؂��o��
		PutNode();				// �m�[�h�̓��e���o��
		right->Put();			// �E�̕����؂��o��
	}
}

//--- �T�� (friend�֐�) ---//
BinNode** Search(BinNode** t, char *kstr)
{
	int cmp;

	while (*t != NULL && (cmp = strcmp(kstr, (*t)->key)) != 0)
		t = (cmp < 0) ? &(*t)->left : &(*t)->right;
	return (t);
}

