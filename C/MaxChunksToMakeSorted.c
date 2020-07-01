#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int maxChunksToSorted(int* arr, int arrSize)
{
	int dup[arrSize];
	memcpy(dup, arr, sizeof(int) * arrSize);
	qsort(arr, arrSize, sizeof(int), cmp);
	int res = 0, sum1 = 0, sum2 = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum1 += arr[i];
		sum2 += dup[i];
		if (sum1 == sum2)
			++res;
	}
	return res;
}
