#!/usr/bin/python3
"""
5-island_perimeter module
"""

def island_perimeter(grid):
    """Calculate the perimeter of the island described in grid

    Args:
    - grid (list[list[int]]): The grid describing the island.

    Returns:
    - int: The perimeter of the island.
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4

                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
