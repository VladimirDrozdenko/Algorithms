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
    List<std::pair<K, V>> seq;
    
public:
    explicit LRU(size_t size) : N(size) {
    }

    void put(const K& key, const V& value) {
        auto itr = table.find(key);
        if (itr == table.cend()) {
            if (table.size() == N + 1) {
                auto tail = seq.getTail();
                seq.removeNode(seq.getTail());
                table.erase(tail->value.first);
            }
            auto pn = seq.pushFront(new typename List<std::pair<K, V>>::Node(std::make_pair(key, value)));
            table.insert(std::make_pair(key, pn));
        } else {
            itr->second->value = std::make_pair(key, value);
        }
    }

    const V* get(K key) {
        auto itr = table.find(key);
        if (itr == table.cend()) {
            return nullptr;
        }

        typename List<std::pair<K, V>>::Node* node = itr->second;
        if (node != seq.getHead()) {
            seq.removeNode(node);
            seq.pushFront(node);
        }

        return &(node->value.second);
    }
};

#endif // LRU_LRU_H
