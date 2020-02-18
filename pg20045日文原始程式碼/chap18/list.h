//-------------------------------------------------------------//
//	���`���X�g�E�m�[�h�N���X�i�C���^�t�F�[�X���j	"list.h"   //
//-------------------------------------------------------------//

//----- �m�[�h�N���X -----//
class Node {

	friend class List;

protected:
	Node*  next;					// �㑱�m�[�h�ւ̃|�C���^

public:
	Node(void) { next = NULL};		// �R���X�g���N�^
	Node* Next(void) const 	{ return (next); }	// �㑱�m�[�h
};

//----- ���`���X�g�N���X -----//
class List {
private:
	Node*  top;				// �擪�m�[�h�ւ̃|�C���^
	Node*  bottom;			// �����_�~�[�m�[�h�ւ̃|�C���^

public:
	List(void);				// �R���X�g���N�^
	~List(void);			// �f�X�g���N�^

	Node* Top(void) const { return ((top == bottom) ? NULL : top); }
	Node* Bottom(void) const;

	List& Insert(Node*);		// �擪�ւ̃m�[�h�}��
	List& Append(Node*);		// �����ւ̃m�[�h�ǉ�
	List& Delete(void);		// �擪�m�[�h�̍폜
	List& Remove(void);		// �����m�[�h�̍폜
	List& Clear(void);		// �S�m�[�h�̍폜
};

