//--- 文字列sの先頭から文字cを検索する ---//
char* strchr(const char *s, int c)
{
	for (const char ch = c ; *s != ch; s++)
		if (*s == '\0')
			return (NULL);
	return ((char*)s);
}
