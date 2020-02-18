//----------------------------------------------------------------------------//
//	ペットクラス Pet（インタフェース部）					"pet.h"           //
//----------------------------------------------------------------------------//

#include	<iostream.h>

//===== ペットクラス =====//
class Pet {

public:
	typedef char	PetName[20];
	enum PetType {Dog, Cat, Monkey};

private:
	PetType	kind;							// 種別
	PetName	name;							// 名前

public:
	Pet(PetType x = Dog, char* n = "");		// コンストラクタ

	PetType Type(void) { return (kind); }	// 種別を返却する
	char*   Name(void) { return (name); }	// 名前を返却する

	void Input(void);						// 入力
	void Sintro(void);						// 自己紹介を行う
};

ostream& operator<<(ostream&, const Pet&);  // 挿入演算子

