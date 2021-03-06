#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int rangeSum(int *nums, int numsSize, int n, int left, int right)
{
	static const int MOD = 1e9 + 7;
	int arr[numsSize * (numsSize + 1) / 2], arrSize = 0;
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += nums[j];
			arr[arrSize++] = sum;
		}
	}
	qsort(arr, arrSize, sizeof(int), cmp);
	int res = 0;
	for (int i = left - 1; i < right; ++i)
		res = (res + arr[i]) % MOD;
	return res;
}