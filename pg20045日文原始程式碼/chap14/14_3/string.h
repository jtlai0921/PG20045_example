//----------------------------------------------------------------------------//
//	������N���X String �C���^�t�F�[�X��					"string.h"        //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== ������N���X =====//
class String {

private:
	int	  len;								// ������̒���
	char*  ptr;								// ������ւ̃|�C���^

public:
	String(const char* s = "");				// �R���X�g���N�^
	String(const String& s);				// �R�s�[�R���X�g���N�^

	~String(void);							// �f�X�g���N�^

	int Length(void) const { return (len); }

	String&  operator=(const char* st1);
	String&  operator=(const String& st1);

	String&  operator+=(const char* st1);
	String&  operator+=(const String& st1);

	friend String operator+(const String& st1, const String& st2);
	friend String operator+(const String& st1, const char*   st2);
	friend String operator+(const char*   st1, const String& st2);

	friend int operator==(const String& st1, const String& st2);
	friend int operator==(const String& st1, const char*   st2);
	friend int operator==(const char*   st1, const String& st2);

	friend int operator!=(const String& st1, const String& st2);
	friend int operator!=(const String& st1, const char*   st2);
	friend int operator!=(const char*   st1, const String& st2);

	friend ostream& operator<<(ostream& s,const String& str);
};

