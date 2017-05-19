//
// Created by Mateusz on 15.05.2017.
//
#include "Scheduler.h"
using namespace academia;

#include <memory>
#include <iostream>
using ::std::unique_ptr;
using ::std::make_unique;
using ::std::vector;
using ::std::set;
using ::std::map;

int main(void){
    std::cout<<"hahah ";
    unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

    vector<int> rooms{1000,2000,3000};
    map<int, set<int>> years{make_pair(1, set<int>{10, 20, 11, 21}),
                             make_pair(2, set<int>{30, 40, 32, 42}),
                             make_pair(3, set<int>{50, 60, 53, 54}),
                             make_pair(4, set<int>{70, 80, 77, 79}),
                             make_pair(5, set<int>{90, 91, 92, 93})};

    map<int, vector<int>> teachers{make_pair(600, vector<int> {70, 80, 91, 92, 93}),
                                   make_pair(300, vector<int> {32}),
                                   make_pair(100, vector<int>{10, 20}),
                                   make_pair(500, vector<int> {77, 79, 90}),
                                   make_pair(200, vector<int>{11, 21, 30, 40}),

                                   make_pair(400, vector<int> {42, 50, 60, 53, 54})};
    Schedule schedule;


    std::cout<<scheduler->PrepareNewSchedule(rooms, teachers, years, 7).Size();


    map<int, vector<int>> nowy {make_pair(600, vector<int> {70, 80, 91, 92, 93}),
                                make_pair(300, vector<int> {32})};






}
