#include	<string.h>
#include	<iostream.h>

int main(void)
{
	char   ary[10] = "ABC";
	char*  ptr     = "ABC";

	cout << "配　　列：" << ary << '\n';
	cout << "ポインタ：" << ptr << '\n';

	strcpy(ary, "12345");
	ptr = "12345";

	cout << "配　　列：" << ary << '\n';
	cout << "ポインタ：" << ptr << '\n';

	return (0);
}

/*
実行結果
配　　列：ABC
ポインタ：ABC
配　　列：12345
ポインタ：12345
*/
