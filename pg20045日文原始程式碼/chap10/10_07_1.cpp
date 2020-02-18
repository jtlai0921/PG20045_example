//--- ������st1��st2���ŏ���n�������r���� ---//
int strncmp(const char* st1, const char* st2, size_t n)
{
	while (n && *st1 && *st2) {
		if (*st1 != *st2)					// �������Ȃ�
			return ((unsigned char)*st1 - (unsigned char) *st2);
		st1++;	st2++; n--;
	}
	if (!n)   return (0);					// ������
	if (*st1) return (1);					// st1 > st2
	return (-1);							// st1 < st2
}
