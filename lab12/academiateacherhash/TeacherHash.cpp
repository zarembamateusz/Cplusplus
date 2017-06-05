//
// Created by Mateusz on 30.05.2017.
//
#include "TeacherHash.h"

namespace academia {
    academia::TeacherId::TeacherId(int id) {
        id_ = id;
    }

    int TeacherId::GetId() const {
        return id_;
    }

    TeacherId::operator int() const {
        return id_;
    }

    string Teacher::Name() const {
        return name_;
    }

    string Teacher::Department() const {
        return department_;
    }

    Teacher::Teacher(TeacherId id, string name, string department) : id_(id.GetId()) {
        name_ = name;
        department_ = department;
    }

    TeacherId Teacher::Id() const {
        return id_;
    }

    bool operator==(const Teacher &fir, const Teacher &sec) {
        bool n = false;
        if (fir.Id() == sec.Id() && fir.Name() == sec.Name() && fir.Department() == sec.Department())
            n = true;
        return n;
    }

    bool operator!=(const Teacher &fir, const Teacher &sec) {
        bool n = false;
        if (fir.Id() != sec.Id() || fir.Name() != sec.Name() || fir.Department() != sec.Department())
            n = true;
        return n;
    }


    size_t TeacherHash::operator()(Teacher const &teacher) const {
        size_t value = 0;
        value = value + teacher.Id();
        for (int i = 0; i < teacher.Name().size(); i++)
            value = value + (int) teacher.Name()[i];
        for (int j = 0; j < teacher.Department().size(); j++)
            value = value + teacher.Department()[j];
        return value;
    }
}