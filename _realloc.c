#include "main.h"

/**
 * _realloc - Reallocate a memory
 * @ptr: Pointer to array
 * @old_size: Old size
 * @new_size: New size
 * Return: A pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *str;
	char *ptr1;
	unsigned int i;

	ptr1 = (char *)ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	str = malloc((new_size) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			str[i] = ptr1[i];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			str[i] = ptr1[i];
	}
	free(ptr1);
	return (str);
}
