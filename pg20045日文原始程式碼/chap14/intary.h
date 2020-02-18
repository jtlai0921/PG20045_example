//----------------------------------------------------------------------------//
//  �����z��N���X IntAry ��S�Łi�C���^�t�F�[�X���j		"intary.h"        //
//----------------------------------------------------------------------------//


//===== �����z��N���X =====//
class IntAry {

private:
	static int counter;
	static void CntUp(void) { counter++; }
	static void CntDn(void) { counter--; }

	int		size;				// �z��̗v�f��
	int*	ptr;					// �擪�v�f�ւ̃|�C���^

public:
	//----- �Y�����͈̓G���[ -----//
	class RangeErr {
	private:
		IntAry* ident;
		int		index;
	public:
		RangeErr(IntAry* p, int i) : ident(p), index(i) { }
		int Index(void)  { return (index); }
	};

	static int GetCount(void) { return (counter); }

	IntAry(int sz)          { ptr = new int[size = sz]; CntUp(); }
	IntAry(const IntAry&);

	~IntAry(void)           { delete[] ptr; CntDn(); }

	int Size(void)          { return (size); }

	IntAry& operator=(const IntAry&);

	int& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw RangeErr(this, i);		// �Y�����͈̓G���[���o
		return (ptr[i]);
	}
};

