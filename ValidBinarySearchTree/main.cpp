#include <iostream>
#include "tree.h"
using namespace std;

static void TestTree(Node* root) {
    Node::print(root);

    cout << "Is BST: " << boolalpha << Node::isBST(root) << endl;

    Node::deleteTree(root);
}

int main() {
    Node* rootBST = new Node(5, new Node(2), new Node(7, new Node(6), new Node(9)));
    Node* rootTree = new Node(5, new Node(2), new Node(7, new Node(3), new Node(9)));

    TestTree(rootBST);

    cout << endl;

    TestTree(rootTree);    
}