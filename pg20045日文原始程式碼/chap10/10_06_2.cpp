//--- ������src��dest�ɍő�maxlen�����R�s�[���� ---//
char* strncpy(char *dest, const char *src, size_t maxlen)
{
	char* temp = dest;

	while (maxlen) {
		if (!(*dest++ = *src++)) break;		// '\0'����������I��
		maxlen--;
	}
	while (maxlen--) *dest = '\0';			// �c���'\0'�Ŗ��߂�
	return (temp);
}
