//-------------------------------------------------------------//
//	������N���X String ������					"string.cpp"   //
//-------------------------------------------------------------//

#include	<string.h>
#include	<iostream.h>

#include	"string.h"

//--- �R���X�g���N�^ ---//
String::String(const char* s)
{
	len = strlen(s);
	ptr = new char[len + 1];
	strcpy(ptr, s);
}

//--- �R�s�[�R���X�g���N�^ ---//
String::String(const String& s)
{
	len = s.len;
	ptr = new char[len + 1];
	strcpy(ptr, s.ptr);
}

//--- �f�X�g���N�^ ---//
String::~String(void)
{
	delete[] ptr;
}

//--- ����iString = char*�j ---//
String& String::operator=(const char* st1)
{
	delete[] ptr;
	len = strlen(st1);
	ptr = new char[len + 1];
	strcpy(ptr, st1);

	return (*this);
}

//--- ����iString = String�j ---//
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

//--- �A���iString += char*�j ---//
String& String::operator+=(const char* st1)
{
	len += strlen(st1);
	char* temp = new char[len+1];
	strcat(strcpy(temp, ptr), st1);
	delete[] ptr;
	ptr = temp;

	return (*this);
}

//--- �A���iString + String�j ---//
String& String::operator+=(const String& st1)
{
	len += st1.len;
	char* temp = new char[len + 1];
	strcat(strcpy(temp, ptr), st1.ptr);
	delete[] ptr;
	ptr = temp;

	return (*this);
}

//--- �A���iString + String�j ---//
String operator+(const String& st1, const String& st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- �A���iString + char*�j ---//
String operator+(const String& st1, const char* st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- �A���ichar* + String�j ---//
String operator+(const char* st1, const String& st2)
{
	String temp = st1;
	temp += st2;
	return (temp);
}

//--- ���������H�iString == String�j ---//
int operator==(const String& st1, const String& st2)
{
	return (!strcmp(st1.ptr, st2.ptr));
}

//--- ���������H�iString == char*�j ---//
int operator==(const String& st1, const char* st2)
{
	return (!strcmp(st1.ptr, st2));
}

//--- ���������H�ichar* == String�j ---//
int operator==(const char* st1, const String& st2)
{
	return (!strcmp(st1, st2.ptr));
}

//--- �������Ȃ����H�iString != String�j ---//
int operator!=(const String& st1, const String& st2)
{
	return (strcmp(st1.ptr, st2.ptr) != 0);
}

//--- �������Ȃ����H�iString == char*�j ---//
int operator!=(const String& st1, const char* st2)
{
	return (strcmp(st1.ptr, st2) != 0);
}

//--- �������Ȃ����H�ichar* == String�j ---//
int operator!=(const char* st1, const String& st2)
{
	return (strcmp(st1, st2.ptr) != 0);
}

//--- �}�����Z�q ---//
ostream& operator<<(ostream& s, const String& str)
{
	return (s << (str.ptr));
}
