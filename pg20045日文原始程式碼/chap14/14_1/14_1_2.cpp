/*
	整数配列クラス IntFixedAry 　－ 利用例 －
*/

//#include	<new.h>
#include	<except.h>
#include	<iomanip.h>
#include	<iostream.h>

#include	"intfixa.h"

void f(void)
{
	try {
		IntFixedAry	x(10);
		for (int i = 0; i < 10; i++)	//①
			x[i] = i;
	}
	catch (IntFixedAry::RangeErr x) {
		cout << "添え字オーバーフロー : " << x.Index() << '\n';
		return;
	}
	catch (xalloc) {
		cout << "メモリの確保に失敗しました。\n";
		exit (1);									// 強制終了
	}

	cout << "関数ｆは無事終了しました。\n";
}

void g(void)
{
	try {
		IntFixedAry	x(5);
		IntFixedAry	y(10);	//②

		x = y;
	}
	catch (IntFixedAry::SizeErr x) {
		cout << "サイズエラー         : " << x.Size()  << '\n';
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

	g();
	cout << "関数ｇからmain関数へ戻ってきました。\n";

	return (0);
}

/*実行結果一例
添え字オーバーフロー：10
関数ｆからmain関数に戻ってきました。
サイズエラー        ：20
関数ｇからmain関数に戻ってきました。

実行結果一例
関数ｆは無事終了しました。
関数ｆからmain関数に戻ってきました。
サイズエラー        ：20
関数ｇからmain関数に戻ってきました。

実行結果一例
関数ｆは無事終了しました。
関数ｆからmain関数に戻ってきました。
関数ｇは無事終了しました。
関数ｇからmain関数に戻ってきました。
*/
