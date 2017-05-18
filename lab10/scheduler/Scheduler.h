//
// Created by Mateusz on 15.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstddef>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

namespace academia {
    class Schedule;

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots)=0;

    };

    class SchedulingItem {
    public:
        friend class Schedule;
        SchedulingItem(int corse_id_, int teacher_id_, int room_id_, int time_slot_, int year_);
        int CourseId()const;
        int TeacherId() const ;
        int RoomId()const;
        int TimeSlot()const;
        int Year()const;

    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule {
    public:
        Schedule();
        Schedule(std::vector<SchedulingItem> wektor);
        SchedulingItem operator[](const int &scheduled_item_number) const;
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        Schedule OfCourse(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

    private:
        std::vector<SchedulingItem> object_;

    };


    class GreedyScheduler: public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override ;

    private:
    };

    class NoViableSolutionFound {
    public:

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
