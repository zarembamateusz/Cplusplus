//
// Created by Mateusz on 20.03.2017.
//

#include "SmartTree.h"
#include <iostream>
#include <sstream>
#include <regex>

namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto pointer = std::make_unique<SmartTree>();
        pointer->value = value;
        pointer->left = nullptr;
        pointer->right = nullptr;
        return pointer;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        std::unique_ptr<SmartTree> tmp = nullptr;
        tree->left = move(left_subtree);
        tmp = move(tree);
        return tmp;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        std::unique_ptr<SmartTree> tmp = nullptr;
        tree->right = move(right_subtree);
        tmp = move(tree);
        return tmp;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr != nullptr) {
            PrintTreeInOrder(unique_ptr->left, out);
            *out << unique_ptr->value << ", ";;
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    void dodawanie(const std::unique_ptr<SmartTree> &tree, std::string *ss, int &k, int &l) {

        if (tree != nullptr) {
            std::string tmp;
            sprintf((char *) tmp.c_str(), "%d", tree->value);
            std::string nowy = tmp.c_str();
            *ss += "[";
            *ss += nowy;
            *ss += " ";
            dodawanie(tree->left, ss, k, l);
            *ss += "]";
            *ss += " ";
            dodawanie(tree->right, ss, k, l);
            *ss += "]";
        } else
            *ss += "[none";
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        int k = 0;
        int l = 0;
        std::string ss;
        dodawanie(tree, &ss, k, l);
        ss += "]";
        return ss;
    }


    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        unsigned sept = 0;
        std::regex pattern{R"(\[(-*\d+|none)\s(.*))"};
        std::smatch matches;
        std::unique_ptr<SmartTree> leaf;
        if(std::regex_match(tree, matches, pattern)) {
            std::string child = matches[2].str();
            for(unsigned j=0; j<child.size();j++) {
                if(child[j]=='[') {
                    sept=sept+1;
                }
                else if(child[j]==']') {
                    sept=sept-1;
                }
                else if(sept==0) {
                    sept=j;
                    break;
                }
            }

            std::string left = child.substr(0, sept);
            std::string right = child.substr(sept + 1, child.size() - 1);
            leaf = CreateLeaf(std::stoi(matches[1]));
            leaf = InsertLeftChild(std::move(leaf), RestoreTree(left));
            leaf = InsertRightChild(std::move(leaf), RestoreTree(right));
        }
        return leaf;
    }

}


