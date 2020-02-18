//----------------------------------------------------------------------------//
//	�z��N���X�e���v���[�g Ary�i�C���^�t�F�[�X���j			"tary.h"          //
//----------------------------------------------------------------------------//


//===== �z��N���X�e���v���[�g =====//
template <class Type> class Ary {

private:
	int		size;				// �z��̗v�f��
	Type*	ptr;					// �擪�v�f�ւ̃|�C���^

public:
	//----- �Y�����͈̓G���[ -----//
	class RangeErr {
	private:
		Ary*	 ident;
		int	 index;
	public:
		RangeErr(Ary* p, int i) : ident(p), index(i) {}
		int Index(void)	{ return (index); }
	};

	Ary(int sz)			{ ptr = new Type[size = sz]; }	// �R���X�g���N�^
	Ary(const Ary&);									// �R�s�[�R���X�g���N�^

	~Ary(void)			{ delete[] ptr; }				// �f�X�g���N�^

	Ary& operator=(const Ary&);							// ������Z�q

	Type& operator[](int i)								// �Y�������Z�q
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);			// �Y�����͈̓G���[���o
		return (ptr[i]);
	}
};

