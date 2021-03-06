
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		if (!head)
			return nullptr;
		ListNode *tortoise = head, *hare = head->next;
		while (hare && hare->next)
		{
			tortoise = tortoise->next;
			hare = hare->next->next;
			if (tortoise == hare)
				break;
		}
		if (hare && hare->next)
		{
			tortoise = head;
			hare = hare->next;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return hare;
		}
		return nullptr;
	}
};