#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePathsIII(vector<vector<int>> &grid)
	{
		int allzero = 0, M = 0, N = 0, startx = 0, starty = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
				{
					startx = i;
					starty = j;
				}
				else if (grid[i][j] == 0)
					++allzero;
			}
		}
		return dfs(grid, allzero + 1, startx, starty); //for the start pos will consume count from allzero
	}

	int dfs(vector<vector<int>> &grid, int allzero, int m, int n)
	{
		if (m >= (int)grid.size() || m < 0 || n >= (int)grid[0].size() || n < 0)
			return 0;
		if (grid[m][n] == -1 || allzero < 0)
			return 0;
		if (grid[m][n] == 2)
			return allzero == 0 ? 1 : 0;
		int res = 0;
		grid[m][n] = -1;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			res += dfs(grid, allzero - 1, m + path[i], n + path[i + 1]);
		grid[m][n] = 0;
		return res;
	}
};