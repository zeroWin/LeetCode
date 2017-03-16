/**
 * 463. Island Perimeter
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 * Example:

 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]

 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:

 **/
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int result = 0;
	int i,j;
	
	for(i = 0; i < gridRowSize; ++i) // 行
	{
		for(j = 0; j < gridColSize; ++j) // 列
		{
			result += 4;
			if(grid[i][j] == 1)
			{
				if(j == 0 && j + 1 < gridColSize) //是第0列
				{
					if(grid[i][j+1] == 1)
						result -= 1;
				}
				if(j + 1 = gridColSize && j > 0)  // 最后一列
				{
					if(grid[i][j-1] == 1)
						result -= 1;
				}
				if( j > 0 && j < gridColSize - 1) // 不是第0列和最后一列
				{
					if(grid[i][j-1] == 1)
						result -= 1;
					if(grid[i][j + 1] == 1)
						result -= 1;
				}
				
				
				if(i == 0 && i + 1 < gridRowSize) //是第0行
				{
					if(grid[i+1][j] == 1)
						result -= 1;
				}
				
				if(i + 1 == gridRowSize && i > 0) //是最后一行
				{
					if(grid[i-1][j] == 1)
						result -= 1;
				}
				
				if( i > 0 && i  < gridRowSize - 1) // 不是第0行和最后一行
				{
					if(grid[i-1][j] == 1)
						result -= 1;
					if(gird[i+1][j] == 1)
						result -= 1;
				}
			}
		}	
	}
	return result;
	
}