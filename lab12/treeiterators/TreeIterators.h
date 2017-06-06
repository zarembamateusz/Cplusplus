//
// Created by Mateusz on 04.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include <memory>
#include <iostream>
#include <vector>
namespace tree{
    template<class T>
    class Tree {
    public:
        Tree();
        Tree(T value);
        void Insert(T value);
        T Value(){return value_;};
        int Size(){return size_;};
        auto Root(){ return this;} ;
        size_t Depth();
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        int size_;
        int depth_;
        T value_;

    };
    template<class T>
    Tree<T>::Tree():size_(0),depth_(0) {
        value_ = 0;
        left_ = nullptr;
        right_ = nullptr;
    }
    template<class T>
    Tree<T>::Tree(T value):size_(1),depth_(1){
        value_ = value;
        left_ = nullptr;
        right_ = nullptr;
    }
    template<class T>
    void Tree<T>::Insert(T value) {
        if (value > value_) {
            if (!right_)
                right_ = std::make_unique<Tree<T>>(value);
            else
                right_->Insert(value);
        }else {
            if (!left_)
                left_ = std::make_unique<Tree<T>>(value);
            else
                left_->Insert(value);
        }
        size_++;
    }

    template <class T>
    size_t Tree<T>::Depth(){
        if(left_ && right_)
            return 1+std::max(left_->Depth(),right_->Depth());
        else{
            if(left_)
                return 1+left_->Depth();
            if(right_)
                return 1+right_->Depth();
            return 1;
        }
    }

    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Tree<int> *value): number_(0){PrintTree(value);};
        void operator++(){number_+=1;};
        int operator*(){return iterator_vector[number_];};
        bool operator!=(const InOrderTreeIterator &sec)const{
            return (iterator_vector!=sec.iterator_vector||number_!=sec.number_);
        }
        std::vector<int> Vector(){return iterator_vector;}
        void SedIterator(int new_value){number_=new_value;};
        void PrintTree(Tree<T> *uniq);

    private:
        std::vector<int> iterator_vector;
        int number_;
    };

    template<class T>
    void InOrderTreeIterator<T>::PrintTree(Tree<T> *uniq) {
        if (uniq != nullptr) {
            PrintTree(uniq->left_.get());
            iterator_vector.push_back(int(uniq->Value()));
            PrintTree(uniq->right_.get());
        }
    }

    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<T> *tree) : i_(tree->Root()) {};
        InOrderTreeIterator<T> begin() {
            i_.SedIterator(0);
            return i_;
        }
        InOrderTreeIterator<T> end() {
            i_.SedIterator(i_.Vector().size()-1);
            return i_;
        }
    private:
        InOrderTreeIterator<T> i_;
    };
    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *value) {
        return InOrderTreeView<T>(value);
    };

    template<class T>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(Tree<T> *value): number_(0){PrintTree(value);};
        void operator++(){number_+=1;};
        T operator*(){return iterator_vector[number_];};
        bool operator!=(const PreOrderTreeIterator &sec)const{
            return (iterator_vector!=sec.iterator_vector||number_!=sec.number_);
        }
        std::vector<T> Vector(){return iterator_vector;}
        void SedIterator(int new_value){number_=new_value;};
        void PrintTree(Tree<T> *uniq);

    private:
        std::vector<T> iterator_vector;
        int number_;
    };

    template<class T>
    void PreOrderTreeIterator<T>::PrintTree(Tree<T> *uniq) {
        if (uniq != nullptr) {
            iterator_vector.push_back(uniq->Value());
            PrintTree(uniq->left_.get());
            PrintTree(uniq->right_.get());
        }
    }

    template <class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<T> *tree) : i_(tree->Root()) {};
        PreOrderTreeIterator<T> begin() {
            i_.SedIterator(0);
            return i_;
        }
        PreOrderTreeIterator<T> end() {
            i_.SedIterator(i_.Vector().size()-1);
            return i_;
        }
    private:
        PreOrderTreeIterator<T> i_;
    };
    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    };
    template<class T>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(Tree<T> *value): number_(0){PrintTree(value);};
        void operator++(){number_+=1;};
        T operator*(){return iterator_vector[number_];};
        bool operator!=(const PostOrderTreeIterator &sec)const{
            return (iterator_vector!=sec.iterator_vector||number_!=sec.number_);
        }
        std::vector<T> Vector(){return iterator_vector;}
        void SedIterator(int new_value){number_=new_value;};
        void PrintTree(Tree<T> *uniq);

    private:
        std::vector<T> iterator_vector;
        int number_;
    };
    template<class T>
    void PostOrderTreeIterator<T>::PrintTree(Tree<T> *uniq) {
        if (uniq != nullptr) {

            PrintTree(uniq->left_.get());
            PrintTree(uniq->right_.get());
            iterator_vector.push_back(uniq->Value());
        }
    }

    template <class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(Tree<T> *tree) : i_(tree->Root()) {};
        PostOrderTreeIterator<T> begin() {
            i_.SedIterator(0);
            return i_;
        }
        PostOrderTreeIterator<T> end() {
            i_.SedIterator(i_.Vector().size()-1);
            return i_;
        }

    private:
        PostOrderTreeIterator<T> i_;
    };
    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    };

}

#endif //JIMP_EXERCISES_TREEITERATORS_H