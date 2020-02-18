/*
	銀行口座クラス Kouza　－ 利用例 －
*/

#include	<iostream.h>

#include	"kouza.h"

int main(void)
{
	Kouza	Nozawa(1234569,  0, 1991, 1, 1);
	Kouza	Miyata(3468924, 10, 1992, 2, 2);

	Nozawa.Ireru(100);		// 野沢君が100円預ける

	Miyata.Orosu(5);			// 宮田君が5円引き出す

	cout << "野沢君の口座\n";
	cout << "口座番号＝" << Nozawa.KouzaNo()  << '\n';
	cout << "預 金 額＝" << Nozawa.Yokingaku() << "円\n";
	cout << "開 設 日＝" << Nozawa.Kaisetsubi() << '\n';

	cout << "宮田君の口座\n";
	cout << "口座番号＝" << Miyata.KouzaNo()  << '\n';
	cout << "預 金 額＝" << Miyata.Yokingaku() << "円\n";
	cout << "開 設 日＝" << Miyata.Kaisetsubi() << '\n';

	return (0);
}

/*
実行結果
野沢君の口座
口座番号＝1234569
預 金 額＝100円
開 設 日＝1991年1月1日
宮田君の口座
口座番号＝3468924
預 金 額＝5円
開 設 日＝1992年2月2日
*/
