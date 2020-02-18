#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 a[10];

	for (i = 0; i < 10; i++)	// æ“ª‚©‚ç‡‚É1, 2, c‚ð“ü‚ê‚é
		a[i] = i + 1;

	for (i = 0; i < 10; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
ŽÀs—á
a[0] = 1
a[1] = 2
    F
 y’†—ªz
    F
a[9] = 10
*/
