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

	static void ReverseInPairs(Node* head)
	{

	}
};


int main()
{
	Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	Node::Print(head);
	Node::Clear(head);
}