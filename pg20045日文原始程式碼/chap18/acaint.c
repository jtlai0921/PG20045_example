//---------------------------------------------------------------------------//
//	yintzAzzρNX AcAint iΐ»j					"acaint.c"       //
//---------------------------------------------------------------------------//

#include	"acaint.h"

//----- Y¦Zq -----//
int& AcAint::operator[](char* kstr)
{
	ANint*& ptr = (ANint*)*Search(&(BinNode*)tree, kstr);
	if (ptr == NULL)
		ptr = new ANint(kstr);
	return (ptr->data);
}

