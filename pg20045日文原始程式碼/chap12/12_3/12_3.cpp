/*
    ���t�N���X Date ��Q�� �| ���p�� �|
*/

#include	<iostream.h>

#include	"date.h"

int main(void)
{
	Date MyBirthday( 1963, 11, 18);
	Date UnivFukuoka(1995,  8, 23);
	Date Day[3];						// �z��

	cout << "MyBirthday = "  << MyBirthday  << '\n';
	cout << "UnivFukuoka = " << UnivFukuoka << '\n';

	for (int i = 0; i < 3; i++)
		cout << "Day[" << i << "] = " << Day[i] << '\n';

	return (0);
}

/*
���s����
MyBirthday = 1963�N11��18��
UnivFukuoka = 1995�N8��23��
Day[0] = 1996�N11��18��
Day[1] = 1996�N11��18��
Day[2] = 1996�N11��18��
*/
