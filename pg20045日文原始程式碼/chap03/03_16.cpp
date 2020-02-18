#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 x[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int	 y[3][2] = { {1, 5}, {5, 3}, {8, 1} };
	int	 z[2][2];

	for (i = 0; i < 2; i++) {					// Ï‚ð‹‚ß‚é
		for (int j = 0; j < 2; j++) {
			z[i][j] = 0;
			for (int k = 0; k < 3; k++)
				z[i][j] += x[i][k] * y[k][j];
		}
	}

	for (i = 0; i < 2; i++) {					// Œ‹‰Ê‚ð•\Ž¦
		for (int j = 0; j < 2; j++)
			cout << z[i][j] << ' ';
		cout << '\n';
	}

	return (0);
}

/*
ŽÀsŒ‹‰Ê
 26 18
 62 51
*/
