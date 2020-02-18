#include	<iostream.h>

#include	"date.h"

int main(void)
{
    typedef int (Date::*pcomp)(int) const;                                      
	pcomp		fcomp[] = {Date::CompY, Date::CompM, Date::CompD};
	int			menu;
	const Date	MyBirthday(1963, 11, 18);			//我的生日

	cout << "請猜猜我的生日。\n";
	do {
		cout << "0...年   1...月   2...日   3...結束：";
		cin >> menu;
		if (menu >= 0 && menu <= 2) {
			int	value, diff;
			cout << "輸入數值";
			cin >> value;

			diff = (MyBirthday.*fcomp[menu])(value);
			if (!diff)
				cout << "正確。\n";
			else if (diff > 0)
				cout <<  diff << "大。\n";
			else
				cout << -diff << "小。\n";
		}
	} while (menu != 3);

	return (0);
}
