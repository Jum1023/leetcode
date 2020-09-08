#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxJumps(vector<int> &arr, int d)
	{
		int N = arr.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < N; ++i)
			v.push_back({arr[i], i});
		sort(v.begin(), v.end());

		int res = 1;
		vector<int> dp(N, 1);
		for (int i = 0; i < N; ++i)
		{
			int index = v[i].second;
			int left = index - 1, right = index + 1;
			while (left >= max(0, index - d) && arr[left] < arr[index])
			{
				dp[index] = max(dp[index], dp[left] + 1);
				--left;
			}
			while (right <= min(N - 1, index + d) && arr[right] < arr[index])
			{
				dp[index] = max(dp[index], dp[right] + 1);
				++right;
			}
			res = max(res, dp[index]);
		}
		return res;
	}
};