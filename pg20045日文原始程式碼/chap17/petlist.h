//----------------------------------------------------------------------------//
//	�y�b�g���`���X�g�N���X PetList�i�C���^�t�F�[�X���j		"petlist.h"       //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"pet.h"

//----- �y�b�g�m�[�h�N���X -----//
class PetNode {

	friend class  PetList;

private:
	Pet*     pet;			// �y�b�g�̃f�[�^
	PetNode* next;			// �㑱�m�[�h�ւ̃|�C���^

public:
	PetNode(Pet* ptr) : pet(ptr) { next = NULL; }		// �R���X�g���N�^
	~PetNode(void)			{ delete pet; }				// �f�X�g���N�^

	PetNode* Next(void)		{ return (next); }			// �㑱�m�[�h
	operator Pet*(void)		{ return (pet);  }			// �ϊ��֐�
};

//----- �y�b�g���`���X�g�N���X -----//
class PetList {
	//  ���̃N���X�́A�N���XPet�̃t�����h�ł�

	friend ostream& operator<<(ostream& s, const PetList& x);

private:
	PetNode*  top;			// �擪�m�[�h�ւ̃|�C���^
	PetNode*  bottom;		// �����_�~�[�m�[�h�ւ̃|�C���^

public:
	PetList(void);										// �R���X�g���N�^
	~PetList(void);										// �f�X�g���N�^

	PetNode* Top(void) { return ((top == bottom) ? NULL : top); }
	PetNode* Bottom(void);

	PetList& Insert(PetNode*);							// �擪�ւ̃m�[�h�}��
	PetList& Append(PetNode*);							// �����ւ̃m�[�h�ǉ�
	PetList& Delete(void);								// �擪�m�[�h�̍폜
	PetList& Remove(void);								// �����m�[�h�̍폜
	PetList& Clear(void);								// �S�m�[�h�̍폜

	PetList& Introduce(void);							// ���ȏЉ�
};

ostream& operator<<(ostream&, const PetList&);			// �}�����Z�q

