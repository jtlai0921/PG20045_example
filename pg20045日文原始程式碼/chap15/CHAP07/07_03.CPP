#include	<limits.h>
#include	<iostream.h>

int main(void)
{
	cout << "‚±‚Ìˆ—Œn‚ÌcharŒ^‚ÍA";
	if (CHAR_MIN)
		cout << "•„†•t‚«Œ^‚Å‚·B\n";
	else
		cout << "•„†‚È‚µŒ^‚Å‚·B\n";

	return (0);
}

/*
ŽÀsŒ‹‰Êˆê—á
‚±‚Ìˆ—Œn‚ÌcharŒ^‚ÍA•„†•t‚«Œ^‚Å‚·B*/
