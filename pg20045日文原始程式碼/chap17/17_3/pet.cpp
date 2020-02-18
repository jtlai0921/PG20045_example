//----------------------------------------------------------------------------//
//	継承版ペットクラス Pet（実現部）						"pet.c"           //
//----------------------------------------------------------------------------//

#include	<string.h>

#include	"pet.h"

//============================ class Pet ========================//

//--- ペットクラス・コンストラクタ ---//
Pet::Pet(char* n)
{
	strcpy(name, n);
}

//--- ペットクラス・ストリーム挿入演算子 ---//
ostream& operator<<(ostream& s, const Pet& p)
{
	// 名前だけを出力する
	return (s << "{ " << p.Name() << " }" );
}

//============================ class Pdog ========================//
//--- 犬クラス・コンストラクタ ---//
Pdog::Pdog(char* n, char* k) : Pet(n)
{
	strcpy(kname, k);
}

