/*
	�����z��N���X IntAry�@�\���p��\
*/

#include	<iomanip.h>
#include	<iostream.h>

#include	"intary.h"

int main(void)
{
	int  i, n;

	cout << "���݂�IntAry�̐��F" << IntAry::GetCount() << '\n';

	cout << "�v�f������͂���F";
	cin >> n;

	IntAry  x(n);
	cout << "�N���XIntAry�̃I�u�W�F�N�gx���`���܂����B\n";
	cout << "���݂�IntAry�̐��F" << IntAry::GetCount() << '\n';

	for (i = 0; i < n; i++)
		x[i] = i;

	IntAry*  y = new IntAry(x);
	cout << "�N���XIntAry�̃I�u�W�F�N�g�𓮓I�ɐ������܂����B\n";
	cout << "���݂�IntAry�̐��F" << IntAry::GetCount() << '\n';

	cout << "    x    y\n";
	cout << "----------\n";
	for (i = 0; i < n; i++)
		cout << setw(5) << x[i] << setw(5) << y[i] << '\n';

	delete y;
	cout << "�N���XIntAry�̃I�u�W�F�N�g�����ł��������B\n";
	cout << "���݂�IntAry�̐��F" << IntAry::GetCount() << '\n';

	return (0);
}

