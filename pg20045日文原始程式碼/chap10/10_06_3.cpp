//--- ������str��dest�ɕt�������� ---//
char* strcat(char *dest, const char *src)
{
	char* temp = dest;

	while (*dest) dest++;			// dest�𖖔��܂Ői�߂�
	while (*dest++ = *src++) ;		// src��'\0'��������܂ŃR�s�[
	return (temp);
}
