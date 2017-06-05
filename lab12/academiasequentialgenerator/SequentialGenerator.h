//
// Created by Mateusz on 30.05.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class T, class C>
class SequentialIdGenerator {
public:

    SequentialIdGenerator();
    SequentialIdGenerator(C simple_type);

    T NextValue();

private:
    int counter_;
};


template <class T, class C>
SequentialIdGenerator<T,C>::SequentialIdGenerator() {
    counter_ = 0;
}


template <class T, class C>
SequentialIdGenerator<T,C>::SequentialIdGenerator(C simple_type) {
    counter_ = (int)simple_type;
}

template <class T, class C>
T SequentialIdGenerator<T,C>::NextValue() {
    return T{counter_++};
}


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
