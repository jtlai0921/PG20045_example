//----------------------------------------------------------------------------//
//	�X�^�b�N�N���X�e���v���[�g Stack						"stack.h"         //
//----------------------------------------------------------------------------//


//===== �X�^�b�N�N���X�e���v���[�g =====//
template <class Type> class Stack {

private:
	int		size;				// �z��̗v�f��
	Type*	ptr;					// �擪�v�f�ւ̃|�C���^
	Type*	top;					// �X�^�b�N�|�C���^

	Stack(const Stack&);				// �R�s�[�R���X�g���N�^�𖳌���
	Stack& operator=(const Stack&);		// ������Z�q�𖳌���

public:
	//----- ��X�^�b�N����̃|�b�v�ɑ΂����O -----//
	class EmptyErr {
	private:
		Stack*	ident;
	public:
		EmptyErr(Stack* p) : ident(p) { }
		Stack* Ptr(void)  { return (ident); }
	};

	Stack(int sz) { ptr = top = new Type[size = sz]; }
	~Stack(void)  { delete[] ptr; }

	int Push(const Type &x) {			// �v�b�V��
		if (ptr - top < size) {
			*top++ = x;
			return (1);
		}
		return (0);
	}

	Type Pop(void) {					// �|�b�v
		if (top <= ptr)
			throw EmptyErr(this);		// �G���[���o
		return (*--top);
	}
};

