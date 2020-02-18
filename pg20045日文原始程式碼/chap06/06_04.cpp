#include	<iostream.h>

void func(void)
{
	int         ax = 0;			// 自動記憶寿命
	static int  sx = 0;			// 静的記憶寿命

	cout << "ax：" << ax << "  sx：" << sx << '\n';
	ax++;	sx++;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		func();

	return (0);
}

/*
実行結果
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
