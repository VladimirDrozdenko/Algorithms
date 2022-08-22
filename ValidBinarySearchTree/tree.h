#ifndef ___MY_TREE_H___
#define ___MY_TREE_H___

#include <iostream>
#include <limits>
#include <stack>
#include <string>

struct Node {
    int value;
    Node* left, *right;

    Node(int val, Node* pl = nullptr, Node* pr = nullptr) 
        : value(val), left(pl), right(pr) {}

    static void deleteTree(const Node* root) {
        if (root) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    static void print(const Node* root, std::string prefix = "") {
        if (root) {
            std::cout << prefix << root->value << std::endl;
            print(root->left, prefix + "  ");
            print(root->right, prefix + "  ");
        }
    }

    static bool recursiveIsBST(const Node* root) {
        return helperIsBST(root, 
            std::numeric_limits<int>::min(), 
            std::numeric_limits<int>::max());
    }

    static bool isBST(const Node* root) {
        std::stack<const Node*> s;

        for (const Node* p = root; p; p = p->left) {
            s.push(p);
        }

        const Node* prev = nullptr;

        while(!s.empty()) {
            const Node* current = s.top();

            if (prev) {
                if (prev->value >= current->value) {
                    return false;
                }    
            }

            prev = current;
            
            s.pop();

            for (const Node* pp = current->right; pp; pp = pp->left) {
                s.push(pp);
            }
        }

        return true;
    }

private:
    static bool helperIsBST(const Node* root, int min, int max) {
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
