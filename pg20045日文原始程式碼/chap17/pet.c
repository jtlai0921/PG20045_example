//----------------------------------------------------------------------------//
//	ペットクラス　Pet（実現部）								"pet.c"           //
//----------------------------------------------------------------------------//


#include	<string.h>

#include	"pet.h"

//--- コンストラクタ ---//
Pet::Pet(PetType t, char* n)
{
	kind = t;
	strcpy(name, n);
}

//--- 入力 ---//
void Pet::Input(void)
{
	int  k;
	do {
		cout << "種別 【0･･犬, 1･･猫, 2･･猿】 : ";
		cin >> k;
	} while (k < Dog || k > Monkey);
	kind = PetType(k);
	cout << "名前 : ";
	cin >> name;
}

//--- 自己紹介する ---//
void Pet::Sintro(void)
{
	cout << "僕は";
	switch (kind) {
	 case Dog :     cout << "犬"; break;
	 case Cat :     cout << "猫"; break;
	 case Monkey :  cout << "猿"; break;
	}
	cout << "で、名前は" << name << "って言うんだよ!!\n";
}

//--- ペットクラス・ストリーム挿入演算子 ---//
ostream& operator<<(ostream& s, const Pet& p)
{
	s << "{ ";
	switch (p.Type()) {
	 case Pet::Dog    : s << "犬, "; break;
	 case Pet::Cat    : s << "猫, "; break;
	 case Pet::Monkey : s << "猿, "; break;
	}
	s << p.Name() << " }";
	return (s);
}

