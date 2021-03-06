#include <stdbool.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (!head)
		return false;
	struct ListNode *tortoise = head, *hare = head->next;
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			return true;
	}
	return false;
}