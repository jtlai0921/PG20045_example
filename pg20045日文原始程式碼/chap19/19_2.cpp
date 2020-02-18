#include	<fstream.h>
#include	<iostream.h>

int main(int argc, char* argv[])
{
	int  i;

	for (i = 0; i < argc; i++)
		cout << i << " : " << argv[i] << '\n';

	return (0);
}

