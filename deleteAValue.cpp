#include <stdlib.h>

struct Node{
	int val;
	Node *next;
};

void deleteVal(int val, Node **list)
{
	if (*list == NULL) return;
	Node *prev, *cur;
	cur = *list;
	prev = cur;
	while (cur != NULL)
	{
		if (cur == *list && cur->val == val)
		{
			*list = (*list)->next;
			//free(cur); //as the node is not from malloc...
			cur = *list;
			prev = cur;
		}
		else if (cur != *list && cur->val == val)
		{
			prev->next = cur->next;
			//free(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

int main() 
{
	Node a,b,c,d;
	a.val = 1;
	b.val = 1;
	c.val = 3;
	d.val = 4;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;
	Node **headpp, *headp;
	headp = &a;
	headpp = &headp;
	deleteVal(4, headpp);
	return 0;
}
