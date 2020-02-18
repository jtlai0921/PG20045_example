//----------------------------------------------------------------------------//
//	�A�z�z��p�Q���؃m�[�h�N���X BinNode�i�C���^�t�F�[�X�� �j"binnode.h"      //
//----------------------------------------------------------------------------//

//=====  �A�z�z��p�Q���؃m�[�h�N���X =====/
class BinNode {

	friend BinNode** Search(BinNode**, char*);

private:
	char*     key;					// �L�[
	BinNode*  left;					// ���̎q�ւ̃|�C���^
	BinNode*  right;					// �E�̎q�ւ̃|�C���^

public:
	BinNode(char*);
	~BinNode(void);

	const char* Key(void)		{ return (key); }
	BinNode* Left(void)			{ return (left); }
	BinNode* Right(void)			{ return (right); }

	virtual void PutNode(void) = 0;		// �������z�֐�

	void Put(void);						// �����؏�̑S�m�[�h�����ɏo��
};

