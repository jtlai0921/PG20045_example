//----------------------------------------------------------------------------//
//	�y�b�g���`���X�g�N���X PetList�i�������j				"petlist.c"       //
//----------------------------------------------------------------------------//

#include	<iostream.h>

#include	"petlist.h"

//---�R���X�g���N�^ ---//
PetList::PetList(void)
{
	Pet* x = new Pet(Pet::Dog, "DUMMY");		// �_�~�[�m�[�h�쐬
	top = bottom = new PetNode(x);
}

//--- �f�X�g���N�^ ---//
PetList::~PetList(void)
{
	Clear();									// �S�v�f���폜
	delete top;								// �_�~�[�m�[�h���
}

//--- ���X�g�̖����v�f�ւ̃|�C���^ ---//
PetNode* PetList::Bottom(void)
{
	if (top == bottom)
		return (NULL);
	else {
		PetNode* ptr = top;
		while (ptr->next != bottom)
			ptr = ptr->next;
		return (ptr);
	}
}

//--- ���X�g�̐擪�ɗv�f��}�� ---//
PetList& PetList::Insert(PetNode* x)
{
	PetNode* ptr = top;
	top = x;
	top->next = ptr;
	return (*this);
}

//--- ���X�g�̖����ɗv�f��ǉ� ---//
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

//---  ���X�g�擪�̗v�f���폜 ---//
PetList& PetList::Delete(void)
{
	if (top != bottom) {
		PetNode* ptr = top->next;
		delete top;
		top = ptr;
	}
	return (*this);
}

//---  ���X�g���̑S�v�f���폜 ---//
PetList& PetList::Clear(void)
{
	PetNode* ptr = top;
	while (ptr != bottom) {
		PetNode* next = ptr->next;
		delete ptr;
		ptr = next;	
	}
	top = bottom;
	return (*this);
}

//---  ���X�g�����̗v�f���폜 ---//
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
	}
	return (*this);
}

//---  ���ȏЉ� ---//
PetList& PetList::Introduce(void)
{
	PetNode* ptr = top;
	cout << "<<---------------- ���ȏЉ� ---------------->>\n";
	while (ptr != bottom) {
		ptr->pet->Sintro();
		ptr = ptr->next;
	}
	cout << "<<------------------------------------------>>\n";
	return (*this);
}

//---  �y�b�g���X�g�E�X�g���[���}�����Z�q ---//
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

