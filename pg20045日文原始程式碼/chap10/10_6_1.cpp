//--- 文字列st1とst2を比較する ---//
int strcmp(const char* st1, const char* st2)
{
	while (*st1 == *st2) {
		if (*st1 == '\0')
			return (0);						// 等しければ0を返却
		st1++;	st2++;
	}
	return ((unsigned char)*st1 - (unsigned char) *st2);
}
