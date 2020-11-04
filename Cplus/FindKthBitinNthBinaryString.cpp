
class Solution
{
public:
	char findKthBit(int n, int k)
	{
		if (n == 1)
			return '0';
		if (k == (1 << (n - 1)))
			return '1';
		if (k < (1 << (n - 1)))
			return findKthBit(n - 1, k);
		return '1' - findKthBit(n, (1 << n) - k) + '0';
	}
};