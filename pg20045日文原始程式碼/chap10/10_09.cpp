#include	<string.h>
#include	<iostream.h>

int main(void)
{
	char*  dynamic = new char[8];
	strcpy(dynamic, "ABCD");

	cout << "文字列dynamic：" << dynamic << '\n';

	delete[] dynamic;

	return (0);
}

/*
実行結果
文字列dynamic：ABCD
*/
