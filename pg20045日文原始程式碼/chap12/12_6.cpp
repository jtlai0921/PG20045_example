#include	<iostream.h>

#include	"date.h"

int main(void)
{
    typedef int (Date::*pcomp)(int) const;                                      
	pcomp		fcomp[] = {Date::CompY, Date::CompM, Date::CompD};
	int			menu;
	const Date	MyBirthday(1963, 11, 18);			// 私の誕生日

	cout << "私の誕生日を当ててください。\n";
	do {
		cout << "０…年　１…月　２…日　３…終了 ：";
		cin >> menu;
		if (menu >= 0 && menu <= 2) {
			int	value, diff;
			cout << "値を入力してください：";
			cin >> value;

			diff = (MyBirthday.*fcomp[menu])(value);
			if (!diff)
				cout << "正解です。\n";
			else if (diff > 0)
				cout <<  diff << "だけ大きいです。\n";
			else
				cout << -diff << "だけ小さいです。\n";
		}
	} while (menu != 3);

	return (0);
}

/*
実行例
私の誕生日を当ててください。
０･･･年　１･･･月　２･･･日　３･･･終了：0▼
値を入力してください：1964▼
1だけ大きいです。
０･･･年　１･･･月　２･･･日　３･･･終了：0▼
値を入力してください：1963▼
正解です。
０･･･年　１･･･月　２･･･日　３･･･終了：1▼
値を入力してください：11▼
正解です。
０･･･年　１･･･月　２･･･日　３･･･終了：3▼
*/
