#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menger.h"


/**
 * make_holes - fill a row in a menger sponge with holes
 * @buffer: line to put holes in
 * @row: with row in the sponge this is
 * @length: length of the row
 */
void make_holes(char *buffer, size_t row, size_t length)
{
	size_t gap = 3, size = 1, start, stop;

	while (row >= size)
	{
		if (row / size % 3 == 1)
			for (start = size; start < length; start += gap)
				for (stop = start; stop - start < size; stop++)
					buffer[stop] = ' ';
		gap *= 3;
		size *= 3;
	}
}


/**
 * menger - print a 2D menger sponge
 * @level: the level of the sponge
 */
void menger(int level)
{
	char *buffer;
	size_t index, length;

	if (level < 0)
		return;
	length = (size_t)pow(3, level);
	buffer = malloc(length + 1);
	if (buffer == NULL)
		return;
	buffer[length] = '\0';
	for (index = 0; index < length; index++)
	{
		memset(buffer, '#', length);
		make_holes(buffer, index, length);
		printf("%s\n", buffer);
	}
	free(buffer);
}
