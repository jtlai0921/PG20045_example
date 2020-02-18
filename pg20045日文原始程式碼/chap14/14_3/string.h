//----------------------------------------------------------------------------//
//	文字列クラス String インタフェース部					"string.h"        //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== 文字列クラス =====//
class String {

private:
	int	  len;								// 文字列の長さ
	char*  ptr;								// 文字列へのポインタ

public:
	String(const char* s = "");				// コンストラクタ
	String(const String& s);				// コピーコンストラクタ

	~String(void);							// デストラクタ

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

