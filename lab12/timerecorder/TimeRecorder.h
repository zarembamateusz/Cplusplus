//
// Created by kubas1129 on 30.05.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <iostream>
#include <chrono>
#include <unordered_map>

namespace profiling{




    template <class F>
     auto TimeRecorder(F foo){
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        foo();
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        //std::cout << "Elapsed time:" << elapsed.count()*10.f;
        return std::make_pair<decltype(foo()), double>(foo(), elapsed.count()*1000.f);
    };

}


#endif //JIMP_EXERCISES_TIMERECORDER_H
