//----------------------------------------------------------------------------//
//	�X�^�b�N�N���X Astack									"astack.h"        //
//----------------------------------------------------------------------------//


//#include	"tary.h"  // tary.h��14�͂ɂȂ��B
#include	"intary.h" // ���ύX

//===== �X�^�b�N�N���X =====//
template <class Type>
class Astack : public Ary<Type> {

private:
	int	top;
	Astack(const Astack&);					// �R�s�[�R���X�g���N�^�𖳌���
	Astack& operator=(const Astack&);		// ������Z�q

public:
	//----- ��X�^�b�N����̃|�b�v�ɑ΂����O -----//
	class EmptyErr {
	private:
		Astack*	ident;
	public:
		EmptyErr(Astack* a) : ident(a) { }
		Astack* Ptr(void) { return (ident); }
	};

	Astack(int a) : Ary<Type>(a) { top = 0; }
	
	int Push(const Type& a) {
		if (top - 1 < size) {
			ptr[top++] = a;
			return (1);
		}
		return (0);
	}
	
	Type Pop(void) {
		if (top < 1)
			throw EmptyErr(this);
		return (ptr[--top]);
	}
};

