#include <cstdlib> //for rand
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet
{
public:
	/** Initialize your data structure here. */
	RandomizedSet()
	{
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		if (modify.find(val) != modify.end())
			return false;
		modify[val] = randaccess.size();
		randaccess.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		if (modify.find(val) == modify.end())
			return false;
		modify[randaccess.back()] = modify[val];
		randaccess[modify[val]] = randaccess.back();
		randaccess.pop_back();
		modify.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		return randaccess[rand() % randaccess.size()];
	}

private:
	vector<int> randaccess;
	unordered_map<int, int> modify; //{val,index}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */