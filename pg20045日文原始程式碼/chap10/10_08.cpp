#include	<string.h>
#include	<iostream.h>

int main(void)
{
	char   ary[10] = "ABC";
	char*  ptr     = "ABC";

	cout << "�z�@�@��F" << ary << '\n';
	cout << "�|�C���^�F" << ptr << '\n';

	strcpy(ary, "12345");
	ptr = "12345";

	cout << "�z�@�@��F" << ary << '\n';
	cout << "�|�C���^�F" << ptr << '\n';

	return (0);
}

/*
���s����
�z�@�@��FABC
�|�C���^�FABC
�z�@�@��F12345
�|�C���^�F12345
*/
