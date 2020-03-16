#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
	{
		int dp[502][502][4] = {{{0}}};
		vector<vector<int>> board(N, vector<int>(N, 1));
		for (auto &m : mines)
			board[m[0]][m[1]] = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 1)
					dp[i + 1][j + 1][0] = dp[i][j + 1][0] + 1;
			}
		}
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 1)
					dp[i + 1][j + 1][1] = dp[i + 2][j + 1][1] + 1;
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (board[i][j] == 1)
					dp[i + 1][j + 1][2] = dp[i + 1][j][2] + 1;
			}
		}
		for (int j = N - 1; j >= 0; j--)
		{
			for (int i = 0; i < N; i++)
			{
				if (board[i][j] == 1)
					dp[i + 1][j + 1][3] = dp[i + 1][j + 2][3] + 1;
			}
		}

		int res = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (board[i - 1][j - 1] == 1)
					res = max(res, min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3])));
			}
		return res;
	}
};