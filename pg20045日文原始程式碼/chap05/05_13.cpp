#include	<iostream.h>

//--- ‚Qs‚R—ñ‚Ìs—ñx‚Æ‚Rs‚Q—ñ‚Ìs—ñy‚ÌÏ‚ğz‚ÉŠi”[‚·‚é ---//
void mul(int x[][3], int y[][2], int z[][2])
{
	for (int i = 0; i < 2; i++)						// Ï‚ğ‹‚ß‚é
		for (int j = 0; j < 2; j++) {
			z[i][j] = 0;
			for (int k = 0; k < 3; k++)
				z[i][j] += x[i][k] * y[k][j];
		}
}

int main(void)
{
	int x[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int y[3][2] = { {1, 5}, {5, 3}, {8, 1} };
	int z[2][2];

	mul(x, y, z);
	for (int i = 0; i < 2; i++) {                   // Œ‹‰Ê‚ğ•\¦
		for (int j = 0; j < 2; j++)
			cout << z[i][j] << ' ';
		cout << '\n';
	}

	return (0);
}

/*
ÀsŒ‹‰Ê
 26 18
 62 51
*/
