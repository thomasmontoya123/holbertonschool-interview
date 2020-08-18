#include <stdio.h>

/**
 * print_grid - prints grid.
 *
 * @grid: grid
 * Return: Void
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpile_checker - checks if sand pile is stable
 *
 * @grid: grid to check.
 * Return: 1 if the grid is stable.
 */
int sandpile_checker(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * grid_sum - Sum two grids.
 *
 * @grid1: grid1.
 * @grid2: grid2.
 * Return: void
 */

void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, sum;

	sum = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = grid1[i][j] + grid2[i][j];
			grid2[i][j] = sum;
			grid1[i][j] = sum;
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles.
 *
 * @grid1: grid 1.
 * @grid2: grid 2.
 * Return: void.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	grid_sum(grid1, grid2);

	while ((sandpile_checker(grid1)) != 1)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					grid1[i][j] -= 4;
				if ((i > 0) && (grid2[i - 1][j] > 3))
					grid1[i][j] += 1;
				if ((i < 2) && (grid2[i + 1][j] > 3))
					grid1[i][j] += 1;
				if ((j > 0) && (grid2[i][j - 1] > 3))
					grid1[i][j] += 1;
				if ((j < 2) && (grid2[i][j + 1] > 3))
					grid1[i][j] += 1;
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				grid2[i][j] = grid1[i][j];
		}

	}
}
