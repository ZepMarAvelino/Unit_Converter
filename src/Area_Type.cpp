#include "Area_Type.hpp"

namespace afzm{

const std::vector<Area_Type::System> Area_Type::systems_ {System::None, System::Metric, System::Imperial, System::US_Customary};
const std::vector<Area_Type::Type> Area_Type::metric_types_ {Type::Metre_Square, Type::Fermi_Square, Type::Angstrom_Square, Type::Micron_Square,
                            Type::Myriametre_Square, Type::X_Unit_Square, Type::Hectare};
const std::vector<Area_Type::Type> Area_Type::imperial_types_ {Type::Point_Square, Type::Pica_Square, Type::Thou_Square, Type::Inch_Square,
                                     Type::Foot_Square, Type::Yard_Square, Type::Chain_Square, Type::Furlong_Square,
                                     Type::Mile_Square, Type::League_Square, Type::Rood, Type::Acre};
const std::vector<Area_Type::Type> Area_Type::us_types_ {Type::Survey_Link_Square, Type::Survey_Inch_Square, Type::Survey_Foot_Square, Type::Rod_Square,
                               Type::Survey_Chain_Square, Type::Survey_Furlong_Square, Type::Section, Type::Survey_League_Square,
                               Type::Survey_Acre, Type::Survey_Township};
const std::vector<Area_Type::Prefix> Area_Type::prefixes_ {Prefix::None, Prefix::yocto, Prefix::zepto, Prefix::atto, Prefix::femto,
                        Prefix::pico, Prefix::nano, Prefix::micro, Prefix::milli, Prefix::centi, Prefix::deci, Prefix::deca,
                        Prefix::hecto, Prefix::kilo, Prefix::mega, Prefix::giga, Prefix::tera, Prefix::peta, Prefix::exa,
            Prefix::zetta, Prefix::yotta};



std::string Area_Type::getTypeName(Area_Type::Type type, Area_Type::Prefix prefix){
    switch (type)
    {
    case Type::Metre_Square:
        switch (prefix)
        {
        case Prefix::yocto:
            return "Square yoctometre";
            break;
        case Prefix::zepto:
            return "Square zeptometre";
            break;
        case Prefix::atto:
            return "Square attometre";
            break;
        case Prefix::femto:
            return "Square femtometre";
            break;
        case Prefix::pico:
            return "Square picometre";
            break;
        case Prefix::nano:
            return "Square nanometre";
            break;
        case Prefix::micro:
            return "Square micrometre";
            break;
        case Prefix::milli:
            return "Square millimetre";
            break;
        case Prefix::centi:
            return "Square centimetre";
            break;
        case Prefix::deci:
            return "Square decimetre";
            break;
        case Prefix::deca:
            return "Square decametre";
            break;
        case Prefix::hecto:
            return "Square hectometre";
            break;
        case Prefix::kilo:
            return "Square kilometre";
            break;
        case Prefix::mega:
            return "Square megametre";
            break;
        case Prefix::giga:
            return "Square gigametre";
            break;
        case Prefix::tera:
            return "Square terametre";
            break;
        case Prefix::peta:
            return "Square petametre";
            break;
        case Prefix::exa:
            return "Square exametre";
            break;
        case Prefix::zetta:
            return "Square zettametre";
            break;
        case Prefix::yotta:
            return "Square yottametre";
            break;

        default:
            return "Square metre";
            break;
        }
        break;
    case Type::Fermi_Square:
        return "Square fermi";
        break;
    case Type::Angstrom_Square:
        return "Square ångström";
        break;
    case Type::Micron_Square:
        return "Square micron";
        break;
    case Type::Myriametre_Square:
        return "Square myriametre";
        break;
    case Type::X_Unit_Square:
        return "Square x unit";
        break;
    case Type::Hectare:
        return "Hectare";
        break;
    case Type::Point_Square:
        return "Square point";
        break;
    case Type::Pica_Square:
        return "Square pica";
        break;
    case Type::Thou_Square:
        return "Square thou";
        break;
    case Type::Inch_Square:
        return "Square inch";
        break;
    case Type::Foot_Square:
        return "Square foot";
        break;
    case Type::Yard_Square:
        return "Square yard";
        break;
    case Type::Chain_Square:
        return "Square chain (short)";
        break;
    case Type::Furlong_Square:
        return "Square furlong";
        break;
    case Type::Mile_Square:
        return "Square mile";
        break;
    case Type::League_Square:
        return "Square league";
        break;
    case Type::Rood:
        return "Rood";
        break;
    case Type::Acre:
        return "Acre";
        break;
    case Type::Survey_Link_Square:
        return "Square survey link";
        break;
    case Type::Survey_Inch_Square:
        return "Square survey inch";
        break;
    case Type::Survey_Foot_Square:
        return "Square survey foot";
        break;
    case Type::Rod_Square:
        return "Square rod";
        break;
    case Type::Survey_Chain_Square:
        return "Square survey chain";
        break;
    case Type::Survey_Furlong_Square:
        return "Square survey furlong";
        break;
    case Type::Section:
        return "Section";
        break;
    case Type::Survey_League_Square:
        return "Square survey league";
        break;
    case Type::Survey_Acre:
        return "Survey acre";
        break;
    case Type::Survey_Township:
        return "Survey township";
        break;

    default:
        return "None";
    }
}

std::string Area_Type::getSystemName(Area_Type::Type type){
    switch (type)
    {
    case Type::Metre_Square:
    case Type::Fermi_Square:
    case Type::Angstrom_Square:
    case Type::Micron_Square:
    case Type::Myriametre_Square:
    case Type::X_Unit_Square:
    case Type::Hectare:
        return "Metric";
        break;
    case Type::Point_Square:
    case Type::Pica_Square:
    case Type::Thou_Square:
    case Type::Inch_Square:
    case Type::Foot_Square:
    case Type::Yard_Square:
    case Type::Chain_Square:
    case Type::Furlong_Square:
    case Type::Mile_Square:
    case Type::League_Square:
    case Type::Rood:
    case Type::Acre:
        return "Imperial";
        break;
    case Type::Survey_Link_Square:
    case Type::Survey_Inch_Square:
    case Type::Survey_Foot_Square:
    case Type::Survey_Chain_Square:
    case Type::Rod_Square:
    case Type::Survey_Furlong_Square:
    case Type::Section:
    case Type::Survey_League_Square:
    case Type::Survey_Acre:
    case Type::Survey_Township:
        return "US Customary";
        break;

    default:
        return "None";
    }
}

std::string Area_Type::getSystemName(Area_Type::System system){
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

std::string Area_Type::getPrefixName(Area_Type::Prefix prefix){
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

Area_Type::System Area_Type::getSystem(Area_Type::Type type){
    switch (type)
    {
    case Type::Metre_Square:
    case Type::Fermi_Square:
    case Type::Angstrom_Square:
    case Type::Micron_Square:
    case Type::Myriametre_Square:
    case Type::X_Unit_Square:
    case Type::Hectare:
        return System::Metric;
        break;
    case Type::Point_Square:
    case Type::Pica_Square:
    case Type::Thou_Square:
    case Type::Inch_Square:
    case Type::Foot_Square:
    case Type::Yard_Square:
    case Type::Chain_Square:
    case Type::Furlong_Square:
    case Type::Mile_Square:
    case Type::League_Square:
    case Type::Rood:
    case Type::Acre:
        return System::Imperial;
        break;
    case Type::Survey_Link_Square:
    case Type::Survey_Inch_Square:
    case Type::Survey_Foot_Square:
    case Type::Rod_Square:
    case Type::Survey_Chain_Square:
    case Type::Survey_Furlong_Square:
    case Type::Section:
    case Type::Survey_League_Square:
    case Type::Survey_Acre:
    case Type::Survey_Township:
        return System::US_Customary;
        break;

    default:
        return System::None;
    }
}

Area_Type::System Area_Type::getSystemEnum(const std::string& name)
{

    for(const auto& system: systems_){
        if (name == getSystemName(system)){
            return system;
        }
    }
    return System::None;
}

Area_Type::Type Area_Type::getTypeEnum(const std::string& name)
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

Area_Type::Prefix Area_Type::getPrefixEnum(const std::string& name)
{

    for(const auto& prefix: prefixes_){
        if (name == getPrefixName(prefix)){
            return prefix;
        }
    }
    return Prefix::None;
}


};
