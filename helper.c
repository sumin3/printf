/**
 * _strlen - return the length of a string
 * @s:the string that need to find the length
 * Return: return the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}
/**
 * _strncpy - copies a string.
 * @dest: the copied string
 * @src: the string need to copied
 * @n: use n bytes from src
 * Return: return a pointer to the resultring string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
