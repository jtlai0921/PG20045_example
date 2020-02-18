#include	<iostream.h>

int main(void)
{
	const int	max = 4;
	int		x[max];
	double	y[max];

	for (int i = 0; i < max; i++) {
		cout  <<  "&x[" <<  i  <<  "] = "  <<  &x[i]  <<  " : ";
		cout  <<  "&y[" <<  i  <<  "] = "  <<  &y[i]  <<  '\n';
	}

	return (0);
}
/*
ŽÀsŒ‹‰Êˆê—á
&x[0] = 500 : &y[0] = 600
&x[1] = 502 : &y[1] = 608
&x[2] = 504 : &y[2] = 616
&x[3] = 506 : &y[3] = 624
*/
