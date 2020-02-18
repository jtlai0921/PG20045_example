//----------------------------------------------------------------------------//
//	【string】連想配列用２分木クラス AcAstring（実現部）	"acastrng.c"      //
//----------------------------------------------------------------------------//

#include	"acastrng.h"

//----- 添え字演算子 -----//
string& AcAstring::operator[](char* kstr)
{
	ANstring*& ptr = (ANstring*)*Search(&(BinNode*)tree, kstr);
	if (ptr == NULL)
		ptr = new ANstring(kstr, "");
	return (*ptr);
}

