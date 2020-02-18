#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 x[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int	 y[2][3] = { {1, 5, 8}, {5, 3, 1} };
	int	 z[2][3] = { {0, 0, 0}, {0, 0, 0} };

	for (i = 0; i < 2; i++) {					// ˜a‚ð‹‚ß‚é
		for (int j = 0; j < 3; j++)
			z[i][j] = x[i][j] + y[i][j];
	}

	for (i = 0; i < 2; i++) {					// Œ‹‰Ê‚ð•\Ž¦
		for (int j = 0; j < 3; j++)
			cout << z[i][j] << ' ';
		cout << '\n';
	}

	return (0);
}

/*
ŽÀsŒ‹‰Ê
 2 7 11
 9 8 7
*/
