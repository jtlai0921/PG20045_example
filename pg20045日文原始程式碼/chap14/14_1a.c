//----------------------------------------------------------------------------//
//	�����z��N���X IntFixedAry �i�������j					"IntFixedAry.c"   //
//----------------------------------------------------------------------------//

#include	"IntFixedAry.h"

//--- �R�s�[�R���X�g���N�^ ---//
IntFixedAry::IntFixedAry(const IntFixedAry& x)
{
	ptr = new int[x.size];
	size = x.size;
	for (int i = 0; i < size; i++)
		ptr[i] = x.ptr[i];
}

//--- ������Z�q ---//
IntFixedAry& IntFixedAry::operator=(const IntFixedAry& x)
{
	if (x.size != size)						// �v�f�����قȂ�
		throw SizeErr(this, x.size);		// �T�C�Y�G���[���o	
	else {
		for (int i = 0; i < size; i++)
			ptr[i] = x.ptr[i];
	}
	return (*this);
}

