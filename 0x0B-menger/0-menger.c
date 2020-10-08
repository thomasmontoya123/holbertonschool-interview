#include "menger.h"


/**
* cell_check - checks a cell.
* @row: Row of the cell.
* @col: Column of the cell.
* Return: 1 for solid.
*/

int cell_check(int row, int col)
{
	while (1)
	{
		if (row == 0 || col == 0)
			return (1);
		else if (row % 3 == 1 && col % 3 == 1)
			return (0);
		row /= 3;
		col /= 3;
	}
}

/**
* menger - Draws a 2D Menger Sponge.
* @level: Level of the Menger Sponge to draw.
* Return: void
*/

void menger(int level)
{
	int n, i, j;

	n = pow(3, level);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (cell_check(i, j))
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

