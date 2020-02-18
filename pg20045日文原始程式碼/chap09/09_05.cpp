#include	<except.h>
#include	<iostream.h>
#include	<new.h>
int main(void)
{
	int	  asize;
	int	  i;
	int*  a;

	cout << "生成する配列の要素数を入力してください：";
	cin >> asize;

	try {
		a = new int[asize];
	}

	catch (xalloc) {
		cout << "メモリの確保ができませんので、プログラムを終了します。\n";
		return (1);										// 異常終了
	}

	for (i = 0; i < asize; i++)
		a[i] = i;

	for (i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	delete[] a;

	return (0);											// 正常終了
}

/*
実行例（1）
生成する配列の要素数を入力してください：3000▼
メモリの確保ができませんので、プログラムを終了します。
実行例（2）
生成する配列の要素数を入力してください：3▼
a[0] = 0
a[1] = 1
a[2] = 2
*/
