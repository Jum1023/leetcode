#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestIncreasingPath(vector<vector<int>> &matrix)
	{
		int res = 0;
		if (matrix.empty())
			return res;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
		for (int i = 0; i < (int)matrix.size(); ++i)
			for (int j = 0; j < (int)matrix[0].size(); j++)
				res = max(res, longestIncreasingPath(matrix, dp, i, j));
		return res + 1;
	}

	int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
	{
		if (dp[i][j] != 0)
			return dp[i][j];
		int res = 0;
		int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int k = 0; k < 4; k++)
		{
			int x = i + path[k][0], y = j + path[k][1];
			if (x >= 0 && x < (int)matrix.size() && y >= 0 && y < (int)matrix[0].size() && matrix[x][y] > matrix[i][j])
				res = max(res, 1 + longestIncreasingPath(matrix, dp, x, y));
		}
		dp[i][j] = res;
		return res;
	}
};