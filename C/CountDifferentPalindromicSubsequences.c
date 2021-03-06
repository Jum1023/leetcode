#include <string.h>

/*
Assume that dp[i][j] is the number of different palindromic subsequences in range [i,j]

if s[i] != s[j] so [i,j] is not a palindromic string, we can get rid of either s[i] or s[j]. We have:
dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
we must -dp[i+1][j-1], because the range [i+1, j-1] is calculated twice.

if s[i] == s[j] so
dp[i][j] = dp[i+1][j-1] + s[i] {dp[i+1][j-1]} s[j] - duplicated elements between 2 sets

The most important thing here is to calculate the number of duplicated elements. These elements will be in the range (i1,j1) (a sub range of [i,j]) where:
i1 is the next position to the right from i so that s[i] = s[i1]
j1 is the next position to the left from j so that s[j1] = s[j]

all elements in [i1+1, j1-1] will be duplicated, because:
{s[i1] { [i1+1, j1-1] } s[j1]} == {s[i] { [i1+1, j1-1] } s[j]}
*/

int countPalindromicSubsequences(char *S)
{
	static const int MOD = 1e9 + 7;
	int N = strlen(S);
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
		dp[i][i] = 1;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (S[i] != S[j])
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
			else
			{
				int l = i + 1, r = j - 1;
				while (l < j && S[i] != S[l])
					++l;
				while (i < r && S[j] != S[r])
					--r;
				int duplicates = (l < r) ? -dp[l + 1][r - 1] : (r == l) ? 1 : 2;
				dp[i][j] = dp[i + 1][j - 1] * 2 + duplicates;
			}
			dp[i][j] = dp[i][j] < 0 ? dp[i][j] + MOD : dp[i][j] % MOD;
		}
	}
	return dp[0][N - 1];
}