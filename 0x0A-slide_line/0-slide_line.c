#include "slide_line.h"

/**
 * slide_left - slide l
 * @line: list of integers
 * @size: size of list
 * Return: 1 success
 */
int slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				i--;
				break;
			}
			if (line[i] == line[j] && line[i] != 0)
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else if (line[j] != 0 && line[i + 1] == 0)
			{
				line[i + 1] = line[j];
				line[j] = 0;
				break;
			}
		}
	}
	return (1);
}

/**
 * slide_right - slide r
 * @line: list of integers
 * @size: size of list
 * Return: 1 success
 */
int slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = i + 1; j <= size; j++)
		{
			if (line[size - i] == 0 && line[size - j] != 0)
			{
				line[size - i] = line[size - j];
				line[size - j] = 0;
				i--;
				break;
			}
			if (line[size - i] == line[size - j] && line[size - i] != 0)
			{
				line[size - i] *= 2;
				line[size - j] = 0;
				break;
			}
			if (line[size - j] != 0 && line[size - (i + 1)] == 0)
			{
				line[size - (i + 1)] = line[size - j];
				line[size - j] = 0;
				break;
			}
		}
	}
	return (1);
}

/**
 * slide_line - reproduce the 2048 game
 * @line: list of numbers to slide
 * @size: size of list
 * @direction: direction to slide
 *
 * Return: 1 if successful or 0 if fails
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	return (slide_right(line, size));
}
