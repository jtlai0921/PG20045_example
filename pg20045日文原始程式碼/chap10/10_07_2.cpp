//--- ������s�̐擪���當��c���������� ---//
char* strchr(const char *s, int c)
{
	for (const char ch = c ; *s != ch; s++)
		if (*s == '\0')
			return (NULL);
	return ((char*)s);
}
