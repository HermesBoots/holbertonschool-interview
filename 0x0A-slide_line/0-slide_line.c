#include <stdio.h>
#include "slide_line.h"


/**
 * merge_line - merge the matching values in a 2048 game
 * @line: line to merge
 * @size: size of the line
 * @direction: which direction to merge
 */
void merge_line(int *line, size_t size, int direction)
{
	ssize_t fast, slow;

	slow = direction == SLIDE_LEFT ? 0 : size - 1;
	while (slow >= 0 && (size_t)slow < size && line[slow] == 0)
		slow += direction == SLIDE_LEFT ? 1 : -1;
	fast = slow + (direction == SLIDE_LEFT ? 1 : -1);
	while (fast >= 0 && (size_t)fast < size && line[fast] == 0)
		fast += direction == SLIDE_LEFT ? 1 : -1;
	while (fast >= 0 && (size_t)fast < size)
	{
		if (line[slow] == line[fast])
		{
			line[slow] *= 2;
			line[fast] = 0;
		}
		do {
			slow += direction == SLIDE_LEFT ? 1 : -1;
		} while (slow >= 0 && (size_t)slow < size && line[slow] == 0);
		fast = slow;
		do {
			fast += direction == SLIDE_LEFT ? 1 : -1;
		} while (fast >= 0 && (size_t)fast < size && line[fast] == 0);
	}
}


/**
 * slide_line - collapse a single line in a 2048 game
 * @line: line of numbers to collapse
 * @size: number of elements on the line
 * @direction: which direction to slide
 * Return: 1 if arguments are valid, 0 if they aren't
 */
int slide_line(int *line, size_t size, int direction)
{
	ssize_t fast, slow;

	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	if (size < 1)
		return (1);
	merge_line(line, size, direction);
	slow = direction == SLIDE_LEFT ? 0 : size - 1;
	fast = slow + (direction == SLIDE_LEFT ? 1 : -1);
	while (fast >= 0 && (size_t)fast < size && line[fast] == 0)
		fast += direction == SLIDE_LEFT ? 1 : -1;
	while (fast >= 0 && (size_t)fast < size)
	{
		if (line[slow] == 0)
		{
			line[slow] = line[fast];
			line[fast] = 0;
		}
		do {
			slow += direction == SLIDE_LEFT ? 1 : -1;
		} while (slow >= 0 && (size_t)slow < size && line[slow] != 0);
		fast = slow;
		do {
			fast += direction == SLIDE_LEFT ? 1 : -1;
		} while (fast >= 0 && (size_t)fast < size && line[fast] == 0);
	}
	return (1);
}
