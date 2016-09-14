#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int data, Node* pn = 0)
		: value(data), next(pn) {}

	static void Clear(Node*& head)
	{
		while (head) {
			Node* p = head;
			head = head->next;
			delete p;
		}
	}

	static void Print(Node* head)
	{
		for (Node* p = head; p; p = p->next)
			cout << p->value << " ";
		cout << endl;
	}

	static void ReverseInPairsValueSwap(Node* head)
	{
		for (Node* cur = head; cur && cur->next; cur = cur->next->next)
			swap(cur->value, cur->next->value);
	}

	static Node* ReverseInPairs(Node* head)
	{
		Node* newHead = head, *prev = 0;
		for (Node* cur = head; cur && cur->next; cur = cur->next)
		{
			Node* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = cur;

			if (prev == 0)
			{
				newHead = tmp;
				prev = tmp->next;
			}
			else
			{
				prev->next = tmp;
				prev = prev->next->next;
			}
		}

		return newHead;
	}

	static Node* Reverse(Node* head)
	{
		Node* pp = 0;
		while (head)
		{
			Node* tmp = head->next;
			head->next = pp;
			pp = head;
			head = tmp;
		}
		return pp;
	}

	static bool IsPalindrome(Node* head)
	{
		if (!head || !head->next) return true;

		bool res;
		Node* p1 = head, *p2 = head;
		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		Node* phead1 = head;
		Node* phead2 = Node::Reverse(p2 ? p1 : p1->next);
		Node* pp = phead2;
		while (pp)
		{
			if (pp->value != phead1->value)
				break;
			pp = pp->next;
			phead1 = phead1->next;
		}

		res = pp == 0;
		Node::Reverse(phead2);
		return res;
	}
};

Node* InitList()
{
	return new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6))))));
}

Node* InitPalindromeListEven()
{
	return new Node(1, new Node(2, new Node(3, new Node(3, new Node(2, new Node(1))))));
}

Node* InitPalindromeListOdd()
{
	return new Node(1, new Node(2, new Node(3, new Node(2, new Node(1)))));
}


int main()
{
	Node* head = InitPalindromeListEven();
	Node::Print(head);

	if (Node::IsPalindrome(head))
		cout << "Palindrome" << endl;
	else
		cout << "NOT palindrome" << endl;
	Node::Print(head);

	head = InitPalindromeListOdd();
	Node::Print(head);
	if (Node::IsPalindrome(head))
		cout << "Palindrome" << endl;
	else
		cout << "NOT palindrome" << endl;
	Node::Print(head);

	head = InitList();
	Node::Print(head);
	if (Node::IsPalindrome(head))
		cout << "Palindrome" << endl;
	else
		cout << "NOT palindrome" << endl;
	Node::Print(head);

	Node::Clear(head);
}