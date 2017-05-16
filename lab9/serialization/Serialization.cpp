//
// Created by Mateusz on 10.05.2017.
//

#include "Serialization.h"

namespace academia{


    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_serializator) << std::string("\""s + field_name + "\": "s + std::to_string(value));
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_serializator) << std::string("\""s + field_name + "\": " + std::to_string(value));
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_serializator) << std::string("\""s + field_name + "\": "s + "\""s + value + "\""s);
    }

    void JsonSerializer::Header(const std::string &object_name) {
        (*out_serializator) << std::string(object_name);
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        (*out_serializator) << std::string(object_name);
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_serializator) << std::string("<" + field_name + ">" + std::to_string(value) + "<\\" + field_name + ">");
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_serializator) << std::string("<" + field_name + ">" + std::to_string(value) + "<\\" + field_name + ">");
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_serializator) << std::string("<" + field_name + ">" + value + "<\\" + field_name + ">");
    }

    void XmlSerializer::Header(const std::string &object_name) {
        (*out_serializator) << std::string("<" + object_name + ">");
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        (*out_serializator) << std::string("<\\" + object_name + ">");
    }

    void BuildingRepository::Add(Building &building) {
        building_.push_back(building);
    }

    void BuildingRepository::StoreAll(Serializer *serializer)const {
        vector<reference_wrapper<const Serializable>> reference;
        serializer->Header("building_repository");
        for(const Building &v : building_)
        {
            reference.emplace_back(v);
        }
        serializer->ArrayField("buildings", reference);
        serializer->Footer("building_repository");

    }

    void BuildingRepository::StoreAll(XmlSerializer *xmlserializer) {
        xmlserializer->Header("building_repository");
        xmlserializer->Header("buildings");
        for(auto &v : building_)
        {

            v.Serialize(xmlserializer);

        }
        xmlserializer->Footer("buildings");
        xmlserializer->Footer("building_repository");
    }

    void BuildingRepository::StoreAll(JsonSerializer *jsonserializer) {
        jsonserializer->AddToOutput("{\"buildings\": [");
        int leng = 0;
        for(auto &v : building_)
        {
            leng++;
            v.Serialize(jsonserializer);
            if(leng < building_.size()) jsonserializer->AddToOutput(", ");
        }
        jsonserializer->AddToOutput("]}");

    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const{
        for(int i = 0; i < building_.size();i++)
        {
            if(building_[i].Id() == id) return experimental::make_optional(building_[i]);
        }
    }
}