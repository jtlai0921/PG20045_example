#include	<iostream.h>

const int  smax = 3;
const int  slen = 6;

void print(char x[][slen], int n)
{
	if (n >= 0 && n < smax)
		cout << x[n] << '\n';
}

int main(void)
{
	char  s[][slen] = {"March", "iz", "HK13"};

	for (int i = 0; i < smax; i++)
		print(s, i);

	return (0);
}

/*
ŽÀsŒ‹‰Ê
March
iz
HK13
*/
