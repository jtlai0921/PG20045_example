#include	<limits.h>
#include	<iostream.h>

int main(void)
{
	cout << "���̏����n��char�^�́A";
	if (CHAR_MIN)
		cout << "�����t���^�ł��B\n";
	else
		cout << "�����Ȃ��^�ł��B\n";

	return (0);
}

/*
���s���ʈ��
���̏����n��char�^�́A�����t���^�ł��B*/
