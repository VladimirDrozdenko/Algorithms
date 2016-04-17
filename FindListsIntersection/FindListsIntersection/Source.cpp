#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;

	Node(int v, Node* p = 0)
		: val(v), next(p) {}

	friend static ostream& operator << (ostream& os, const Node* node)
	{
		for (const Node* p = node; p; p = p->next)
			os << p->val << " -> ";
		return os;
	}
};

size_t GetListSize(const Node* head)
{
	size_t size = 0;
	while (head)
	{
		++size;
		head = head->next;
	}

	return size;
}

const Node* GetIntersectionNode(const Node* head1, const Node* head2)
{
	if (!head1 || !head2)
		return 0;

	size_t size1 = GetListSize(head1);
	size_t size2 = GetListSize(head2);

	size_t diff = (size1 > size2)
		? size1 - size2
		: size2 - size1;

	if (size1 > size2)
	{
		for (size_t i = 0; i < diff; ++i)
			head1 = head1->next;
	}
	else if (size1 < size2)
	{
		for (size_t i = 0; i < diff; ++i)
			head2 = head2->next;
	}

	while (head1 && head2 && head1 != head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}

	return head1 == head2
		? head1
		: 0;
}

int main()
{
	Node* ptail = new Node(3, new Node(4, new Node(5)));
	Node* phead1 = new Node(1, new Node(2, ptail));
	Node* phead2 = new Node(10, new Node(11, new Node(12, new Node(13, ptail))));

	cout << "List1: " << phead1 << endl;
	cout << "List2: " << phead2 << endl;

	const Node* tail = GetIntersectionNode(phead1, phead2);
	cout << "Tail: " << ptail << endl;
}