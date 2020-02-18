//---------------------------------------------------------------------------//
//	yintz˜A‘z”z—ñƒNƒ‰ƒX AcAint iÀŒ»•”j					"acaint.c"       //
//---------------------------------------------------------------------------//

#include	"acaint.h"

//----- “Y‚¦š‰‰Zq -----//
int& AcAint::operator[](char* kstr)
{
	ANint*& ptr = (ANint*)*Search(&(BinNode*)tree, kstr);
	if (ptr == NULL)
		ptr = new ANint(kstr);
	return (ptr->data);
}

