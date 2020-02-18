/*
	カウンタクラス　－利用例－					"bsmain.c"
*/

#include	<iostream.h>

#include	"bsco.h"

//--- 10回インクリメントしながら表示する ---//
void count(BsCounter& c)
{
	for (int i = 0; i < 10; i++) {
		cout << c.Value() << ' ';
		c.Increment();
	}
}

int main(void)
{
	BsCounter   a;
	BndCounter  b(5);						// 上限値は5

	cout << "BsCounter  : ";
	count(a);
	cout << '\n';

	cout << "BndCounter : ";
	count(b);
	cout << '\n';

	return (0);
}

/*実行結果
BsCounter  : 0 1 2 3 4 5 6 7 8 9 10
BndCounter : 0 1 2 3 4 5 5 5 5 5 5
*/
