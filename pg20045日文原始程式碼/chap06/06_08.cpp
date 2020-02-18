#include	<iostream.h>

//--- xへの参照を返却する関数 ---//
int& ref(void)
{
	static int  x;			// xは静的記憶寿命

	return (x);
}

int main(void)
{
	ref() = 5;									// ref()へ値を代入

	cout << "ref() = " << ref() << '\n';		// ref()の値を表示

	return (0);
}

/*
実行結果
ref() = 5
*/
