#include	<iostream.h>

//--- vfÌzñÌÅ¬lðÔp·é ---//
int minof(int x[], int n)
{
	int	 min = x[0];
	for (int i = 1; i < n; i++)
		if (x[i] < min) min = x[i];
	return (min);
}

int main(void)
{
	const int  max = 5;						// zñaÌvf
	int a[max];

	for (int i = 0; i < max; i++) {			// zñaÉlðÇÝÞ
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "Å¬lF" << minof(a, max) << '\n';

	return (0);
}

/*
Àsá
a[0] = 10¥
a[1] = 12¥
a[2] = 100¥
a[3] = 95¥
a[4] = 82¥
Å¬lF10
*/
