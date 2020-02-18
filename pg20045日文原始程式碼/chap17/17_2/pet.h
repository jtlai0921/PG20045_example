//----------------------------------------------------------------------------//
//	継承版ペットクラス Pet（インタフェース部）				"pet.h"           //
//----------------------------------------------------------------------------//

#include	<iostream.h>
//===== ペットクラス =====//
class Pet {
public:
	typedef char	PetName[20];
protected:
	PetName name;										// 名前
public:
	Pet(char* n="");										// コンストラクタ
	char*	Name(void) { return (name); }				// 名前を返却する
	virtual void Input(void)  {							//【仮想関数】
		cout << "名前 : "; cin >> name;					//  入力
	}
	virtual void Sintro(void) {							//【仮想関数】
		cout << "僕の名前は" << name << "です。\n";		//   自己紹介 
	}
};
ostream& operator<<(ostream&, const Pet&);				// 挿入演算子

//===== 犬ペットクラス =====//
class Pdog : public Pet {
public:
	typedef char		DogKind[20];
protected:
	DogKind kname;												// 種別
public:
	Pdog(char* n = "", char* k = "");
	void Input(void) {											// 入力
		Pet::Input();
		cout << "種別 : "; cin >> kname;
	}
	void Sintro(void) {											// 自己紹介
		cout << "僕は" << kname << "の" << name << "だワン!!\n";
	}
};

//===== 猫ペットクラス =====//
class Pcat : public Pet {
public:
	Pcat(char* n = "") : Pet(n) { }
	// メンバ関数Inputは定義しない
	void Sintro(void) {											// 自己紹介
		cout << "僕の名前は" << name << "だニャン!!\n";
	}
};

//===== 猿ペットクラス =====//
class Pmonkey : public Pet {
private:
	int age;													// 年齢
public:
	Pmonkey(char* n = "", int a = 0) : Pet(n) { age = a; }
	void Input(void) {											// 入力
		Pet::Input();
		cout << "年齢 : "; cin >> age;
	}
	void Sintro(void) {											// 自己紹介
		cout << "僕は" << age << "歳の" << name << "だキッ!!\n";
	}
};
