#include	<iostream.h>

//--- �Q�̂����ԋp���� ---//
int pow2(unsigned n)
{
	int	 beki = 1;
	for (int i = 0; i < n; i++)
		beki *= 2;
	return (beki);
}

int main(void)
{
	unsigned  a, n;

	cout << "�����l������͂��Ă��������F"; 	cin >> a;
	cout << "�����l������͂��Ă��������F"; 	cin >> n;

	unsigned  l_sht = a << n;
	unsigned  r_sht = a >> n;
	unsigned  m_pow = a * pow2(n);
	unsigned  d_pow = a / pow2(n);
	cout << "�� �~ (�Q��" << n << "��) ��" << m_pow << " �ł��B\n";
	cout << "�� �� (�Q��" << n << "��) ��" << d_pow << " �ł��B\n";
	cout << "�� << " << n << " �� " << l_sht << " �ł��B\n";
	cout << "�� >> " << n << " �� " << r_sht << " �ł��B\n";

	if (m_pow == l_sht)
		cout << "�����Ȃ�����" << a << "�̍�" << n << "�r�b�g�V�t�g�́A�Q��"
			 << n << "��Ə�Z�����l�Ɠ������ł��B\n";
	if (d_pow == r_sht)
		cout << "�����Ȃ�����" << a << "�̉E" << n << "�r�b�g�V�t�g�́A�Q��"
			 << n << "��ŏ��Z�����l�Ɠ������ł��B\n";

	return (0);
}

/*
���s��
�����l������͂��Ă��������F10��
�����l������͂��Ă��������F2��
�� �~ (�Q��2��) �� 40 �ł��B
�� �� (�Q��2��) �� 2 �ł��B
�� << 2 �� 40 �ł��B
�� >> 2 �� 2 �ł��B
�����Ȃ�����10�̍�2�r�b�g�V�t�g�́A�Q��2��Ə�Z�����l�Ɠ������ł��B
�����Ȃ�����10�̉E2�r�b�g�V�t�g�́A�Q��2��ŏ��Z�����l�Ɠ������ł��B
*/
