#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "���̐����l����͂��Ă��������F";
	cin >> a;

	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < a - i ; j++)		// �󔒂��o��
			cout << ' ';
		for (j = 0; j < i * 2 - 1 ; j++)	// '*'���o��
			cout << '*';
		cout << '\n';
	}

	return (0);
}

/*
���s��
���̐����l����͂��Ă��������F3��
    *
   ***
  *****
*/
