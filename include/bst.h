// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>
template<typename T>
struct node {
    T key;
    int count;
    node* right, * left;
    explicit node(T k) : key(k), count(1), right(nullptr), left(nullptr) {}
};
template<typename T>
class BST {
private:
    node<T>* tree;
    int getHeight(node<T>* point) {
        if (point == nullptr)
            return 0;
        int hright = getHeight(point->right);
        int hleft = getHeight(point->left);
        return ++std::max(hright, hleft);
    }
    node<T>* insert(node<T>* p, T k) {
        if (p == nullptr) {
            p = new node<T>(k);
        }
        else if (p->key < k) {
            p->right = insert(p->right, k);
        }
        else if (p->key > k) {
            p->left = insert(p->left, k);
        }
        else {
            p->count++;
        }
        return p;
    }
    int findValue(node<T>* p, T k) {
        if (p->key == k)
            return p->count;
        else if (p->key < k)
            return findValue(p->right, k);
        else if (p->key > k)
            return findValue(p->left, k);
        else
            return 0;
    }
    void deleteTree(node<T>* p) {
        if (p == nullptr)
            return;
        deleteTree(p->left);
        deleteTree(p->right);
        delete p;
        p = nullptr;
    }

public:
    BST() : tree(nullptr) {}
    void insert(T k) {
        tree = insert(tree, k);
    }
    int search(T k) {
        return findValue(tree, k);
    }
    int depth() {
        return --getHeight(tree);
    }
    ~BST() {
        deleteTree(tree);
    }
};
#endif  // INCLUDE_BST_H_
