/**
 * is_palindrome - check if an integer is a palindrome
 * @n: integer to check
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long left = 10000000000000000000LU;
	unsigned long right = 1;

	while (left > 0 && n / left == 0)
		left /= 10;
	while (left > right)
	{
		if (n / left % 10 != n / right % 10)
			return (0);
		left /= 10;
		right *= 10;
	}
	return (1);
}
