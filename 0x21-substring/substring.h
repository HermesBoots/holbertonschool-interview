#ifndef _SUBSTRING_H_
#define _SUBSTRING_H_

/**
 * enum word_status - progress of a word in the current substring search
 * @WORD_DEFAULT: the word has not been confirmed found or not found
 * @WORD_FOUND: the word has been found in the substring
 * @WORD_NOT: the word can't be at this point in the substring
 */
enum word_status
{
	WORD_DEFAULT, WORD_FOUND, WORD_NOT
};

int check_substring_words(
	char const *s, int s_index, enum word_status *word_status,
	char const **words, int nb_words
);
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
