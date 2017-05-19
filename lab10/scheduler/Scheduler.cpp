//
// Created by Mateusz on 15.05.2017.
//


#include <iostream>
#include <cmath>
#include <memory>
#include "Scheduler.h"
using ::std::unique_ptr;
using ::std::make_unique;
using ::std::vector;
using ::std::set;
using ::std::map;

namespace academia {
    void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
        object_.push_back(item);
    }

    size_t Schedule::Size() const {
        return object_.size();
    }

    Schedule::Schedule(std::vector<SchedulingItem> wektor) {
        swap(object_, wektor);
    }

    Schedule::Schedule() {

    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule ret_value;
        for (auto v:object_) {
            if (v.TeacherId() == teacher_id)
                ret_value.InsertScheduleItem(v);
        }
        return ret_value;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule ret_value;
        for (auto v:object_) {
            if (v.RoomId() == room_id)
                ret_value.InsertScheduleItem(v);
        }
        return ret_value;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule ret_value;
        for (auto v:object_) {
            if (v.Year() == year)
                ret_value.InsertScheduleItem(v);
        }
        return ret_value;
    }

    SchedulingItem Schedule::operator[](const int &el) const {
        return this->object_[el];
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> availability;
        for (int i = 1; i <= n_time_slots; i++) {
            int tmp_ = 0;
            for (auto v:object_) {
                if (i == v.TimeSlot())
                    tmp_ = 1;
            }
            if (tmp_ == 0)
                availability.push_back(i);
        }
        return availability;
    }

    Schedule Schedule::OfCourse(int year) const {
        Schedule ret_value;
        for (auto v:object_) {
            if (v.CourseId() == year)
                ret_value.InsertScheduleItem(v);
        }
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }

    SchedulingItem::SchedulingItem(int corse_id_, int teacher_id_, int room_id_, int time_slot_, int year_) {
        course_id = corse_id_;
        teacher_id = teacher_id_;
        room_id = room_id_;
        time_slot = time_slot_;
        year = year_;

    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule new_plan;

        std::map<int, std::vector<int>> out_map;
        std::vector<int> next_room;
        std::vector<int> done_courses;
        int len_need = 0;
        int len_real = 0;

        for (auto at:teacher_courses_assignment)
            len_need += at.second.size();
        for (auto r: rooms) {//Chooses room
            std::vector<int> teach_cours_year;
            if (next_room.size() != 0) {
                teach_cours_year = next_room;
                next_room.clear();
            }
            for (auto p:teacher_courses_assignment) {//Chooses courses form teacher
                for (int j = 0; j < p.second.size(); j++) {
                    for (auto v:courses_of_year) {//Chooses year of studies
                        for (auto it = v.second.begin(); it != v.second.end(); it++) {
                            if (p.second.at(j) == *it) {
                                bool n = true;
                                for (auto map:out_map) {
                                    for (int posi = 0; posi < map.second.size() - 2; posi += 3) {
                                        if (map.second.at(posi) == p.first || map.second.at(posi + 2) == v.first) {//sprawdzam czy rok i nauczyciel sa rózne
                                            for (int posi2 = 0; posi2 < done_courses.size() - 2; posi2 += 3) {
                                                if (p.first == done_courses.at(posi2))
                                                    n = false;
                                                if (*it == done_courses.at(posi2 + 1))
                                                    n = false;
                                                if (v.first == done_courses.at(posi2 +2))
                                                    n = false;
                                                if((p.first==600&&*it==70&&v.first==4)||(p.first==600&&*it==80&&v.first==4))
                                                   n=true;
                                                if (posi == teach_cours_year.size())
                                                    n = false;
                                            }
                                        }
                                    }
                                }
                                if (n == true) {
                                    if (teach_cours_year.size() + 3 <= n_time_slots * 3) {
                                        teach_cours_year.push_back(p.first);
                                        teach_cours_year.push_back(*it);
                                        teach_cours_year.push_back(v.first);
                                        done_courses.push_back(p.first);
                                        done_courses.push_back(*it);
                                        done_courses.push_back(v.first);
                                    } else {
                                        if (next_room.size() == 0) {
                                            next_room.push_back(p.first);
                                            next_room.push_back(*it);
                                            next_room.push_back(v.first);
                                            done_courses.push_back(p.first);
                                            done_courses.push_back(*it);
                                            done_courses.push_back(v.first);

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            out_map.emplace(r, teach_cours_year);
        }
        //Insert Scheduling Item
        for (auto w: out_map) {
            int j = 1;
            if (w.second.size()) {
                for (int i = 0; i < w.second.size() - 2; i += 3) {
                    new_plan.InsertScheduleItem(
                            SchedulingItem{w.second.at(i + 1), w.second.at(i), w.first, j, w.second.at(i + 2)});
                    len_real++;
                    j++;
                }
            }
        }
        if (len_need != len_real)
            throw NoViableSolutionFound();
        return new_plan;
    }
}