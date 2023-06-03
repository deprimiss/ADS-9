// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string w;
    if (file) {
        while (!file.eof()) {
            char ch = file.get();
            if (isalpha(ch) && ch != ' ') {
                    ch = tolower(ch);
                w += ch;
            } else {
                tree.insert(w);
                w.clear();
            }
        }
    } else {
        std::cout << "Error!" << std::endl;
    }
    file.close();
    return tree;
}
