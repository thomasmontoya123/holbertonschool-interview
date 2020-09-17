#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a number is a palindrome.
 * @n: unsigned long number
 * Return: 0 if n is not a palindrome, 1 if n is a palindrome
 */

int is_palindrome(unsigned long n)
{
	int buff[999];
	int i = 0, j;

	if (n / 10 == 0)
		return (1);

	while (n != 0)
	{
		buff[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;

	for (j = 0; j <= i; ++j, i--)
	{
		if (buff[i] != buff[j])
		return (0);

	}
	return (1);
}
