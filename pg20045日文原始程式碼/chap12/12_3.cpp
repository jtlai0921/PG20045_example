/*
    日付クラス Date 第２版 － 利用例 －
*/

#include	<iostream.h>

#include	"date.h"

int main(void)
{
	Date MyBirthday( 1963, 11, 18);
	Date UnivFukuoka(1995,  8, 23);
	Date Day[3];						// 配列

	cout << "MyBirthday = "  << MyBirthday  << '\n';
	cout << "UnivFukuoka = " << UnivFukuoka << '\n';

	for (int i = 0; i < 3; i++)
		cout << "Day[" << i << "] = " << Day[i] << '\n';

	return (0);
}

/*
実行結果
MyBirthday = 1963年11月18日
UnivFukuoka = 1995年8月23日
Day[0] = 1996年11月18日
Day[1] = 1996年11月18日
Day[2] = 1996年11月18日
*/
