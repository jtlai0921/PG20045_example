#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "�����l����͂���F";
	cin >> a;

	if (a > 0) {						// �ǂݍ��񂾐����l�����ł���΁c
		do {
			cout << a % 10;				// �����Ƃ����̌��̐������o��
			a = a / 10;					// �E�ɂP�����炷
		} while (a > 0);
		cout << '\n';
	}

	return (0);
}

/*
���s��
�����l����͂���F1235��
5321
*/