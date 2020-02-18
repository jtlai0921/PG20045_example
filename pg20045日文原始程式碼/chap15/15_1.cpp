/*
	配列クラステンプレート　－ 利用例 －
*/

#include	<new.h>
#include	<iomanip.h>
#include	<iostream.h>

#include	"tary.h"

void f(void)
{
	try {
		Ary<int>	x(20);
		Ary<double>	y(10);
		for (int i = 0; i < 10; i++) {
			x[i] = i;
			y[i] = i;
		}
	}
	catch (Ary<int>::RangeErr x) {
		cout << "添え字オーバーフロー<int> : " << x.Index() << '\n';
		return;
	}
	catch (Ary<double>::RangeErr x) {
		cout << "添え字オーバーフロー<double> : " << x.Index() << '\n';
		return;
	}
	catch (xalloc) {
		cout << "メモリの確保に失敗しました。\n";
		exit (1);									// 強制終了
	}

	cout << "関数ｆは無事終了しました。\n";
}

int main(void)
{
	f();

	cout << "関数ｆからmain関数へ戻ってきました。\n";

	return (0);
}

/*
実行結果一例
関数ｆは無事終了しました。
関数ｆからmain関数へ戻ってきました。
*/