#include	<string.h>
#include	<iostream.h>

int main(void)
{
	char*  dynamic = new char[8];
	strcpy(dynamic, "ABCD");

	cout << "•¶Žš—ñdynamicF" << dynamic << '\n';

	delete[] dynamic;

	return (0);
}

/*
ŽÀsŒ‹‰Ê
•¶Žš—ñdynamicFABCD
*/
