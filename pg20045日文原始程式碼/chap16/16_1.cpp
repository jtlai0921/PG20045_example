/*
	日付クラスGdate 利用例
*/

#include	<iostream.h>

#include	"date.h"

int main(void)
{
	Date  Birthday(1963, 11, 18);

	Gdate Today;
	Gdate Date1(1995);
	Gdate Date2(10, Gdate::Meiji,  11, 18);
	Gdate Date3(10, Gdate::Taisho, 11, 18);
	Gdate Date4(10, Gdate::Showa,  11, 18);
	Gdate Date5(10, Gdate::Heisei, 11, 18);

	cout << "Birthday : " << Birthday << '\n';

	cout << "Today : " << Today << '\n';
	cout << "Date1 : " << Date1 << '\n';
	cout << "Date2 : " << Date2 << '\n';
	cout << "Date3 : " << Date3 << '\n';
	cout << "Date4 : " << Date4 << '\n';
	cout << "Date5 : " << Date5 << '\n';

	return (0);
}

/*
実行結果一例
Birthday : 1963年11月18日
Today : 平成8年11月18日
Date1 : 平成7年1月1日
Date2 : 明治10年11月18日
Date3 : 大正10年11月18日
Date4 : 昭和10年11月18日
Date5 : 平成10年11月18日
*/
