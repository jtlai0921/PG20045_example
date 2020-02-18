#include	<iostream.h>

//int count_bits(unsigned x)		{ /*--- �ȗ��E���7-6���Q�Ƃ��� ---*/ }
//int int_len(void)				{ /*--- �ȗ��E���7-6���Q�Ƃ��� ---*/ }
//void print_bits(unsigned x)		{ /*--- �ȗ��E���7-6���Q�Ƃ��� ---*/ }

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

//--- x������n�r�b�g�V�t�g�����l��ԋp ---//
inline unsigned Lsft(unsigned x, int n)
{
	return ((n >= int_len()) ? 0 : (x << n));
}

//--- x��pos�r�b�g�ڂ���n�r�b�g��1�ɂ����l��ԋp ---//
unsigned set_n(unsigned x, int pos, int n)
{
	return (x | Lsft(~Lsft(~0U, n), pos - 1));
}

//--- x��pos�r�b�g�ڂ���n�r�b�g��0�ɂ����l��ԋp ---//
unsigned reset_n(unsigned x, int pos, int n)
{
	return (x & ~Lsft(~Lsft(~0U, n), pos - 1));
}

//--- x��pos�r�b�g�ڂ���n�r�b�g�𔽓]�����l��ԋp ---//
unsigned inverse_n(unsigned x, int pos, int n)
{
	return (x ^ Lsft(~Lsft(~0U, n), pos - 1));
}

int main(void)
{
	unsigned  x;
	int  a, b;

	cout << "���̐����l����͂��Ă��������F";					cin >> x;
	cout << "���삷��r�b�g�̊J�n�ʒu����͂��Ă��������F";		cin >> a;
	cout << "���삷��r�b�g������͂��Ă��������F";				cin >> b;
	cout << "x                 :"; print_bits(x);				  cout << '\n';
	cout << "set_n(x, a, b)    :"; print_bits(set_n(x, a, b));	  cout << '\n';
	cout << "reset_n(x, a, b)  :"; print_bits(reset_n(x, a, b));  cout << '\n';
	cout << "inverse_n(x, a, b):"; print_bits(inverse_n(x, a, b));cout << '\n';

	return (0);
}	
