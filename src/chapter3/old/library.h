//
// Created by crypt on 10/8/2016.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef CTCI_LIBRARY_TREENODE_H
#define CTCI_LIBRARY_TREENODE_H

template<typename T>
class BTreeNode {
public:
    T data;
    BTreeNode<T> *left;
    BTreeNode<T> *right;
    // BTreeNode<T> *parent;

    BTreeNode(T _data) : data(_data) {
        cout << " { new: " << data << " } ";
        this->left = nullptr;
        this->right = nullptr;
        //    this->parent = nullptr;
    }
};

template<typename T>
class BTree {
public:
    BTreeNode<T> *root;
    //BTreeNode<T> *last;


    BTree<T>() : root(nullptr) {
//        root = new BTreeNode<T>(value);
//        last = root;
    }
};

template<typename T, size_t size>
BTreeNode<T> *
recursiveBuilder(T (&datas)[size], size_t &i, size_t height) {

    if (i < size) {
        if (height > 0) {
            BTreeNode<T> *left = recursiveBuilder(datas, i, height - 1);
            BTreeNode<T> *newNode = nullptr;
            if (i < size) {
                newNode = new BTreeNode<T>(datas[i]);
            } else {
                return left;
            }
            i++;
            BTreeNode<T> *right = nullptr;
            if (i < size) right = recursiveBuilder(datas, i, height - 1);
            newNode->left = left;
            newNode->right = right;
            // if (left != nullptr) left->parent = newNode;
            // if (right != nullptr) right->parent = newNode;
            return newNode;
        } else { //if (height == 0){
            BTreeNode<T> *newNode = new BTreeNode<T>(datas[i]);
            i++;
            // newNode->parent->right = recursiveBuilder(datas, i ++ , height + 1);
            // newNode->parent->left = newNode;
            // return newNode->parent;
            return newNode;
        }
    } else {
        return nullptr;
    }

}


/*
template<typename T, size_t size>
void
recursiveBuilder(BTree<T>* tree, T (&datas)[size], size_t &i, size_t height ) {
    cout << "el: " << datas[i] << ", he: " << height;
    if ( height > 0 ) {
        BTreeNode<T> *newNode = new BTreeNode(datas[i]);
        if (tree->last->left == nullptr) {

            //T tmpData = tree->last->data;
            tree->last->data = newNode->data;
            newNode->data = tmpData;
            tree->last->left = ;
            height--;
            recursiveBuilder(tree,datas, i,height);
        }
        if( tree->last->right == nullptr ) {
            // Add to the right;
            tree->last->right = newNode;
            newNode->parent = tree->last;
            tree->last = newNode;
            recursiveBuilder(tree, datas, i , height);
        } else {

        }
    }
    i++;
}
*/

template<typename T, size_t size>
BTree<T> *
createBTree(T (&datas)[size]) {
    BTree<T> *tree = nullptr;
    //size_t depth;
    tree = new BTree<T>();
    //tree = new BTree<T>(datas[0]);
    // if (size > 0) {
    BTreeNode<T> *root = new BTreeNode<T>(datas[0]);
    size_t i = 1, height = 1;
    while (i < size) {
        //for (size_t i = 0, height = 0; i < size; i++, height++) {
        BTreeNode<T> *tmp;
        //= recursiveBuilder(datas, i, height );
        // if (root != nullptr && tmp != nullptr) {
        //tmp->left = root;
        if (i < size) {
            tmp = new BTreeNode<T>(datas[i]);
            i++;
            tmp->left = root;
            root = tmp;
            //root->left = tmp;

            if (i < size) {

                //i++;
                root->right = recursiveBuilder(datas, i, height - 1);
                height++;
            }
        } /*else {
                root = tmp;
            }*/
//            tmp->parent = root;


        //  }
        //i++;
    }
// }
    tree->root = root;
    return tree;
}

template<typename T>
void
buildStringTree(BTreeNode<T> *root, vector <vector<T>> &elements, int height = 0) {
    if (root != nullptr) {

        if (root->left != nullptr) buildStringTree(root->left, elements, height + 1);
        while (elements.size() < height) {
            //elements.push_back({});
            elements.resize(height);
        }
        elements.at(height).push_back(root->data);
        if (root->right != nullptr) buildStringTree(root->right, elements, height + 1);
    }

}

template<typename T>
void printTree(BTreeNode<T> *root) {

    if (root->left != nullptr) printTree(root->left);
    cout << root->data << " ";
    if (root->right != nullptr) printTree(root->right);

}

/*
#define SIZE 15

int main_chapter3() {

    //int data[] = {-4, -3, -2, -1, 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int data[SIZE];
    for (auto i = 0; i < SIZE; i++) {
//        cout << i << ' ';
        data[i] = i + 1;
    }

    auto tree = createBTree(data);
    printTree(tree->root);
    cout << endl << flush;

    // sleep(1);
    vector<vector<int>> elements(12);

    buildStringTree(tree->root, elements);
    for (vector<int> row : elements) {
        for (int c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "tree creation done";

    return 0;
*/
#endif //CTCI_LIBRARY_TREENODE_H
