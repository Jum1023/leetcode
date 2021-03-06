#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMoneyAmount(int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, n * n));
		for (int i = 0; i < n; ++i)
		{
			dp[i + 1][i + 1] = 0;
			dp[i][i + 1] = i;
		}
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = i + 2; j <= n; ++j)
			{
				for (int k = i + 1; k < j; ++k)
					dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
			}
		}
		return dp[1][n];
	}
};