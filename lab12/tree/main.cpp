//
// Created by Mateusz on 25.05.2017.
//

#include "Tree.h"
using namespace tree;
int main(){
    Tree<int> tree {5};
    auto value = tree.Value();
    std::cout<<tree.Depth()<<std::endl;
    tree.Insert(0);
    std::cout<<tree.Depth()<<std::endl;
    tree.Insert(102);
    std::cout<<tree.Depth()<<std::endl;
    tree.Insert(890);
    std::cout<<tree.Depth()<<std::endl;
    tree.Insert(81);
    std::cout<<tree.Depth()<<std::endl;
    tree.Insert(-1);
    std::cout<<tree.Depth()<<std::endl;


    return 0;
}
