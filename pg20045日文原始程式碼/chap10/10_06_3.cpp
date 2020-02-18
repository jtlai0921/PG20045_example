//--- 文字列strをdestに付け加える ---//
char* strcat(char *dest, const char *src)
{
	char* temp = dest;

	while (*dest) dest++;			// destを末尾まで進める
	while (*dest++ = *src++) ;		// srcに'\0'が見つかるまでコピー
	return (temp);
}
