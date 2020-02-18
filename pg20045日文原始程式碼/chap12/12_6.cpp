#include	<iostream.h>

#include	"date.h"

int main(void)
{
    typedef int (Date::*pcomp)(int) const;                                      
	pcomp		fcomp[] = {Date::CompY, Date::CompM, Date::CompD};
	int			menu;
	const Date	MyBirthday(1963, 11, 18);			// ���̒a����

	cout << "���̒a�����𓖂ĂĂ��������B\n";
	do {
		cout << "�O�c�N�@�P�c���@�Q�c���@�R�c�I�� �F";
		cin >> menu;
		if (menu >= 0 && menu <= 2) {
			int	value, diff;
			cout << "�l����͂��Ă��������F";
			cin >> value;

			diff = (MyBirthday.*fcomp[menu])(value);
			if (!diff)
				cout << "�����ł��B\n";
			else if (diff > 0)
				cout <<  diff << "�����傫���ł��B\n";
			else
				cout << -diff << "�����������ł��B\n";
		}
	} while (menu != 3);

	return (0);
}

/*
���s��
���̒a�����𓖂ĂĂ��������B
�O����N�@�P������@�Q������@�R����I���F0��
�l����͂��Ă��������F1964��
1�����傫���ł��B
�O����N�@�P������@�Q������@�R����I���F0��
�l����͂��Ă��������F1963��
�����ł��B
�O����N�@�P������@�Q������@�R����I���F1��
�l����͂��Ă��������F11��
�����ł��B
�O����N�@�P������@�Q������@�R����I���F3��
*/
