//----------------------------------------------------------------------------//
//	�y�b�g�N���X Pet�i�C���^�t�F�[�X���j					"pet.h"           //
//----------------------------------------------------------------------------//

#include	<iostream.h>

//===== �y�b�g�N���X =====//
class Pet {

public:
	typedef char	PetName[20];
	enum PetType {Dog, Cat, Monkey};

private:
	PetType	kind;							// ���
	PetName	name;							// ���O

public:
	Pet(PetType x = Dog, char* n = "");		// �R���X�g���N�^

	PetType Type(void) { return (kind); }	// ��ʂ�ԋp����
	char*   Name(void) { return (name); }	// ���O��ԋp����

	void Input(void);						// ����
	void Sintro(void);						// ���ȏЉ���s��
};

ostream& operator<<(ostream&, const Pet&);  // �}�����Z�q

