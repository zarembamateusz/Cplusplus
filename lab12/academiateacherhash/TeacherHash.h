//
// Created by Mateusz on 30.05.2017.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>
#include <unordered_map>
namespace academia {
    using std::string;

    class TeacherId{
    public:
        TeacherId(int id);
        int GetId() const ;
        operator int() const;

    private:
        int id_;

    };

    class Teacher{
    public:
        Teacher(TeacherId id,string name_,string department);
        string Name()const;
        string Department ()const;
        TeacherId Id ()const;

    private:
        string name_;
        string department_;
        TeacherId id_;

    };

    class TeacherHash{
    public:
        size_t operator ()(Teacher const& teacher) const;
    };

    bool operator==(const Teacher &fir, const Teacher &sec);
    bool operator!=(const Teacher &fir, const Teacher &sec);


}

#endif //JIMP_EXERCISES_TEACHERHASH_H
