#include	<limits.h>
#include	<iostream.h>

int main(void)
{
	cout << "この処理系のchar型は、";
	if (CHAR_MIN)
		cout << "符号付き型です。\n";
	else
		cout << "符号なし型です。\n";

	return (0);
}

/*
実行結果一例
この処理系のchar型は、符号付き型です。*/
