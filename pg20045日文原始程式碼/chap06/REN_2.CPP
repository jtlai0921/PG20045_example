#include  <iostream.h>

//--- ｘへの参照を返却する関数 ---//
int& ref(void)
{
	static int  x = 3;

	return (x);
}

int main(void)
{
	ref() = 5;		// ref()へ値を代入

	cout << "ref() = " << ref() << '\n';

	return (0);
}
