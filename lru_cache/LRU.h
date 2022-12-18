//
// Created by Drozdenko, Vladimir on 12/12/22.
//

#ifndef LRU_LRU_H
#define LRU_LRU_H

#include <unordered_map>
#include "List.h"

template <typename K, typename V>
class LRU {
private:
    size_t N;
    std::unordered_map<K, typename List<std::pair<K, V>>::Node*> table;
    List<typename std::pair<K, V>> seq;
    
public:
    explicit LRU(size_t size) : N(size) {
    }

    void put(const K& key, const V& value) {
        auto itr = table.find(key);
        if (itr == table.cend()) {
            if (table.size() == N) {
                // remove the oldest value
                auto tail = seq.getTail();
                seq.removeNode(seq.getTail());
                table.erase(tail->value.first);
            }

            // add a new value to the top of the cache
            auto pNode = seq.pushFront(new typename List<std::pair<K, V>>::Node(std::make_pair(key, value)));
            table.insert(std::make_pair(key, pNode));
        } else {
            // ensure it is the first one in the list
            auto pNode = itr->second;
            if (seq.getHead() != pNode) {
                seq.removeNode(pNode);
                seq.pushFront(pNode);
            }

            // update existing value
            pNode->value = std::make_pair(key, value);
        }
    }

    const V* get(const K& key) {
        auto itr = table.find(key);
        if (itr == table.cend()) {
            return nullptr;
        }

        typename List<std::pair<K, V>>::Node* pNode = itr->second;
        if (pNode != seq.getHead()) {
            seq.removeNode(pNode);
            seq.pushFront(pNode);
        }

        return &(pNode->value.second);
    }
};

#endif // LRU_LRU_H
