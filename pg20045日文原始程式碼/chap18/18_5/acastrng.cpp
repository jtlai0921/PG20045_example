//----------------------------------------------------------------------------//
//	�ystring�z�A�z�z��p�Q���؃N���X AcAstring�i�������j	"acastrng.c"      //
//----------------------------------------------------------------------------//

#include	"acastrng.h"

//----- �Y�������Z�q -----//
string& AcAstring::operator[](char* kstr)
{
	ANstring*& ptr = (ANstring*)*Search(&(BinNode*)tree, kstr);
	if (ptr == NULL)
		ptr = new ANstring(kstr, "");
	return (*ptr);
}

