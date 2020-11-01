#include "Temperature_Type.hpp"


namespace afzm {


const std::vector<Temperature_Type::System> Temperature_Type::systems_ = {System::None};
const std::vector<Temperature_Type::Type> Temperature_Type::all_types_ = {Type::Celsius, Type::Kelvin, Type::Fahrenheit, Type::Rankine,
                                                                Type::Delisle, Type::Newton, Type::Reaumur, Type::Romer};
const std::vector<Temperature_Type::Prefix> Temperature_Type::prefixes_ = {Prefix::None};

std::string Temperature_Type::getTypeName(Temperature_Type::Type type){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        return "Celsius";
        break;
    case Temperature_Type::Type::Kelvin:
        return "Kelvin";
        break;
    case Temperature_Type::Type::Fahrenheit:
        return "Fahrenheit";
        break;
    case Temperature_Type::Type::Rankine:
        return "Rankine";
        break;
    case Temperature_Type::Type::Delisle:
        return "Delisle";
        break;
    case Temperature_Type::Type::Newton:
        return "Newton";
        break;
    case Temperature_Type::Type::Reaumur:
        return "Réaumur";
        break;
    case Temperature_Type::Type::Romer:
        return "Romer";
        break;

    default:
        return "None";
    }
}

std::string Temperature_Type::getSystemName(){
    return "None";
}

std::string Temperature_Type::getPrefixName(){
    return "None";
}

Temperature_Type::System Temperature_Type::getSystem(){
    return System::None;
}

Temperature_Type::System Temperature_Type::getSystemEnum()
{
    return System::None;
}

Temperature_Type::Type Temperature_Type::getTypeEnum(const std::string& name)
{
    for(const auto& type: all_types_){
        if (name == getTypeName(type)){
            return type;
        }
    }
    return Type::None;
}

Temperature_Type::Prefix Temperature_Type::getPrefixEnum()
{
    return Prefix::None;
}

};
