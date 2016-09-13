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
};

Node* InitList()
{
	return new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6))))));
}


int main()
{
	Node* head = InitList();

	cout << "Original list:      ";
	Node::Print(head);

	/*cout << "Reverse pair SWAP:  ";
	Node::ReverseInPairsValueSwap(head);
	Node::Print(head);

	Node::Clear(head);
	head = InitList();*/

	cout << "Reverse pair NODES: ";
	head = Node::ReverseInPairs(head);
	Node::Print(head);
	Node::Clear(head);
}