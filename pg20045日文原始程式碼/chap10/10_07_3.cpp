//--- ������s�̖������當��c���������� ---//
char* strrchr(const char *s, int c)
{
	for (const char ch = c, *ret = NULL; ; s++){
		if (*s == ch)						// c�𔭌�
			ret = s;
		if (*s == '\0')
			return ((char*)ret);
	}
}
