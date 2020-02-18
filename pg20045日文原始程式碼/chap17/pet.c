//----------------------------------------------------------------------------//
//	�y�b�g�N���X�@Pet�i�������j								"pet.c"           //
//----------------------------------------------------------------------------//


#include	<string.h>

#include	"pet.h"

//--- �R���X�g���N�^ ---//
Pet::Pet(PetType t, char* n)
{
	kind = t;
	strcpy(name, n);
}

//--- ���� ---//
void Pet::Input(void)
{
	int  k;
	do {
		cout << "��� �y0����, 1���L, 2�����z : ";
		cin >> k;
	} while (k < Dog || k > Monkey);
	kind = PetType(k);
	cout << "���O : ";
	cin >> name;
}

//--- ���ȏЉ�� ---//
void Pet::Sintro(void)
{
	cout << "�l��";
	switch (kind) {
	 case Dog :     cout << "��"; break;
	 case Cat :     cout << "�L"; break;
	 case Monkey :  cout << "��"; break;
	}
	cout << "�ŁA���O��" << name << "���Č����񂾂�!!\n";
}

//--- �y�b�g�N���X�E�X�g���[���}�����Z�q ---//
ostream& operator<<(ostream& s, const Pet& p)
{
	s << "{ ";
	switch (p.Type()) {
	 case Pet::Dog    : s << "��, "; break;
	 case Pet::Cat    : s << "�L, "; break;
	 case Pet::Monkey : s << "��, "; break;
	}
	s << p.Name() << " }";
	return (s);
}

