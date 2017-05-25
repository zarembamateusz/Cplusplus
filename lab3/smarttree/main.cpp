//
// Created by Mateusz on 16.03.2017.
//
#include "SmartTree.h"
#include <string>
#include <memory>
#include <map>
#include <iostream>
#include <sstream>
using namespace datastructures;
int main(){
    std::stringstream ss;
    std::string tmp;
    auto root = CreateLeaf(99);
    root = InsertLeftChild(move(root), CreateLeaf(100));
    root = InsertRightChild(move(root), CreateLeaf(88));
    root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(897));
    root->right = InsertRightChild(move(root->right), CreateLeaf(761));


    std::cout<<DumpTree(root);

    


    return 0;
}