
#include	<iostream.h>

//--- ����������1�ł���r�b�g�̐���ԋp���� ---//
int count_bits(unsigned x)
{
	int	 count = 0;
	while (x != 0) {
		if (x & 1) count++;
		x >>= 1;				// x = x >> 1;
	}
	return (count);
}

//--- int�^�̃r�b�g����ԋp���� ---//
int int_len(void)
{
	unsigned  x = ~0;
	return (count_bits(x));
}

//--- ���̃r�b�g�\����\������ ---//
void print_bits(unsigned x)
{
	for (int i = int_len() - 1; i >= 0; i--)
		cout << ((x >> i) & 1) ? '1' : '0';
}

int main(void)
{
	unsigned  x;
	char  cont;				// �����𑱍s���邩

	do {
		cout << "���̐����l����͂��Ă��������F";
		cin >> x;

		cout << "���̐��̃r�b�g�\���͈ȉ��̒ʂ�ł��B\n";
		print_bits(x);
		cout << '\n';

		cout << "�����𑱂��܂����H�i�x�^�m�j";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

	return (0);
}

/*
���s���ʈ��
���̐����l����͂��Ă��������F10��
���̐��̃r�b�g�\���͈ȉ��̒ʂ�ł��B
0000000000001010
�����𑱂��܂����H�i�x�^�m�jY��
���̐����l����͂��Ă��������F255��
���̐��̃r�b�g�\���͈ȉ��̒ʂ�ł��B
0000000011111111
�����𑱂��܂����H�i�x�^�m�jN��
*/
