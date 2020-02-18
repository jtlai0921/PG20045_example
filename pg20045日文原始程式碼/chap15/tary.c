//----------------------------------------------------------------------------//
//	�z��N���X�e���v���[�g Ary �i�������j					"tary.c"          //
//----------------------------------------------------------------------------//


#include	"tary.h"

//--- �R�s�[�R���X�g���N�^ ---//
template <class Type> Ary <Type>::Ary(const Ary& x)
{
	ptr = new Type[x.size];
	size = x.size;
	for (int i = 0; i < size; i++)
		ptr[i] = x.ptr[i];
}

//--- ������Z�q ---//
template <class Type> Ary<Type>& Ary<Type>::operator=(const Ary& x)
{
	if (&x != this) {				// �������g�ւ͑�����Ȃ�
		delete[] ptr;
		ptr = new Type[x.size];
		size = x.size;
		for (int i = 0; i < size; i++)
			ptr[i] = x.ptr[i];
	}
	return (*this);
}

