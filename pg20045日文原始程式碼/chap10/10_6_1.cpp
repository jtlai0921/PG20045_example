//--- •¶Žš—ñst1‚Æst2‚ð”äŠr‚·‚é ---//
int strcmp(const char* st1, const char* st2)
{
	while (*st1 == *st2) {
		if (*st1 == '\0')
			return (0);						// “™‚µ‚¯‚ê‚Î0‚ð•Ô‹p
		st1++;	st2++;
	}
	return ((unsigned char)*st1 - (unsigned char) *st2);
}
