/*
	カウンタクラスファミリ　－利用例－
									"vcmain.c"
*/

#include    <iostream.h>

#include    "vcounter.h"

//--- 10回インクリメントしながら表示する ---//
void count(VCounter& c)
{
	for (int i = 0; i < 10; i++) {
		cout << c.Value() << ' ';
		c.Increment();
	}
}

int main(void)
{
	UnCounter  a;
	BnCounter  b(5);		// 上限値は5

	cout << "UnCounter  : ";
	count(a);
	cout << '\n';

	cout << "BnCounter : ";
	count(b);
	cout << '\n';

	return (0);
}

/*
実行結果
UnCounter  : 0 1 2 3 4 5 6 7 8 9 10
BnCounter : 0 1 2 3 4 5 5 5 5 5 5
*/
