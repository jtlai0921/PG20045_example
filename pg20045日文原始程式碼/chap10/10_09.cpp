#include	<string.h>
#include	<iostream.h>

int main(void)
{
	char*  dynamic = new char[8];
	strcpy(dynamic, "ABCD");

	cout << "������dynamic�F" << dynamic << '\n';

	delete[] dynamic;

	return (0);
}

/*
���s����
������dynamic�FABCD
*/
