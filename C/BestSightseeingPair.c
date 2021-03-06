
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxScoreSightseeingPair(int *A, int ASize)
{
	int res = A[0] + A[1] + 0 - 1, maxscore = max(A[0], A[1] + 1);
	for (int i = 2; i < ASize; ++i)
	{
		res = max(res, maxscore + A[i] - i);
		maxscore = max(maxscore, A[i] + i);
	}
	return res;
}