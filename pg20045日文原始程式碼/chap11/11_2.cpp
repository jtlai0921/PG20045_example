/*
	銀行口座クラス kouza　－ 利用例 －
*/

#include	<iostream.h>

#include	"kouza.h"

int main(void)
{
	kouza	nozawa(1234569,  0);		// 野沢君の銀行口座
	kouza	miyata(3468924, 10);		// 宮田君の銀行口座

	nozawa.ireru(100);				// 野沢君が100円預ける

	miyata.orosu(5);					// 宮田君が5円引き出す

	cout << "野沢君の口座\n";
	cout << "口座番号＝" << nozawa.kouza_no()  << '\n';
	cout << "預 金 額＝" << nozawa.yokingaku() << "円\n\n";

	cout << "宮田君の口座\n";
	cout << "口座番号＝" << miyata.kouza_no()  << '\n';
	cout << "預 金 額＝" << miyata.yokingaku() << "円\n";

	return (0);
}

/*
実行結果
野沢君の口座
口座番号＝1234569
預 金 額＝100円
宮田君の口座
口座番号＝3468924
預 金 額＝5円
*/
