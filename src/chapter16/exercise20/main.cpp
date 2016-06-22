//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <atomic>
#include <memory>

using namespace std;

namespace exercise16_20 {

    template<typename T, typename TData>
    class TrieNode {

    private:
        unsigned long id;
        static atomic<unsigned long> Counter;
        TData data;
        T value;
        unordered_map<T, shared_ptr<TrieNode<T, TData>>> children;
    public:
        TrieNode<T, TData>() {
            this->id = Counter++;
        }

        TrieNode<T, TData>(T value, TData data) : value(value), data(data) {
            this->id = Counter++;
        }

        shared_ptr<TrieNode<T, TData>> getChild(const T &value) {
            return this->children.find(value);
        }

        ~TrieNode() {
            cout << "Deleting[" << this->id << "]: " << this->value << endl;
            /*
             for_each(children.begin(), children.end(),
                     [](auto item) {
                         delete item.second;
                     });
            //delete data;
             */
        }

        shared_ptr<TrieNode<T, TData>> addChild(T value, TData data) {
            auto item = make_shared<TrieNode<T, TData>>(value, data);
            this->children.emplace(value, item);
            return item;
        }
    };

    template<typename T, typename TData>
    atomic<unsigned long> TrieNode<T, TData>::Counter = {0};

    void main() {
        TrieNode<char, vector<string>> root;
        root.addChild('c', {"ciao"});
        root.addChild('d', {"bau"})->addChild('e',{"ciao"});

    }

}
