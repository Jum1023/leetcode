#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
	{
		int n = puzzles.size();
		vector<int> res(n), bitmask(n);
		unordered_map<int, int> m;
		for (int i = 0; i < (int)words.size(); i++)
		{
			int mask = 0;
			for (int j = 0; j < (int)words[i].length(); j++)
				mask |= (1 << (words[i][j] - 'a'));
			++m[mask];
		}
		for (int i = 0; i < n; i++)
		{
			int mask = 0;
			for (int j = 0; j < (int)puzzles[i].length(); j++)
				mask |= (1 << (puzzles[i][j] - 'a'));
			int submask = mask;
			while (submask != 0)
			{
				if ((submask & (1 << (puzzles[i][0] - 'a'))) != 0 && m.find(submask) != m.end())
					res[i] += m[submask];
				submask = ((submask - 1) & mask);
			}
		}
		return res;
	}
};