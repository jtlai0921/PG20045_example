#include	<iostream.h>

#include	"acaint.h"

int main(void)
{
	AcAint	word;			// int�A�z�z��
	char	temp[257];

	while (cin >> temp)
		++word[temp];

	cout << '\n';
	word.Put();

	return (0);
}

