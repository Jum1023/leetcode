#include <vector>
using namespace std;

class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		int index = nums1.size();
		for (--m, --n; n >= 0;)
		{
			if (m >= 0 && nums1[m] > nums2[n])
				nums1[--index] = nums1[m--];
			else
				nums1[--index] = nums2[n--];
		}
	}
};