//
// Created by Mateusz on 10.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<string>
#include <vector>
#include <functional>
#include <experimental/optional>

using namespace std;
using namespace std::literals;

namespace academia {

    class Building;
    class Serializable;

    class Serializer{
    public:

        Serializer(std::ostream *out): out_serializator(out) {}

        virtual void IntegerField(const std::string &field_name, int value) {}
        virtual void DoubleField(const std::string &field_name, double value) {}
        virtual void StringField(const std::string &field_name, const std::string &value) {}
        virtual void BooleanField(const std::string &field_name, bool value) {}
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) {}
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value) {}
        virtual void Header(const std::string &object_name) {}
        virtual void Footer(const std::string &object_name) {}

    protected:
        std::ostream *out_serializator;
    };

    class JsonSerializer{
    public:

        JsonSerializer(std::ostream *out) : out_serializator(out) {}

        virtual void IntegerField(const std::string &field_name, int value);
        virtual void DoubleField(const std::string &field_name, double value);
        virtual void StringField(const std::string &field_name, const std::string &value);
        virtual void BooleanField(const std::string &field_name, bool value) {}
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) {}
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value) {}
        virtual void Header(const std::string &object_name);
        virtual void Footer(const std::string &object_name);


        virtual void AddToOutput(std::string in) { (*out_serializator) << in; }
        virtual void AddCommaToOutput() { (*out_serializator) << std::string(", "); }

    protected:
        std::ostream *out_serializator;
    };

    class XmlSerializer{
    public:

        XmlSerializer(std::ostream *out) : out_serializator(out) {}

        virtual void IntegerField(const std::string &field_name, int value);
        virtual void DoubleField(const std::string &field_name, double value);
        virtual void StringField(const std::string &field_name, const std::string &value);
        virtual void BooleanField(const std::string &field_name, bool value) {}
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) {}
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value) {}
        virtual void Header(const std::string &object_name);
        virtual void Footer(const std::string &object_name);

    protected:
        std::ostream *out_serializator;

    };


    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer) =0;
        virtual void Serialize(JsonSerializer *jsonserializer) =0;
        virtual void Serialize(XmlSerializer *xmlserializer) =0;
    };

    class Room : public Serializable{
    public:

        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };

        Room(int id, std::string room_number, Type typ): id_(id), room_number_(room_number), typ_(typ) {}

        std::string EnumToString(Type type) {
            switch(type) {
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::CLASSROOM:
                    return "CLASSROOM";
            }
        }

        void Serialize(Serializer *serializer) override{
            serializer->Header("Room");
            serializer->IntegerField("Id", id_);
            serializer->StringField("room number", room_number_);
            serializer->StringField("type", EnumToString(typ_));
            serializer->Footer("Room");
        }

        void Serialize(JsonSerializer *jsonserializer) override {
            jsonserializer->Header("{");
            jsonserializer->IntegerField("id", id_);
            jsonserializer->AddCommaToOutput();
            jsonserializer->StringField("name", room_number_);
            jsonserializer->AddCommaToOutput();
            jsonserializer->StringField("type", EnumToString(typ_));
            jsonserializer->Footer("}");
        }

        void Serialize(XmlSerializer *xmlserializer) override {
            xmlserializer->Header("room");
            xmlserializer->IntegerField("id", id_);
            xmlserializer->StringField("name", room_number_);
            xmlserializer->StringField("type", EnumToString(typ_));
            xmlserializer->Footer("room");
        }

    private:
        int id_;
        std::string room_number_;
        Type typ_;
    };


    class Building : public Serializable{
    public:
        Building(int id, std::string name, std::initializer_list<Room> rooms): id_(id), name_(name) {
            for(const auto &v : rooms)
            {
                rooms_.push_back(v);
            }
        }


        void Serialize(Serializer *serializer) override {}

        void Serialize(JsonSerializer* jsonserializer) override {
            jsonserializer->Header("{");
            jsonserializer->IntegerField("id", id_);
            jsonserializer->AddCommaToOutput();
            jsonserializer->StringField("name", name_);
            jsonserializer->AddCommaToOutput();
            jsonserializer->AddToOutput("\""s + "rooms" + "\": "s);
            jsonserializer->Header("[");
            int leng = 0;
            for(auto &v : rooms_)
            {
                leng++;
                v.Serialize(jsonserializer);
                if(leng < rooms_.size()) jsonserializer->AddToOutput(", ");
            }
            jsonserializer->Footer("]");
            jsonserializer->Footer("}");
        }

        void Serialize(XmlSerializer *xmlserializer) override {
            xmlserializer->Header("building");
            xmlserializer->IntegerField("id", id_);
            xmlserializer->StringField("name", name_);
            xmlserializer->Header("rooms");
            for(auto &v : rooms_)
            {
                v.Serialize(xmlserializer);
            }
            xmlserializer->Footer("rooms");
            xmlserializer->Footer("building");
        }

        int Id() const { return id_; }

    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;

    };


    class BuildingRepository{
    public:

        BuildingRepository(std::initializer_list<Building> arg) {
            for(auto &v : arg) building_.push_back(v);
        }


        void Add(Building &building);

        void StoreAll(Serializer *serializer)const;
        void StoreAll(XmlSerializer *xmlserializer);
        void StoreAll(JsonSerializer *jsonserializer);

        std::experimental::optional<Building> operator[](int id)const;

    private:
        vector<Building> building_;
    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H