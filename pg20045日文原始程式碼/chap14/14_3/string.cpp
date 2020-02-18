//-------------------------------------------------------------//
//	文字列クラス String 実現部					"string.cpp"   //
//-------------------------------------------------------------//

#include	<string.h>
#include	<iostream.h>

#include	"string.h"

//--- コンストラクタ ---//
String::String(const char* s)
{
	len = strlen(s);
	ptr = new char[len + 1];
	strcpy(ptr, s);
}

//--- コピーコンストラクタ ---//
String::String(const String& s)
{
	len = s.len;
	ptr = new char[len + 1];
	strcpy(ptr, s.ptr);
}

//--- デストラクタ ---//
String::~String(void)
{
	delete[] ptr;
}

//--- 代入（String = char*） ---//
String& String::operator=(const char* st1)
{
	delete[] ptr;
	len = strlen(st1);
	ptr = new char[len + 1];
	strcpy(ptr, st1);

	return (*this);
}

//--- 代入（String = String） ---//
String& String::operator=(const String& st1)
{
	if (&st1 != this) {
		delete[] ptr;
		len += st1.len;
		ptr = new char[len + 1];
		strcpy(ptr, st1.ptr);
	}

	return (*this);
}

//--- 連結（String += char*） ---//
String& String::operator+=(const char* st1)
{
	len += strlen(st1);
	char* temp = new char[len+1];
	strcat(strcpy(temp, ptr), st1);
	delete[] ptr;
	ptr = temp;

	return (*this);
}

//--- 連結（String + String） ---//
String& String::operator+=(const String& st1)
{
	len += st1.len;
	char* temp = new char[len + 1];
	strcat(strcpy(temp, ptr), st1.ptr);
	delete[] ptr;
	ptr = temp;

	return (*this);
}

//--- 連結（String + String） ---//
String operator+(const String& st1, const String& st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- 連結（String + char*） ---//
String operator+(const String& st1, const char* st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- 連結（char* + String） ---//
String operator+(const char* st1, const String& st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- 等しいか？（String == String） ---//
int operator==(const String& st1, const String& st2)
{
	return (!strcmp(st1.ptr, st2.ptr));
}

//--- 等しいか？（String == char*） ---//
int operator==(const String& st1, const char* st2)
{
	return (!strcmp(st1.ptr, st2));
}

//--- 等しいか？（char* == String） ---//
int operator==(const char* st1, const String& st2)
{
	return (!strcmp(st1, st2.ptr));
}

//--- 等しくないか？（String != String） ---//
int operator!=(const String& st1, const String& st2)
{
	return (strcmp(st1.ptr, st2.ptr) != 0);
}

//--- 等しくないか？（String == char*） ---//
int operator!=(const String& st1, const char* st2)
{
	return (strcmp(st1.ptr, st2) != 0);
}

//--- 等しくないか？（char* == String） ---//
int operator!=(const char* st1, const String& st2)
{
	return (strcmp(st1, st2.ptr) != 0);
}

//--- 挿入演算子 ---//
ostream& operator<<(ostream& s, const String& str)
{
	return (s << (str.ptr));
}
