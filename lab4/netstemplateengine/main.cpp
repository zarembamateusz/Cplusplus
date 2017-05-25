//
// Created by Mateusz on 27.03.2017.
//
#include "SimpleTemplateEngine.h"
#include <string>
#include <unordered_map>
#include <iostream>


using namespace nets;
int main(){
/*
    std::unordered_map<std::string,std::string> map ={{"name","Xavier"}};
    View view{"Hello {{name}}!"};
    std::cout << view.Render(map);
    */
    /*std::unordered_map<std::string,std::string> map ={{"test", "888"}};
    View view{"test {{test}} of {test} but {{test} or {test}} and {{{test}}}"};
    std::cout << view.Render(map);*/
    
    std::unordered_map<std::string,std::string> map ={{"test", "replacement"}};
    View view{"Test {{test}} missing:{{missing}}:missing"};
    std::cout << view.Render(map);
    

    return 0;
}



