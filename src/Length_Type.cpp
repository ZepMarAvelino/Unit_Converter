#include "Length_Type.hpp"


namespace afzm{

const std::vector<Length_Type::System> Length_Type::systems_ {System::None, System::Metric, System::Imperial, System::US_Customary};
const std::vector<Length_Type::Type> Length_Type::metric_types_ {Type::Metre, Type::Fermi, Type::Angstrom, Type::Micron, Type::Myriametre, Type::X_Unit};
const std::vector<Length_Type::Type> Length_Type::imperial_types_ {Type::Point, Type::Pica, Type::Thou, Type::Inch, Type::Foot, Type::Yard, Type::Chain,
                                    Type::Furlong, Type::Mile, Type::League, Type::Fathom, Type::Short_Cable, Type::Long_Cable,
                                     Type::Nautical_Mile};
const std::vector<Length_Type::Type> Length_Type::us_types_ {Type::Link, Type::Survey_Inch, Type::Survey_Foot, Type::Rod, Type::Survey_Chain, Type::Survey_Furlong,
                              Type::Survey_Mile, Type::Survey_League};
const std::vector<Length_Type::Prefix> Length_Type::prefixes_ {Prefix::None, Prefix::yocto, Prefix::zepto, Prefix::atto, Prefix::femto, Prefix::pico, Prefix::nano,
                                 Prefix::micro, Prefix::milli, Prefix::centi, Prefix::deci, Prefix::deca, Prefix::hecto, Prefix::kilo,
            Prefix::mega, Prefix::giga, Prefix::tera, Prefix::peta, Prefix::exa, Prefix::zetta, Prefix::yotta};



std::string Length_Type::getTypeName(Length_Type::Type type, Length_Type::Prefix prefix){
    switch (type)
    {
    case Type::Metre:
        switch (prefix)
        {
        case Prefix::yocto:
            return "yoctometre";
            break;
        case Prefix::zepto:
            return "zeptometre";
            break;
        case Prefix::atto:
            return "attometre";
            break;
        case Prefix::femto:
            return "femtometre";
            break;
        case Prefix::pico:
            return "picometre";
            break;
        case Prefix::nano:
            return "nanometre";
            break;
        case Prefix::micro:
            return "micrometre";
            break;
        case Prefix::milli:
            return "millimetre";
            break;
        case Prefix::centi:
            return "centimetre";
            break;
        case Prefix::deci:
            return "decimetre";
            break;
        case Prefix::deca:
            return "decametre";
            break;
        case Prefix::hecto:
            return "hectometre";
            break;
        case Prefix::kilo:
            return "kilometre";
            break;
        case Prefix::mega:
            return "megametre";
            break;
        case Prefix::giga:
            return "gigametre";
            break;
        case Prefix::tera:
            return "terametre";
            break;
        case Prefix::peta:
            return "petametre";
            break;
        case Prefix::exa:
            return "exametre";
            break;
        case Prefix::zetta:
            return "zettametre";
            break;
        case Prefix::yotta:
            return "yottametre";
            break;

        default:
            return "Metre";
            break;
        }
        break;
    case Type::Fermi:
        return "Fermi";
        break;
    case Type::Angstrom:
        return "ångström";
        break;
    case Type::Micron:
        return "Micron";
        break;
    case Type::Myriametre:
        return "Myriametre";
        break;
    case Type::X_Unit:
        return "X unit";
        break;
    case Type::Point:
        return "Point";
        break;
    case Type::Pica:
        return "Pica";
        break;
    case Type::Thou:
        return "Thou";
        break;
    case Type::Inch:
        return "Inch";
        break;
    case Type::Foot:
        return "Foot";
        break;
    case Type::Yard:
        return "Yard";
        break;
    case Type::Chain:
        return "Chain";
        break;
    case Type::Furlong:
        return "Furlong";
        break;
    case Type::Mile:
        return "Mile";
        break;
    case Type::League:
        return "League";
        break;
    case Type::Fathom:
        return "Fathom";
        break;
    case Type::Short_Cable:
        return "Cable (short)";
        break;
    case Type::Long_Cable:
        return "Cable (long)";
        break;
    case Type::Nautical_Mile:
        return "Nautical mile";
        break;
    case Type::Link:
        return "Link";
        break;
    case Type::Survey_Inch:
        return "Survey inch";
        break;
    case Type::Survey_Foot:
        return "Survey foot";
        break;
    case Type::Rod:
        return "Rod";
        break;
    case Type::Survey_Chain:
        return "Survey chain";
        break;
    case Type::Survey_Furlong:
        return "Survey furlong";
        break;
    case Type::Survey_Mile:
        return "Survey mile";
        break;
    case Type::Survey_League:
        return "Survey league";
        break;

    default:
        return "None";
    }
}

std::string Length_Type::getSystemName(Length_Type::Type type){
    switch (type)
    {
    case Type::Metre:
    case Type::Fermi:
    case Type::Angstrom:
    case Type::Micron:
    case Type::Myriametre:
    case Type::X_Unit:
        return "Metric";
        break;
    case Type::Point:
    case Type::Pica:
    case Type::Thou:
    case Type::Inch:
    case Type::Foot:
    case Type::Yard:
    case Type::Chain:
    case Type::Furlong:
    case Type::Mile:
    case Type::League:
    case Type::Fathom:
    case Type::Short_Cable:
    case Type::Long_Cable:
    case Type::Nautical_Mile:
        return "Imperial";
        break;
    case Type::Link:
    case Type::Survey_Inch:
    case Type::Survey_Foot:
    case Type::Rod:
    case Type::Survey_Chain:
    case Type::Survey_Furlong:
    case Type::Survey_Mile:
    case Type::Survey_League:
        return "US Customary";
        break;

    default:
        return "None";
    }
}

std::string Length_Type::getSystemName(Length_Type::System system){
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

std::string Length_Type::getPrefixName(Length_Type::Prefix prefix){
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

Length_Type::System Length_Type::getSystem(Length_Type::Type type){
    switch (type)
    {
    case Type::Metre:
    case Type::Fermi:
    case Type::Angstrom:
    case Type::Micron:
    case Type::Myriametre:
    case Type::X_Unit:
        return System::Metric;
        break;
    case Type::Point:
    case Type::Pica:
    case Type::Thou:
    case Type::Inch:
    case Type::Foot:
    case Type::Yard:
    case Type::Chain:
    case Type::Furlong:
    case Type::Mile:
    case Type::League:
    case Type::Fathom:
    case Type::Short_Cable:
    case Type::Long_Cable:
    case Type::Nautical_Mile:
        return System::Imperial;
        break;
    case Type::Link:
    case Type::Survey_Inch:
    case Type::Survey_Foot:
    case Type::Rod:
    case Type::Survey_Chain:
    case Type::Survey_Furlong:
    case Type::Survey_Mile:
    case Type::Survey_League:
        return System::US_Customary;
        break;

    default:
        return System::None;
    }
}

Length_Type::System Length_Type::getSystemEnum(const std::string& name)
{

    for(const auto& system: systems_){
        if (name == getSystemName(system)){
            return system;
        }
    }
    return System::None;
}

Length_Type::Type Length_Type::getTypeEnum(const std::string& name)
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

Length_Type::Prefix Length_Type::getPrefixEnum(const std::string& name)
{

    for(const auto& prefix: prefixes_){
        if (name == getPrefixName(prefix)){
            return prefix;
        }
    }
    return Prefix::None;
}

};
