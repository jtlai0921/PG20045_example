#include	<iostream.h>

//--- x�ւ̎Q�Ƃ�ԋp����֐� ---//
int& ref(void)
{
	static int  x;			// x�͐ÓI�L������

	return (x);
}

int main(void)
{
	ref() = 5;									// ref()�֒l����

	cout << "ref() = " << ref() << '\n';		// ref()�̒l��\��

	return (0);
}

/*
���s����
ref() = 5
*/
