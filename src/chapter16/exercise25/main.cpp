//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

namespace exercise16_25 {

    template<typename Key, typename Value>
    class LRUCache {
    public:
        class LRUEntry {
        public:
            LRUEntry(Key key, Value value) :
                    key(key), value(value),
                    next(nullptr), prev(nullptr) { }

            Value value;
            Key key;
            LRUEntry *next;
            LRUEntry *prev;
        };

    private:
        unordered_map<Key, LRUEntry *> cache;
        LRUEntry *front;
        LRUEntry *back;
        unsigned long int capacity;

        void refresh(Key &key) {
            LRUEntry *entry = cache[key];
            if (entry != nullptr) {
                //
                // NOTE: && entry != front
                // only if the back has some prev
                // edge case one single element with capacity to 1
                //
                if (entry == back && entry != front) {
                    back = entry->prev;
                    entry->prev->next = nullptr;
                }
                if (entry != front) {
                    //
                    // Reposition
                    // extract
                    //
                    if (entry->prev != nullptr) {
                        entry->prev->next = entry->next;
                    }
                    if (entry->next != nullptr) {
                        entry->next->prev = entry->prev;
                    }
                    //
                    // MOVE TO
                    // FRONT
                    //
                    entry->next = front;
                    front->prev = entry;
                    entry->prev = nullptr;
                    front = entry;
                } else {
                    // It is Already Front
                    // nothing to do
                }

            }
        }

    public:

        LRUCache(unsigned long int capacity = (2 << 16)) : front(nullptr), back(nullptr), capacity(capacity),
                                                           cache(capacity) { }

        void insert(Key key, Value value) {
            if (cache.count(key) > 0) {
                cache[key]->value = value;
                refresh(key);
            } else {
                LRUEntry *entry = new LRUEntry(key, value);
                cache.emplace(key, entry);
                if (front == nullptr && back == nullptr) {
                    back = entry;
                    front = entry;
                    return;
                }
                if (cache.size() > capacity) {
                    back->prev->next = nullptr;
                    LRUEntry *tmp = back;
                    back = back->prev;
                    cache.erase(tmp->key);
                    delete tmp;
                }
                entry->next = front;
                front->prev = entry;
                front = entry;


            }
        }

        bool contains(Key key) {
            return cache.count(key) > 0;
        }

        Value get(Key key) {
            if (cache.count(key) > 0) {
                refresh(key);
                return cache[key]->value;
            }
        }

        ~LRUCache() {
            for_each(cache.begin(), cache.end(), [](auto item) {
                delete item.second;
            });
        }
    };

    void main() {

        LRUCache<int, string> cache(4);
        cache.insert(1, "one");
        cache.insert(2, "two");

        cache.insert(3, "three");
        cache.insert(4, "four");
        cache.get(1);
        cache.insert(5, "five");
        cache.insert(6, "six");

        assert(cache.contains(1) == 1);
        assert(cache.contains(2) == 0);
        assert(cache.contains(3) == 0);
        assert(cache.contains(4) == 1);
        assert(cache.contains(5) == 1);
        assert(cache.contains(6) == 1);
    }

}
