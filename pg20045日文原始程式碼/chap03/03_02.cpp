#include	<iostream.h>

int main(void)
{
	char  c;

	while (cin.get(c))
		if (c == '\n')			// ���s�����ł���΁c
			cout << "[RET]\n";
		else						// �����łȂ���΁c
			cout << c;

	return (0);
}

/*
���s���ʈ��
This is pen.��
This is pen.
Are you ready?��
Are you ready?
Ctrl+Z
*/