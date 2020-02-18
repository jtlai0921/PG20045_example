//----------------------------------------------------------------------------//
//	継承版ペット線形リストクラスPetList（実現部）			"petlist.c"       //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"petlist.h"

//--- コンストラクタ ---//
PetList::PetList(void)
{
	Pet* x = new Pdog("DUMMY");				// ダミーノード作成
	top = bottom = new PetNode(x);
}

//--- デストラクタ ---//
PetList::~PetList(void)
{
	Clear();
	delete top;								// ダミーノード解放
}

//--- リストの末尾要素へのポインタ ---//
PetNode* PetList::Bottom(void)
{
	if (top == bottom) return (NULL);
	PetNode* ptr = top;
	while (ptr->next != bottom)
		ptr = ptr->next;
	return (ptr);
}

//--- リストの先頭に要素を挿入 ---//
PetList& PetList::Insert(PetNode* x)
{
	PetNode* ptr = top;
	top = x;
	top->next = ptr;
	return (*this);
}

//--- リストの末尾に要素を追加 ---//
PetList& PetList::Append(PetNode* x)
{
	if (top == bottom)
		Insert(x);
	else {
		PetNode* ptr = Bottom();
		ptr->next = x;
		x->next = bottom;
	}
	return (*this);
}

//--- リスト先頭の要素を削除 ---//
PetList& PetList::Delete(void)
{
	if (top != bottom) {
		PetNode* ptr = top->next;
		delete top;
		top = ptr;
	}
	return (*this);
}

//---  リスト末尾の要素を削除 -----//
PetList& PetList::Remove(void)
{
	if (top == bottom)
		;
	else if (top->next == bottom)
		Delete();
	else {
		PetNode* now = top;
		PetNode* pre;
	while (now->next != bottom) {
		pre = now;
		now = now->next;
	}
	pre->next = bottom;
	delete now;

	return (*this);
}

//--- リスト中の全要素を削除 ---//
PetList& PetList::Clear(void)
{
	PetNode* ptr = bottom;
	while (ptr != bottom) {
		PetNode* next = ptr->next;
		delete ptr;
		ptr = next;
	}
	top = bottom;
	return (*this);
}

//-----  自己紹介 -----//
PetList& PetList::Introduce(void)
{
	PetNode* ptr = top;
	cout << "<<---------------- 自己紹介 ---------------->>\n";
	while (ptr != bottom) {
		ptr->pet->Sintro();
		ptr = ptr->next;
	}
	cout << "<<------------------------------------------>>\n";
	return (*this);
}

//-----  ペットリスト・ストリーム挿入演算子 -----//
ostream& operator<<(ostream& s, const PetList& x)
{
	PetNode* ptr = x.top;
	s << "{\n";
	while (ptr != x.bottom) {
		s << '\t' << *(Pet*)(*ptr) << '\n';
		ptr = ptr->Next();
	}
	s << "}\n";
	return (s);
}

