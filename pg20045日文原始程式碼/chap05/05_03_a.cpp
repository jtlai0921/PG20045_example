//--- ���������_��x��n���ԋp���� ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)					// n��0���傫���ꍇ
		while (n > 0) {
			a *= x;
			n--;
		}
	else						// n��0�ȉ��̏ꍇ
		while (n < 0) {
			a /= x;
			n++;
		}

	return (a);
}
