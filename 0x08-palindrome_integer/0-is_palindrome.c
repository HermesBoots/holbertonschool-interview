/**
 * count_digits - count the base-10 digits in an integer
 * @n: integer to check
 * Return: number of digits in n
 */
static inline unsigned long count_digits(unsigned long n)
{
	if (n < 10LU)
		return (1LU);
	if (n < 100LU)
		return (10LU);
	if (n < 1000LU)
		return (100LU);
	if (n < 10000LU)
		return (1000LU);
	if (n < 100000LU)
		return (10000LU);
	if (n < 1000000LU)
		return (100000LU);
	if (n < 10000000LU)
		return (1000000LU);
	if (n < 100000000LU)
		return (10000000LU);
	if (n < 1000000000LU)
		return (100000000LU);
	if (n < 10000000000LU)
		return (1000000000LU);
	if (n < 100000000000LU)
		return (10000000000LU);
	if (n < 1000000000000LU)
		return (100000000000LU);
	if (n < 10000000000000LU)
		return (1000000000000LU);
	if (n < 100000000000000LU)
		return (10000000000000LU);
	if (n < 1000000000000000LU)
		return (100000000000000LU);
	if (n < 10000000000000000LU)
		return (1000000000000000LU);
	if (n < 100000000000000000LU)
		return (10000000000000000LU);
	if (n < 1000000000000000000LU)
		return (100000000000000000LU);
	return (1000000000000000000LU);
}

/**
 * is_palindrome - check if an integer is a palindrome
 * @n: integer to check
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long left;
	unsigned long right = 1;

	left = count_digits(n);
	while (left > right)
	{
		if (n / left % 10 != n / right % 10)
			return (0);
		left /= 10;
		right *= 10;
	}
	return (1);
}
