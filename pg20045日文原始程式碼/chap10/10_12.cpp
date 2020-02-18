#include	<iostream.h>

const int  smax = 3;
const int  slen = 6;		// •s—v

void print(char* x[], int n)
{
	if (n >= 0 && n < smax)
		cout << x[n] << '\n';
}

int main(void)
{
	char*  p[] = {"March", "iz", "HK13"}; 

	for (int i = 0; i < smax; i++)
		print(p, i);

	return (0);
}

/*
ŽÀsŒ‹‰Ê
March
iz
HK13
*/
