//----------------------------------------------------------------------------//
//	ペット線形リストクラス PetList（インタフェース部）		"petlist.h"       //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"pet.h"

//----- ペットノードクラス -----//
class PetNode {

	friend class  PetList;

private:
	Pet*     pet;			// ペットのデータ
	PetNode* next;			// 後続ノードへのポインタ

public:
	PetNode(Pet* ptr) : pet(ptr) { next = NULL; }		// コンストラクタ
	~PetNode(void)			{ delete pet; }				// デストラクタ

	PetNode* Next(void)		{ return (next); }			// 後続ノード
	operator Pet*(void)		{ return (pet);  }			// 変換関数
};

//----- ペット線形リストクラス -----//
class PetList {
	//  このクラスは、クラスPetのフレンドです

	friend ostream& operator<<(ostream& s, const PetList& x);

private:
	PetNode*  top;			// 先頭ノードへのポインタ
	PetNode*  bottom;		// 末尾ダミーノードへのポインタ

public:
	PetList(void);										// コンストラクタ
	~PetList(void);										// デストラクタ

	PetNode* Top(void) { return ((top == bottom) ? NULL : top); }
	PetNode* Bottom(void);

	PetList& Insert(PetNode*);							// 先頭へのノード挿入
	PetList& Append(PetNode*);							// 末尾へのノード追加
	PetList& Delete(void);								// 先頭ノードの削除
	PetList& Remove(void);								// 末尾ノードの削除
	PetList& Clear(void);								// 全ノードの削除

	PetList& Introduce(void);							// 自己紹介
};

ostream& operator<<(ostream&, const PetList&);			// 挿入演算子

