
int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int minFlips(int a, int b, int c)
{
	return bitCount(a & ~c) + bitCount(b & ~c) + bitCount((c ^ (a & c)) & (c ^ (b & c)));
}