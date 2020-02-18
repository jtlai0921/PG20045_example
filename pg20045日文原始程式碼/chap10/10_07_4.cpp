//--- •¶š—ñst1‚©‚çst2‚ğŒŸõ‚·‚é ---//
char* strstr(const char *st1, const char *st2)
{
	if (*st2 == '\0') return ((char*)st1);
	for ( ; (st1 = strchr(st1, *st2)) != NULL; st1++) {
		for (const char *t1 = st1, *t2 = st2 ; ; )
			if (*++t2 == '\0')
				return ((char*) st1);
			else if (*++t1 != *t2)
				break;
	}
	return (NULL);
}
