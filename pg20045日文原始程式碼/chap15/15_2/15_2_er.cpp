/*
	�X�^�b�N�N���X�e���v���[�g Stack�@�| ���p�� �|
*/

#include	<string.h>
#include	<iostream.h>

#include	"stack.h"

int main(void)
{
	char  x[256];

	cout << "���������͂��ĉ����� : ";
	cin >> x;

	Stack<char>	sc(strlen(x));

	for (int i = 0; x[i] != '\0'; i++)
		sc.Push(x[i]);

	try {
		for (int i = 0; i < strlen(x); i++) {
			char c = sc.Pop();
			cout << c;
		}
		cout << '\n';
	}
	catch (Stack<char>::EmptyErr x) {
		cout << "\n���<char>�X�^�b�N["  << x.Ptr()
		     << "]����|�b�v���悤�Ƃ��܂����B\n";
	}

	Stack<char> a(sc);				// �R���p�C���E�G���[

	Stack<char> b(100);
	b = sc;							// �R���p�C���E�G���[

	return (0);
}

/*
���s��
���������͂��Ă��������@�Fshibata��
atabihs
*/
