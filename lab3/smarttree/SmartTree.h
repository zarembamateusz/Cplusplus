//
// Created by Mateusz on 20.03.2017.
//
//All test works
#include <string>
#include <memory>
#include <map>
#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#endif //JIMP_EXERCISES_SMARTTREE_H
namespace datastructures{

    struct SmartTree{
        int value;
        std::unique_ptr <SmartTree> left;
        std::unique_ptr <SmartTree> right;

    };
    std::string dodawanie(const std::unique_ptr<SmartTree> &tree, std::string tmp,int &k,int &l);
    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);


}