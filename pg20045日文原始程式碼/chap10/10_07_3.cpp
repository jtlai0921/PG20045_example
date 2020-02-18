//--- •¶š—ñs‚Ì––”ö‚©‚ç•¶šc‚ğŒŸõ‚·‚é ---//
char* strrchr(const char *s, int c)
{
	for (const char ch = c, *ret = NULL; ; s++){
		if (*s == ch)						// c‚ğ”­Œ©
			ret = s;
		if (*s == '\0')
			return ((char*)ret);
	}
}
