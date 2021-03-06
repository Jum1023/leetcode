#include <vector>
using namespace std;

class Solution
{
public:
	bool canPlaceFlowers(vector<int> &flowerbed, int n)
	{
		int N = flowerbed.size();
		for (int i = 0; i < N && n > 0; ++i)
		{
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0))
			{
				flowerbed[i++] = 1;
				--n;
			}
		}
		return n == 0;
	}
};