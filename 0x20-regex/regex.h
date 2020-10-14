#ifndef _REGEX_H_
#define _REGEX_H_

int do_match(char const *str, char const *pattern, size_t istr, size_t ipat);
int regex_match(char const *str, char const *pattern);

#endif
