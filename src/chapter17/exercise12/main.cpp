//
// Created by crypt on 24/06/16.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace exercise17_12 {
#define myassert(a, b) __myassert(#a, a, b)

    class BiNode {
    public :
        BiNode *left;
        BiNode *right;
        int data;

        BiNode(int data) : data(data), right(nullptr), left(nullptr){ }

    };

    void buildSortedLinkedList(BiNode *node, BiNode **left, BiNode **right) {
        if (node->right != nullptr) {
            buildSortedLinkedList(node->right, &(node->right), right);
            node->right->left = node;
        } else {
            *right = node;
        }
        if (node->left != nullptr) {
            buildSortedLinkedList(node->left, left, &(node->left));
            node->left->right = node;
        } else {
            *left = node;
        }
    }

    void main() {
        BiNode *bi = new BiNode(12);
        bi->left = new BiNode(8);
        bi->left->left = new BiNode(2);
        bi->left->left->right = new BiNode(4);
        bi->left->left->left = new BiNode(1);
        bi->left->right = new BiNode(10);
        bi->left->right->left = new BiNode(9);
        bi->left->right->right = new BiNode(11);

        //
        bi->right = new BiNode(16);
        //bi->right->right = new BiNode(17);
        bi->right->left = new BiNode(14);
        bi->right->left->left = new BiNode(13);


        BiNode *start;
        BiNode *end;
        buildSortedLinkedList(bi, &start, &end);

        while (start != nullptr) {
            cout << start->data << " ";
            start = start->right;
        }
        cout << endl;


    }
}

