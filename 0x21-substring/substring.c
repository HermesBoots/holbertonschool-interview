#include <stdlib.h>
#include <string.h>
#include "substring.h"


/**
 * check_substring_words - check the list of words against current substring
 * @s: string currently searching in
 * @s_index: index of current substring in s
 * @words: list of words to search for in substring
 * @word_status: array that will be filled with found/failed status of words
 * @nb_words: number of word strings in words
 * Return: index of character after substring or -1 if no substring matches
 */
int check_substring_words(
	char const *s, int s_index, enum word_status *word_status,
	char const **words, int nb_words
)
{
	int word_index = 0, words_found = 0, words_rejected = 0, words_index;

	while (words_found + words_rejected < nb_words)
	{
		if (s[s_index + word_index] == '\0')
			return (-1);
		for (words_index = 0; words_index < nb_words; words_index++)
		{
			if (word_status[words_index] != WORD_DEFAULT)
				continue;
			if (words[words_index][word_index] != s[s_index + word_index])
			{
				words_rejected++;
				word_status[words_index] = WORD_NOT;
			}
			else if (words[words_index][word_index + 1] == '\0')
			{
				words_found++;
				word_status[words_index] = WORD_FOUND;
				s_index += word_index + 1;
				word_index = -1;
				words_rejected = 0;
				for (words_index = 0; words_index < nb_words; words_index++)
					if (word_status[words_index] == WORD_NOT)
						word_status[words_index] = WORD_DEFAULT;
				break;
			}
		}
		word_index++;
	}
	if (words_rejected == 0)
		return (s_index);
	return (-1);
}

/**
 * find_substring - find concatenated words in a long string
 * @s: string to search in
 * @words: list of words to search for in s
 * @nb_words: number of word strings in words array
 * @n: after exiting, will contain number of matching substrings in s
 * Return: list of indexes of start of matching substrings in s
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	enum word_status *word_status;
	int new, *ret, s_index, words_index;

	if (n == NULL)
		return (NULL);
	*n = 0;
	if (nb_words < 1)
		return (NULL);
	if (s == NULL)
		return (NULL);
	if (words == NULL)
		return (NULL);
	for (words_index = 0; words_index < nb_words; words_index++)
		if (words[words_index] == NULL)
			return (NULL);
	word_status = malloc(sizeof(*word_status) * nb_words);
	ret = malloc(sizeof(*ret) * strlen(s));
	if (word_status == NULL || ret == NULL)
	{
		free(word_status);
		free(ret);
		return (NULL);
	}
	s_index = 0;
	while (s[s_index] != '\0')
	{
		for (words_index = 0; words_index < nb_words; words_index++)
			word_status[words_index] = WORD_DEFAULT;
		new = check_substring_words(s, s_index, word_status, words, nb_words);
		if (new >= 0)
			ret[(*n)++] = s_index;
		s_index++;
	}
	free(word_status);
	ret = realloc(ret, sizeof(*ret) * *n);
	return (ret);
}
