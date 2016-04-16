#include <iostream>
#include <stack>
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


bool IsPalindrome(const Node* head)
{
	if (!head || !head->next)
		return true;

	const Node* pS = head, *pF = head;
	while (pF && pF->next) {
		pF = pF->next->next;
		pS = pS->next;
	}

	if (pF)
		pS = pS->next;

	stack<const Node*> s;
	for (; pS; pS = pS->next)
		s.push(pS);

	while (!s.empty())
	{
		const Node* pn = s.top();
		s.pop();
		if (pn->val != head->val)
			return false;
		head = head->next;
	}

	return true;
}

void Report(const Node* plist)
{
	cout << plist << endl;
	if (IsPalindrome(plist))
		cout << "The list is a palindrome." << endl;
	else
		cout << "The list is NOT a palindrome." << endl;
}

int main()
{
	Node* listPalindrome1 = new Node(1, new Node(2, new Node(2, new Node(1))));
	Report(listPalindrome1);
	
	Node* listPalindrome2 = new Node(1, new Node(2, new Node(3, new Node(2, new Node(1)))));
	Report(listPalindrome2);

	Node* listNotPalindrome1 = new Node(1, new Node(3, new Node(2, new Node(1))));
	Report(listNotPalindrome1);
}