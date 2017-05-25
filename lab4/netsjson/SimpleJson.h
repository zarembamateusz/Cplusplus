//
// Created by Mateusz on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
namespace nets {

    class JsonValue {
    public:
        JsonValue(const int &str);
        JsonValue(const double &str);
        JsonValue(const bool &str);
        JsonValue(const std::string &str);
        JsonValue(const std::vector<JsonValue> &str);
        JsonValue(const std::map<std::string, JsonValue> &str);


        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        int int_=_NULL;
        double double_=_NULL;
        bool bool_;
        std::string str_;
        std::vector<JsonValue> vector_;
        std::map<std::string, JsonValue> map_;

    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
