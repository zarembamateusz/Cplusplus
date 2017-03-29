//
// Created by Mateusz on 27.03.2017.
//

#include "SimpleJson.h"
#include <sstream>
#include <iostream>

namespace nets {
    JsonValue::JsonValue(const int &str) {
        int_ = str;
    }

    JsonValue::JsonValue(const double &str) {
        double_ = str;
    }

    JsonValue::JsonValue(const bool &str) {
        bool_ = str;
    }

    JsonValue::JsonValue(const std::string &str) {
        std::string convert;
        convert+='\"';
        for (int i = 0; i < str.size(); i++) {
            if ((str[i] == '\"') || (str[i] == '\\')) {
                convert +="\\";
                convert+=str[i];
            }
            else
                convert+=str[i];
        }
        convert+='\"';
        str_ = convert;
    }

    JsonValue::JsonValue(const std::vector<JsonValue> &str) {
        vector_ = str;
    }

    JsonValue::JsonValue(const std::map<std::string, JsonValue> &str) {
        std::string convert;
        std::string convert2;
        std::map<std::string, JsonValue> tmp;

        for(auto v:str) {
            convert=convert2;
            convert += '\"';
            for (int i = 0; i < v.first.size(); i++) {
                if ((v.first[i] == '\"') || (v.first[i] == '\\')) {
                    convert += "\\";
                    convert += v.first[i];
                } else
                    convert += v.first[i];
            }
            convert += '\"';
            tmp.insert(std::pair <std::string, JsonValue>(convert,v.second));
        }
        map_ = tmp;
    }

    std::string JsonValue::ToString() const {
        std::stringstream convert;
        if (int_!=_NULL)
            convert << int_;
        else if (double_!=_NULL)
            convert << double_;
        else if (vector_.size() > 0) {
            convert << "[";
            for (int i = 0; i < vector_.size(); i++) {
                if(i<vector_.size()-1)
                    convert << vector_.at(i).ToString() << ", ";
                else
                    convert << vector_.at(i).ToString();
            }
            convert << "]";
        } else if (map_.size() > 0) {
            convert << "{";
            int k=1;
            for (auto v:map_) {
                if(map_.size()==k)
                    convert << v.first << ": " << v.second.ToString();
                else
                    convert << v.first << ": " << v.second.ToString()<<", ";
                k++;
            }
            convert << "}";
            std::cout<<convert.str()<<std::endl;
        }
        else if (str_.size()>0) {
            convert << str_;
        }
        else if (bool_)
            convert << "true";
        else
            convert << "false";
        return convert.str();
    }



    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        std::stringstream tmp;
        for (auto v:map_) {
            if (v.first == name) {
                return v.second;
            }
        }


    }

}
