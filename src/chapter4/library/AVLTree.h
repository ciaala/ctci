//
// Created by crypt on 10/10/2016.
//

#ifndef CTCI_LIBRARY_AVLTREE_H
#define CTCI_LIBRARY_AVLTREE_H


#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


template<typename T>
class AVLTree {
public:

    class AVLTreeNode {
    public:
        T value;
        int height;

        AVLTreeNode *left;
        AVLTreeNode *right;
        AVLTreeNode *parent;

    public:
        AVLTreeNode(T value)
                : value(value), height(0),
                  left(nullptr), right(nullptr), parent(nullptr) {
        }

        int getBalanceFactor() const {
            int leftHeight = this->left != nullptr ? this->left->height : 0;
            int rightHeight = this->right != nullptr ? this->right->height : 0;
            int balance = rightHeight - leftHeight;
            // (leftHeight > rightHeight) ? (leftHeight - rightHeight) : (rightHeight - leftHeight);
            return balance;
        }

        void setLeft(AVLTreeNode *node) {
            this->left = node;
            if (node != nullptr) {
                node->parent = this;
            }
        }

        void setRight(AVLTreeNode *node) {
            this->right = node;
            if (node != nullptr) {
                node->parent = this;
            }
        }

        bool isRightChild() {
            return (this->parent != nullptr) && (this->parent->right == this);
        }

        bool isLeftChild() {
            return (this->parent != nullptr) && (this->parent->left == this);
        }

        T &getValue() { return value; }

        void fix_height() {
            int leftHeight = this->left != nullptr ? this->left->height : -1;
            int rightHeight = this->right != nullptr ? this->right->height : -1;
            this->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        }
    };


private:
    AVLTreeNode *root;
public:
    AVLTree() : root(nullptr) {
    }

    AVLTreeNode *getRoot() const {
        return this->root;
    }

///////////////////////////////////////////////////////

    /**
     *            (Q)
     *           /  \
     *         (P)  (C)
     *        /  \
     *      (A) (B)
     *
     *            (P)
     *           /  \
     *         (A)  (Q)
     *             /  \
     *           (B)  (C)
     */
    AVLTreeNode *right_rotation(AVLTreeNode *nodeQ) {
        AVLTreeNode *parent = nodeQ->parent;
        AVLTreeNode *nodeP = nodeQ->left;
        AVLTreeNode *nodeB = nodeP->right;
        if (parent->left == nodeQ) {
            parent->setLeft(nodeP);
        } else if (parent->right == nodeQ) {
            parent->setRight(nodeP);
        } else {
            root = nodeP;
        }

        nodeP->setRight(nodeQ);
        nodeQ->setLeft(nodeB);
        return nodeP;
    }

    /**
     *            [P]
     *           /  \
     *         (A)  [Q]
     *             /  \
     *           [B]  (C)
     *
     *                 (Q)
     *                /  \
     *              [P]  (C)
     *             /  \
     *           (A) [B]
     *
     */
    AVLTreeNode *
    left_rotation(AVLTreeNode *nodeP) {
        AVLTreeNode *parent = nodeP->parent;
        AVLTreeNode *nodeQ = nodeP->right;
        AVLTreeNode *nodeB = nodeQ->left;
        if (nodeP->isLeftChild()) {
            parent->setLeft(nodeQ);
        } else if (nodeP->isRightChild()) {
            parent->setRight(nodeQ);
        }
        /*
        else {
            root = nodeQ;
            nodeQ->parent = nullptr;

        }
        */
        nodeQ->setLeft(nodeP);

        nodeP->setRight(nodeB);

        if (nodeP != nullptr) {
            nodeP->fix_height();
        };

        if (nodeQ != nullptr) {
            nodeQ->fix_height();
        };
        return nodeQ;
    }


    AVLTreeNode *addValue(T t) {
        AVLTreeNode *node = new AVLTreeNode(t);
        root = this->insert(root, node);
        return node;
    }

    virtual
    AVLTreeNode *insert(AVLTreeNode *current, AVLTreeNode *node) {
        if (current == nullptr) return node;

        if (current->getValue() > node->getValue()) {
            current->setLeft(insert(current->left, node));
        } else if (current->getValue() < node->getValue()) {
            current->setRight(insert(current->right, node));
        }
        return updateBalance(current);
    }

    virtual AVLTreeNode *
    updateBalance(AVLTreeNode *node) {
        if (node != nullptr) node->fix_height();

        // Keep the parent before any potential rotation
        // AVLTreeNode *parent;

        int balanceFactor = node->getBalanceFactor();
        if (balanceFactor > 1) {
            return left_rotation(node);
        } else if (balanceFactor < -1) {
            return right_rotation(node);
        }
        return node;
    }

    void
    prepareNodePerLevels(vector <vector<AVLTreeNode *>> &nodePerLevels,
                         AVLTreeNode *current,
                         size_t level = 0) const {
        if (current == nullptr) {
            current = root;
        }
        if (nodePerLevels.size() <= level) {
            nodePerLevels.push_back(vector<AVLTreeNode *>());
        }
        nodePerLevels.at(level).push_back(current);
        if (current->left != nullptr) {
            this->prepareNodePerLevels(nodePerLevels, current->left, level + 1);
        }
        if (current->right != nullptr) {
            this->prepareNodePerLevels(nodePerLevels, current->right, level + 1);
        }
    }

    friend
    ostream &operator<<(ostream &out, const AVLTree<T> &tree) {
        vector <vector<AVLTreeNode *>> nodePerLevels;
        AVLTree<T>::AVLTreeNode *rootNode = tree.getRoot();
        tree.prepareNodePerLevels(nodePerLevels, rootNode);
        int j = 0;
        for (auto it = nodePerLevels.begin();
             it != nodePerLevels.end();
             it++) {

            out << '[' << setw(2) << j << ']' << "\t";
            for (size_t i = 0; i < it->size(); i++) {
                AVLTreeNode *at = it->at(i);
                char side = (at->isRightChild()) ? 'R' : (at->isLeftChild() ? 'L' : ' ');
                out << side;
                out << setw(2) << at->getValue() << "~" << at->height << "\t";
            }
            out << endl;
            j++;
        }
        return out;
    }
};

#endif //CTCI_LIBRARY_AVLTREE_H
