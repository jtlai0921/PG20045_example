#include	<iostream.h>

#include	"date.h"

int main(void)
{
    typedef int (Date::*pcomp)(int) const;                                      
	pcomp		fcomp[] = {Date::CompY, Date::CompM, Date::CompD};
	int			menu;
	const Date	MyBirthday(1963, 11, 18);			//�ڪ��ͤ�

	cout << "�вq�q�ڪ��ͤ�C\n";
	do {
		cout << "0...�~   1...��   2...��   3...�����G";
		cin >> menu;
		if (menu >= 0 && menu <= 2) {
			int	value, diff;
			cout << "��J�ƭ�";
			cin >> value;

			diff = (MyBirthday.*fcomp[menu])(value);
			if (!diff)
				cout << "���T�C\n";
			else if (diff > 0)
				cout <<  diff << "�j�C\n";
			else
				cout << -diff << "�p�C\n";
		}
	} while (menu != 3);

	return (0);
}
