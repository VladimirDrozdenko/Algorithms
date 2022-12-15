//
// Created by Drozdenko, Vladimir on 12/12/22.
//

#ifndef LRU_LIST_H
#define LRU_LIST_H

template <typename T>
class List {
public:
    struct Node {
        T value;
        Node* prev, *next;

        explicit Node(const T& val, Node* pp = nullptr, Node* pn = nullptr)
                : value(val), prev(pp), next(pn) {
        }
    };
private:
    Node* head, *tail;

public:
    List() : head(nullptr), tail(nullptr) {
    }

    ~List() {
        Node* p = head;
        while (p != nullptr) {
            Node* pn = p->next;
            delete p;
            p = pn;
        }
    }

    Node* getHead() const {
        return head;
    }

    Node* getTail() const {
        return tail;
    }

    Node* pushFront(Node* const pNode) {
        pNode->prev = nullptr;
        pNode->next = head;
        head = pNode;

        if (head->next != nullptr) {
            head->next->prev = head;
        }

        if (tail == nullptr) {
            tail = head;
        }

        return head;
    }

    void removeNode(Node* const pNode) {
        if (pNode->prev != nullptr) {
            pNode->prev->next = pNode->next;
        }

        if (pNode->next != nullptr) {
            pNode->next->prev = pNode->prev;
        }

        if (pNode == head) {
            head = pNode->next;
        }

        if (pNode == tail) {
            tail = pNode->prev;
        }

        pNode->next = nullptr;
        pNode->prev = nullptr;
    }
};

#endif //LRU_LIST_H
