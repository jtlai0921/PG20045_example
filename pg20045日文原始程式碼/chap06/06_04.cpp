#include	<iostream.h>

void func(void)
{
	int         ax = 0;			// ©®L¯õ½
	static int  sx = 0;			// ÃIL¯õ½

	cout << "axF" << ax << "  sxF" << sx << '\n';
	ax++;	sx++;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		func();

	return (0);
}

/*
ÀsÊ
ax : 0  sx : 0
ax : 0  sx : 1
ax : 0  sx : 2
ax : 0  sx : 3
ax : 0  sx : 4
ax : 0  sx : 5
ax : 0  sx : 6
ax : 0  sx : 7
ax : 0  sx : 8
ax : 0  sx : 9
*/
