#include <stdio.h>


/**
 * print_grid_3x3 - print a 3x3 grid over 3 rows of text
 * @grid: grid to print
 */
void print_grid_3x3(int grid[3][3])
{
	int x, y;

	printf("=\n");
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
			printf(x < 2 ? "%d " : "%d", grid[y][x]);
		printf("\n");
	}
}


/**
 * sandpiles_sum - combine two grids of sand piles, collapsing too-big piles
 * @grid1: one of the grids
 * @grid2: the other grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	unsigned char stable = 1;
	int x, y;

	for (y = 0; y < 3; y++)
		for (x = 0; x < 3; x++)
		{
			grid1[y][x] += grid2[y][x];
			grid2[y][x] = 0;
			if (grid1[y][x] > 3)
				stable = 0;
		}
	if (stable)
		return;

	print_grid_3x3(grid1);
	for (y = 0; y < 3; y++)
		for (x = 0; x < 3; x++)
		{
			if (grid1[y][x] > 3)
			{
				grid1[y][x] -= 4;
				if (y > 0)
					grid2[y - 1][x]++;
				if (x > 0)
					grid2[y][x - 1]++;
				if (x < 2)
					grid2[y][x + 1]++;
				if (y < 2)
					grid2[y + 1][x]++;
			}
		}
	sandpiles_sum(grid1, grid2);
}
