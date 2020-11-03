#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int atMostNGivenDigitSet(vector<string> &D, int N)
	{
		int res = 0, n = D.size();
		vector<char> v(n);
		for (int i = 0; i < n; ++i)
			v[i] = D[i][0];
		string str = to_string(N);
		int len = str.length();
		for (int i = 1; i < len; ++i)
			res += repeatA(i, n);
		for (int i = 0; i < len; ++i)
		{
			int j = 0;
			while (j < n && v[j] < str[i])
				++j;
			res += j * repeatA(len - i - 1, n);
			if (j >= n || v[j] != str[i])
				break;
			if (i == len - 1)
				++res;
		}
		return res;
	}

	int repeatA(int m, int n) //repeated Arrangement
	{
		if (m == 0)
			return 1;
		int res = 1;
		for (int i = 0; i < m; ++i)
			res *= n;
		return res;
	}
};