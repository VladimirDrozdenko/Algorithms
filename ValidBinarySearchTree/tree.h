#ifndef ___MY_TREE_H___
#define ___MY_TREE_H___

#include <iostream>
#include <limits>
#include <string>

struct Node {
    int value;
    Node* left, *right;

    Node(int val, Node* pl = nullptr, Node* pr = nullptr) 
        : value(val), left(pl), right(pr) {}

    static void deleteTree(Node* root) {
        if (root) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    static void print(Node* root, std::string prefix = "") {
        if (root) {
            std::cout << prefix << root->value << std::endl;
            print(root->left, prefix + "  ");
            print(root->right, prefix + "  ");
        }
    }

    static bool isBST(Node* root) {
        return helperIsBST(root, 
            std::numeric_limits<int>::min(), 
            std::numeric_limits<int>::max());
    }

private:
    static bool helperIsBST(Node* root, int min, int max) {
        if (root == nullptr) {
            return true;
        }

        if (root->value <= min || root->value >= max) {
            return false;
        }

        return helperIsBST(root->left, min, root->value) 
            && helperIsBST(root->right, root->value, max);
    }
};


#endif //___MY_TREE_H___
