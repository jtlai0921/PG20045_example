//----------------------------------------------------------------------------//
//  �����z��N���X IntFixedAry �i�C���^�t�F�[�X���j			"IntFixedAry.h"   //
//----------------------------------------------------------------------------//


//===== �����z��N���X =====//
class IntFixedAry {

private:
	int	  size;				// �z��̗v�f��
	int*  ptr;				// �擪�v�f�ւ̃|�C���^

public:

	//----- �Y�����͈̓G���[ -----//
	class RangeErr {
	private:
		IntFixedAry*  ident;
		int			  index;
	public:
		RangeErr(IntFixedAry* p, int i) : ident(p), index(i) { }
		int Index(void)  { return (index); }
	};

	//----- �T�C�Y�G���[ -----//
	class SizeErr {
	private:
		IntFixedAry*  ident;
		int			  size;
	public:
		SizeErr(IntFixedAry* p, int i) : ident(p), size(i) { }
		int Size(void)  { return (size); }
	};

	IntFixedAry(int sz)          { ptr = new int[size = sz]; }

	IntFixedAry(const IntFixedAry&);

	~IntFixedAry(void)           { delete[] ptr; }			// �f�X�g���N�^

	int Size(void)               { return (size); }

	IntFixedAry& operator=(const IntFixedAry&);

	int& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);		// �Y�����͈̓G���[���o
		return (ptr[i]);
	}
};

