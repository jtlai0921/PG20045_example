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

//--- �E��n�r�b�g��]�����l��ԋp���� ---//
unsigned rrotate(unsigned x, int n)
{
	int		  bits = int_len();
	unsigned  tmp = x;
	return ((x >>= (n % bits)) | (tmp <<= (bits - (n % bits))));
}

//--- ����n�r�b�g��]�����l��ԋp���� ---//
unsigned lrotate(unsigned x, int n)
{
	int		  bits = int_len();
	unsigned	  tmp = x;
	return ((x <<= (n % bits)) | (tmp >>= (bits - (n % bits))));
}

int main(void)
{
	unsigned	x;
	int			n;

	cout << "���̐����l����͂��Ă��������F";		cin >> x;
	cout << "���r�b�g��]���܂����F";				cin >> n;

	cout << "���@�@�F";		print_bits(x);			     cout << '\n';
	cout << "�E��]�F";		print_bits(rrotate(x, n));   cout << '\n';
	cout << "����]�F";		print_bits(lrotate(x, n));   cout << '\n';

	return (0);
}

/*
���s���ʈ��
���̐����l����͂��Ă��������F565��
���r�b�g��]���܂����F4��
���@�@�F0000001000110101
�E��]�F0101000000100011
����]�F0010001101010000
*/
