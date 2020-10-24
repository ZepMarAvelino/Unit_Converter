#include "Mass_Type.hpp"

namespace afzm{

const std::vector<Mass_Type::System> Mass_Type::systems_ = {System::None, System::Metric, System::Imperial, System::US_Customary};
const std::vector<Mass_Type::Type> Mass_Type::metric_types_ = {Type::Gram, Type::Tonne, Type::Carat};
const std::vector<Mass_Type::Type> Mass_Type::imperial_types_ = {Type::Grain, Type::Drachm, Type::Ounce, Type::Pound, Type::Stone, Type::Quarter,
                                    Type::Hundredweight, Type::Ton};
const std::vector<Mass_Type::Type> Mass_Type::us_types_ = {Type::Dram, Type::US_Hundredweight, Type::US_Ton, Type::Pennyweight, Type::Troy_Ounce, Type::Troy_Pound};
const std::vector<Mass_Type::Prefix> Mass_Type::prefixes_ = {Prefix::None, Prefix::yocto, Prefix::zepto, Prefix::atto, Prefix::femto, Prefix::pico, Prefix::nano,
                                 Prefix::micro, Prefix::milli, Prefix::centi, Prefix::deci, Prefix::deca, Prefix::hecto, Prefix::kilo,
                                                       Prefix::mega, Prefix::giga, Prefix::tera, Prefix::peta, Prefix::exa, Prefix::zetta, Prefix::yotta};

std::string Mass_Type::getTypeName(Mass_Type::Type type, Mass_Type::Prefix prefix){
    switch (type)
    {
    case Type::Gram:
        switch (prefix)
        {
        case Prefix::yocto:
            return "yoctogram";
            break;
        case Prefix::zepto:
            return "zeptogram";
            break;
        case Prefix::atto:
            return "attogram";
            break;
        case Prefix::femto:
            return "femtogram";
            break;
        case Prefix::pico:
            return "picogram";
            break;
        case Prefix::nano:
            return "nanogram";
            break;
        case Prefix::micro:
            return "microgram";
            break;
        case Prefix::milli:
            return "milligram";
            break;
        case Prefix::centi:
            return "centigram";
            break;
        case Prefix::deci:
            return "decigram";
            break;
        case Prefix::deca:
            return "decagram";
            break;
        case Prefix::hecto:
            return "hectogram";
            break;
        case Prefix::kilo:
            return "kilogram";
            break;
        case Prefix::mega:
            return "megagram";
            break;
        case Prefix::giga:
            return "gigagram";
            break;
        case Prefix::tera:
            return "teragram";
            break;
        case Prefix::peta:
            return "petagram";
            break;
        case Prefix::exa:
            return "exagram";
            break;
        case Prefix::zetta:
            return "zettagram";
            break;
        case Prefix::yotta:
            return "yottagram";
            break;

        default:
            return "Gram";
            break;
        }
        break;
    case Type::Tonne:
        return "Tonne";
        break;
    case Type::Carat:
        return "Carat";
        break;
    case Type::Grain:
        return "Grain";
        break;
    case Type::Drachm:
        return "Drachm";
        break;
    case Type::Ounce:
        return "Ounce";
        break;
    case Type::Pound:
        return "Pound";
        break;
    case Type::Stone:
        return "Stone";
        break;
    case Type::Quarter:
        return "Quarter";
        break;
    case Type::Hundredweight:
        return "Hundredweight";
        break;
    case Type::Ton:
        return "Ton";
        break;
    case Type::Dram:
        return "Dram";
        break;
    case Type::US_Hundredweight:
        return "Hundredweight (US)";
        break;
    case Type::US_Ton:
        return "Ton (US)";
        break;
    case Type::Pennyweight:
        return "Pennyweight";
        break;
    case Type::Troy_Ounce:
        return "Troy ounce";
        break;
    case Type::Troy_Pound:
        return "Troy pound";
        break;

    default:
        return "None";
    }
}

std::string Mass_Type::getSystemName(Mass_Type::Type type){
    switch (type)
    {
    case Type::Gram:
    case Type::Tonne:
    case Type::Carat:
        return "Metric";
        break;
    case Type::Grain:
    case Type::Drachm:
    case Type::Ounce:
    case Type::Pound:
    case Type::Stone:
    case Type::Quarter:
    case Type::Hundredweight:
    case Type::Ton:
        return "Imperial";
        break;
    case Type::Dram:
    case Type::US_Hundredweight:
    case Type::US_Ton:
    case Type::Pennyweight:
    case Type::Troy_Ounce:
    case Type::Troy_Pound:
        return "US Customary";
        break;

    default:
        return "None";
    }
}

std::string Mass_Type::getSystemName(Mass_Type::System system){
    switch (system)
    {
    case System::Metric:
        return "Metric";
        break;
    case System::Imperial:
        return "Imperial";
        break;
    case System::US_Customary:
        return "US Customary";
        break;

    default:
        return "None";
        break;
    }
}

std::string Mass_Type::getPrefixName(Mass_Type::Prefix prefix){
    switch (prefix)
    {
    case Prefix::yocto:
        return "yocto";
        break;
    case Prefix::zepto:
        return "zepto";
        break;
    case Prefix::atto:
        return "atto";
        break;
    case Prefix::femto:
        return "femto";
        break;
    case Prefix::pico:
        return "pico";
        break;
    case Prefix::nano:
        return "nano";
        break;
    case Prefix::micro:
        return "micro";
        break;
    case Prefix::milli:
        return "milli";
        break;
    case Prefix::centi:
        return "centi";
        break;
    case Prefix::deci:
        return "deci";
        break;
    case Prefix::deca:
        return "deca";
        break;
    case Prefix::hecto:
        return "hecto";
        break;
    case Prefix::kilo:
        return "kilo";
        break;
    case Prefix::mega:
        return "mega";
        break;
    case Prefix::giga:
        return "giga";
        break;
    case Prefix::tera:
        return "tera";
        break;
    case Prefix::peta:
        return "peta";
        break;
    case Prefix::exa:
        return "exa";
        break;
    case Prefix::zetta:
        return "zetta";
        break;
    case Prefix::yotta:
        return "yotta";
        break;

    default:
        return "None";
        break;
    }
}

Mass_Type::System Mass_Type::getSystem(Mass_Type::Type type){
    switch (type)
    {
    case Type::Gram:
    case Type::Tonne:
    case Type::Carat:
        return System::Metric;
        break;
    case Type::Grain:
    case Type::Drachm:
    case Type::Ounce:
    case Type::Pound:
    case Type::Stone:
    case Type::Quarter:
    case Type::Hundredweight:
    case Type::Ton:
        return System::Imperial;
        break;
    case Type::Dram:
    case Type::US_Hundredweight:
    case Type::US_Ton:
    case Type::Pennyweight:
    case Type::Troy_Ounce:
    case Type::Troy_Pound:
        return System::US_Customary;
        break;

    default:
        return System::None;
    }
}

Mass_Type::System Mass_Type::getSystemEnum(const std::string& name)
{

    for(const auto& system: systems_){
        if (name == getSystemName(system)){
            return system;
        }
    }
    return System::None;
}

Mass_Type::Type Mass_Type::getTypeEnum(const std::string& name)
{

    for(const auto& metric: metric_types_){
        if (name == getTypeName(metric)){
            return metric;
        }
    }
    for(const auto& imperial: imperial_types_){
        if (name == getTypeName(imperial)){
            return imperial;
        }
    }
    for(const auto& us_customary: us_types_){
        if (name == getTypeName(us_customary)){
            return us_customary;
        }
    }
    return Type::None;
}

Mass_Type::Prefix Mass_Type::getPrefixEnum(const std::string& name)
{

    for(const auto& prefix: prefixes_){
        if (name == getPrefixName(prefix)){
            return prefix;
        }
    }
    return Prefix::None;
}

};
