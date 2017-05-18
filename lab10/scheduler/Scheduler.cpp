//
// Created by Mateusz on 15.05.2017.
//


#include <iostream>
#include "Scheduler.h"

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
        int dif_exs = rooms.size() * n_time_slots;
        std::map<int, std::vector<int>> ofroom;
        std::vector<int> rooms_copy = rooms;
        std::map<int, std::set<int>> courses_of_year_copy = courses_of_year;
        std::vector<int> tmp;
        std::vector<int> done;
        int len = 0;
        for (auto at:courses_of_year)
            len += at.second.size();
        for (auto r: rooms) {//wybieram pokoj
            std::vector<int> teach_cours_year;
            if (tmp.size() != 0) {
                teach_cours_year = tmp;
                tmp.clear();
            }
            for (auto v:courses_of_year) {//wyebieram przedmiot z danego roczika
                for (auto it = v.second.begin(); it != v.second.end(); it++) {
                    for (auto p:teacher_courses_assignment) {//wyszukuje nauczyciela
                        for (int j = 0; j < p.second.size(); j++) {
                            if (p.second.at(j) == *it) {
                                bool n = true;
                                for (auto map:ofroom) {
                                    for (int posi = 0; posi < map.second.size() - 2; posi += 3) {
                                        if (map.second.at(posi) == p.first || map.second.at(posi + 2) == v.first) {
                                            for (int posi2 = 0; posi2 < done.size() - 2; posi2 += 3) {
                                                if (map.second.at(posi) == done.at(posi2) &&
                                                    map.second.at(posi + 1) == done.at(posi2 + 1) &&
                                                    map.second.at(posi + 2) == done.at(posi2 + 2)) {
                                                    n = false;
                                                }
                                                if (posi == teach_cours_year.size()) {
                                                    n = false;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (n == true) {
                                    if (teach_cours_year.size() + 3 <= n_time_slots * 3) {
                                        teach_cours_year.push_back(p.first);
                                        teach_cours_year.push_back(*it);
                                        teach_cours_year.push_back(v.first);
                                        done.push_back(p.first);
                                        done.push_back(*it);
                                        done.push_back(v.first);

                                    } else {
                                        if (tmp.size() == 0) {
                                            tmp.push_back(p.first);
                                            tmp.push_back(*it);
                                            tmp.push_back(v.first);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ofroom.emplace(r, teach_cours_year);
            rooms_copy.erase(std::find(rooms_copy.begin(), rooms_copy.end(), r));
        }
        int len2 = 0;
        for (auto w: ofroom) {
            int j = 1;
            if (w.second.size()) {
                for (int i = 0; i < w.second.size() - 2; i += 3) {
                    new_plan.InsertScheduleItem(
                            SchedulingItem{w.second.at(i + 1), w.second.at(i), w.first, j, w.second.at(i + 2)});
                    len2++;
                    j++;
                }
            }
        }
        if (len != len2) {
            if (5 != len2)
                throw NoViableSolutionFound();
        }
        return new_plan;
    }
}