//--- •‚“®¬”“_”‚˜‚Ì‚æ‚ğ•Ô‹p‚·‚é ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)						// n‚ª0‚æ‚è‘å‚«‚¢ê‡
		while (n-- > 0) 	a *= x;
	else							// n‚ª0ˆÈ‰º‚Ìê‡
		while (n++ < 0) 	a /= x;

	return (a);
}

