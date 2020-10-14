#include <stddef.h>
#include "regex.h"


/**
 * do_match - recursive helper function for regex_match
 * @str: string to match against
 * @pattern: pattern to match against str
 * @istr: index into str currently used for comparison
 * @ipat: index into pattern currently trying to match
 * Return: 1 if pattern definitely matches str, 0 if it definitely doesn't
 */
int do_match(char const *str, char const *pattern, size_t istr, size_t ipat)
{
	if (pattern[ipat] == '\0' && str[istr] == '\0')
		return (1);
	if (pattern[ipat] == '\0' && str[istr] != '\0')
		return (0);
	if (pattern[ipat + 1] != '*')
	{
		if (
			pattern[ipat] == str[istr] ||
			(pattern[ipat] == '.' && str[istr] != '\0')
		)
			return (do_match(str, pattern, istr + 1, ipat + 1));
		else
			return (0);
	}
	else
	{
		if (
			pattern[ipat] == str[istr] ||
			(pattern[ipat] == '.' && str[istr] != '\0')
		)
		{
			if (do_match(str, pattern, istr + 1, ipat))
				return (1);
			else
				return (do_match(str, pattern, istr, ipat + 2));
		}
		else
			return (do_match(str, pattern, istr, ipat + 2));
	}
}


/**
 * regex_match - do a regexp match with a limited set of special characters
 * @str: string to match against
 * @pattern: pattern to match against str
 * Return: 1 if pattern matches, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	return (do_match(str, pattern, 0, 0));
}
