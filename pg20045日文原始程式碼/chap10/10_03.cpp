#include	<string.h>
#include	<iostream.h>

int main(void)
{
	cout << "�����񃊃e����\"AB\\tC\"\n";
	cout << "strlen(\"AB\\tC\")          :" << strlen("AB\tC") << '\n';
	cout << "sizeof(\"AB\\tC\")          :" << sizeof("AB\tC") << "\n\n";

	cout << "�����񃊃e����\"ABC\\0XYZ\"\n";
	cout << "strlen(\"ABC\\0XYZ\")       :" << strlen("ABC\0XYZ") << '\n';
	cout << "sizeof(\"ABC\\0XYZ\")       :" << sizeof("ABC\0XYZ") << '\n';

	return (0);
}

/*
���s����
�����񃊃e����"AB\tC"
strlen("AB\tC")         :4
sizeof("AB\tC")         :5

�����񃊃e����"ABC\0XYZ"
strlen("ABC\0XYZ")      :3
sizeof("ABC\0XYZ")      :8
*/
