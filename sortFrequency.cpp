#include <vector>

using namespace std;

struct linkedNode{
	int number;
	int val;
	linkedNode *next;
	linkedNode(int a, int b) :number(a), val(b), next(NULL){}
};

//we need to return the head address as the address is not recognised, but the content is recognised.
linkedNode * insertNode(linkedNode (*head), int number, int val)
{
	if (head == NULL)
	{
		/*
		head = (linkedNode *)malloc(sizeof(linkedNode));
		head->number = number;
		head->val = val;
		head->next = NULL;
		*/
		head = new linkedNode(number, val);
		return head;
	}
	linkedNode *cur = head, *prev = head;
	linkedNode *node = new linkedNode(number, val);
	while (cur != NULL)
	{
		if (cur == head && cur->val > val)
		{
			node->next = cur;
			head = node;
			return head;
		}
		else if (cur != head && cur->val > val)
		{
			node->next = cur;
			prev->next = node;
			return head;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	prev->next = node;
	return head;
}

vector<int> sortFrequency(vector<int> &v)
{
	if (v.size() == 0) return v;
	vector<int> res;
	int *flag = (int *)malloc(sizeof(int)*v.size());
	linkedNode *head = NULL, *temp = NULL;

	for (int i = 0; i < v.size(); i++)
		flag[i] = 1;
	for (int i = 0; i < v.size(); i++)
	{
		//find the # of each elements in v
		int number, count = 0;
		if (flag[i])
		{
			number = v[i];
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == number)
				{
					count++;
					flag[j] = 0;
				}
			}
			head = insertNode(head, number, count);
		}
	}

	temp = head;
	while (head != NULL)
	{
		for (int i = 0; i < head->val; i++)
			res.push_back(head->number);
		head = head->next;
		delete temp;
		temp = head;
	}
	return res;
}

int main()
{
	vector<int> v = { 1, 3, 2, 2, 1, 1, 5, 6, 8, 8 };
	vector<int> res = sortFrequency(v);
	return 0;
}
