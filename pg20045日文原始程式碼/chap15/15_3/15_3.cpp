/*
	�L���[�N���X�e���v���[�g�@�|���p��|
*/

#include	<string.h>
#include	<iostream.h>

#include	"queue.h"

int main(void)
{
	Queue<int>	Q(10);
	int			menu;

	do {
		cout << "(1)�ǉ��@(2)��o���@(3)����@(0)�I��\n";
		cin >> menu;

		switch (menu) {
		 int data;
		 case 1 : cout << "��������͂��� : ";
				  cin >> data;	Q.Add(data); break;
		 case 2 : try {
					  cout << Q.Remove() << "�����o���܂����B\n";
				  }
				  catch (Queue<int>::EmptyErr x) {
					  cout << "�L���[�͋�ł���!!\n";
				  }
				  break;
		 case 3 : cout << Q; break;
		}
	} while(menu);

	return (0);
}

/*
���s��
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
1��
��������͂���F5��
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
1��
��������͂���F8��
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
1��
��������͂���F10��
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
3��
{ 5 8 10 }
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
2��
5�����o���܂����B
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
3��
{ 8 10 }
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
1��
��������͂���F5��
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
3��
{ 8 10 5 }
(�P)�ǉ��@(�Q)��o��(�R)����@(�S)�I��
4��
*/
