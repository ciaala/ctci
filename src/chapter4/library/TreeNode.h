#ifndef CTCI_LIBRARY_TREENODE_H
#define CTCI_LIBRARY_TREENODE_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinaryTreeNode {
private:
    T t;
    unsigned int height;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *parent;


public:
    BinaryTreeNode(T t) :
            t(t),
            height(0),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {

    }

    BinaryTreeNode<T> *
    getRight() { return right; }

    BinaryTreeNode<T> *
    getLeft() { return left; }

    void
    setRight(BinaryTreeNode<T> *node) {
        this->right = node;
        node->parent = this;
    }

    void
    setLeft(BinaryTreeNode<T> *node) {
        this->left = node;
        node->parent = this;
    }


    bool
    isLeftChild() {
        return (this->parent != nullptr && this->parent->left == this);
    }

    bool
    isRightChild() {
        return (this->parent != nullptr && this->parent->righ == this);
    }


    BinaryTreeNode<T> *
    getParent() { return parent; }

    T &
    getValue() { return t; }

    virtual ~BinaryTreeNode() {
        cout << "Deleting " << this->t << endl;
        if (left) { delete left; }
        if (right) { delete right; }
        delete this;
    }


    unsigned int getHeight() const {
        return height;
    }

    void setHeight(unsigned int height) {
        this->height = height;
    }

    virtual void
    addValue(BinaryTreeNode<T> *node) {
        if (this->t > node->t) {
            if (this->left != nullptr) {
                node->height++;
                this->left->addValue(node);
            } else {
                this->left = node;
                node->parent = this;
            }
        } else if (this->t < node->t) {
            if (this->right != nullptr) {
                node->height++;
                this->right->addValue(node);
            } else {
                this->right = node;
                node->parent = this;
            }
        }
    }
};


template<typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;
    unsigned height;
public :

    BinaryTree() : root(nullptr), height(0) {}

/*
    void fix_height(BinaryTreeNode<T> *node) {
        if (node->getParent() != nullptr && node->getParent()->getParent() != nullptr) {
            BinaryTreeNode<T> *parent = node->getParent();
            BinaryTreeNode<T> *granny = parent->getParent();
            if (granny->getLeft() == nullptr) {
                granny->setRight(node);
                node->setHeight(node->getHeight() - 1);

                granny->setLeft(parent);
                parent->setHeight(parent->getHeight() - 1);
            }
        }
    }
*/
    BinaryTreeNode<T> *addValue(T t) {
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>(t);
        if (root != nullptr) {
            root->addValue(node);
        } else {
            root = node;
        }
        return node;
    }

    BinaryTreeNode<T> *getRoot() const {
        return root;
    }

    void
    prepareNodePerLevels(vector <vector<BinaryTreeNode<T> *>> &nodePerLevels,
                         BinaryTreeNode<T> *current,
                         size_t level = 0) const {
        if (current == nullptr) {
            current = root;
        }
        nodePerLevels.at(level).push_back(current);
        if (current->getLeft() != nullptr) {
            this->prepareNodePerLevels(nodePerLevels, current->getLeft());
        }
        if (current->getRight() != nullptr) {
            this->prepareNodePerLevels(nodePerLevels, current->getRight());
        }
    }

    friend
    ostream &operator<<(ostream &out, const BinaryTree<T> &tree) {
        vector <vector<BinaryTreeNode<T> *>> nodePerLevels;

        tree.prepareNodePerLevels(nodePerLevels, tree.getRoot());

        for (auto it = nodePerLevels.begin();
             it != nodePerLevels.end();
             it++) {
            for (size_t i = 0; i < it->size(); i++) {
                out << it->at(i);
            }
        }
        return out;
    }

};


#endif //CTCI_LIBRARY_TREENODE_H