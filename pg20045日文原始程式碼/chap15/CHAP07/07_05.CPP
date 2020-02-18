#include	<iostream.h>

int main(void)
{
	cout << "この処理系の負数のシフトは";
	if ((-8 >> 1) == -4)
		cout << "算術シフトです。\n";
	else
		cout << "論理シフトです。\n";

	return (0);
}

/*
実行結果一例
この処理系の負数のシフトは論理シフトです。*/