//--- 文字列srcをdestに最大maxlen文字コピーする ---//
char* strncpy(char *dest, const char *src, size_t maxlen)
{
	char* temp = dest;

	while (maxlen) {
		if (!(*dest++ = *src++)) break;		// '\0'を見つけたら終了
		maxlen--;
	}
	while (maxlen--) *dest = '\0';			// 残りを'\0'で埋める
	return (temp);
}
