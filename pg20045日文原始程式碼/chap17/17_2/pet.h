//----------------------------------------------------------------------------//
//	�p���Ńy�b�g�N���X Pet�i�C���^�t�F�[�X���j				"pet.h"           //
//----------------------------------------------------------------------------//

#include	<iostream.h>
//===== �y�b�g�N���X =====//
class Pet {
public:
	typedef char	PetName[20];
protected:
	PetName name;										// ���O
public:
	Pet(char* n="");										// �R���X�g���N�^
	char*	Name(void) { return (name); }				// ���O��ԋp����
	virtual void Input(void)  {							//�y���z�֐��z
		cout << "���O : "; cin >> name;					//  ����
	}
	virtual void Sintro(void) {							//�y���z�֐��z
		cout << "�l�̖��O��" << name << "�ł��B\n";		//   ���ȏЉ� 
	}
};
ostream& operator<<(ostream&, const Pet&);				// �}�����Z�q

//===== ���y�b�g�N���X =====//
class Pdog : public Pet {
public:
	typedef char		DogKind[20];
protected:
	DogKind kname;												// ���
public:
	Pdog(char* n = "", char* k = "");
	void Input(void) {											// ����
		Pet::Input();
		cout << "��� : "; cin >> kname;
	}
	void Sintro(void) {											// ���ȏЉ�
		cout << "�l��" << kname << "��" << name << "������!!\n";
	}
};

//===== �L�y�b�g�N���X =====//
class Pcat : public Pet {
public:
	Pcat(char* n = "") : Pet(n) { }
	// �����o�֐�Input�͒�`���Ȃ�
	void Sintro(void) {											// ���ȏЉ�
		cout << "�l�̖��O��" << name << "���j����!!\n";
	}
};

//===== ���y�b�g�N���X =====//
class Pmonkey : public Pet {
private:
	int age;													// �N��
public:
	Pmonkey(char* n = "", int a = 0) : Pet(n) { age = a; }
	void Input(void) {											// ����
		Pet::Input();
		cout << "�N�� : "; cin >> age;
	}
	void Sintro(void) {											// ���ȏЉ�
		cout << "�l��" << age << "�΂�" << name << "���L�b!!\n";
	}
};
