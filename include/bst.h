// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>
template<typename T>
struct Node {
    T key;
    Node* right, * left;
    int count;
    explicit Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
};
template<typename T>
class BST {
 private:
    Node<T>* tree;
    int getHeight(Node<T>* p) {
        if (p == nullptr)
            return 0;
        int hright = getHeight(p->right);
        int hleft = getHeight(p->left);
        return 1 + std::max(hright, hleft);
    }
    node<T>* insert(Node<T>* p, T k) {
        if (p == nullptr) {
            p = new Node<T>(k);
        } else if (p->key > k) {
            p->left = insert(p->left, k);
        } else if (p->key < k) {
            p->right = insert(p->right, k);
        } else {
            p->count++;
        }
        return p;
    }
    int findVal(Node<T>* p, T k) {
        if (p->key == k)
            return p->count;
        else if (p->key < k)
            return findVal(p->right, k);
        else if (p->key > k)
            return findVal(p->left, k);
        else
            return 0;
    }
    void deleteTree(Node<T>* p) {
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
        return findVal(tree, k);
    }
    int depth() {
        return getHeight(tree) - 1;
    }
    ~BST() {
        deleteTree(tree);
    }
};
#endif  // INCLUDE_BST_H_
