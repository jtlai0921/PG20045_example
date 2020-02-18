//--- •¶š—ñs‚Ìæ“ª‚©‚ç•¶šc‚ğŒŸõ‚·‚é ---//
char* strchr(const char *s, int c)
{
	for (const char ch = c ; *s != ch; s++)
		if (*s == '\0')
			return (NULL);
	return ((char*)s);
}
