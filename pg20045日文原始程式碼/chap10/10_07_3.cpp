//--- 文字列sの末尾から文字cを検索する ---//
char* strrchr(const char *s, int c)
{
	for (const char ch = c, *ret = NULL; ; s++){
		if (*s == ch)						// cを発見
			ret = s;
		if (*s == '\0')
			return ((char*)ret);
	}
}
