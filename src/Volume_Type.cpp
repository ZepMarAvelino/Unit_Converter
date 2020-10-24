#include "Volume_Type.hpp"

namespace afzm{

const std::vector<Volume_Type::System> Volume_Type::systems_ = {System::None, System::Metric, System::Imperial, System::US_Customary};
const std::vector<Volume_Type::Type> Volume_Type::metric_types_ = {Type::Metre_Cubic, Type::Litre, Type::Fermi_Cubic, Type::Angstrom_Cubic, Type::Micron_Cubic,
                                   Type::Myriametre_Cubic, Type::X_Unit_Cubic};
const std::vector<Volume_Type::Type> Volume_Type::imperial_types_ = {Type::Point_Cubic, Type::Pica_Cubic, Type::Thou_Cubic, Type::Inch_Cubic,
                                     Type::Foot_Cubic, Type::Yard_Cubic, Type::Chain_Cubic, Type::Furlong_Cubic,
                                     Type::Mile_Cubic, Type::League_Cubic, Type::Fluid_Ounce, Type::Gill,
                                     Type::Pint, Type::Quart, Type::Gallon, Type::Bushel, Type::Quarter};
const std::vector<Volume_Type::Type> Volume_Type::us_types_ = {Type::Survey_Link_Cubic, Type::Survey_Inch_Cubic, Type::Survey_Foot_Cubic, Type::Rod_Cubic,
                               Type::Survey_Chain_Cubic, Type::Survey_Furlong_Cubic, Type::Survey_Mile_Cubic, Type::Survey_League_Cubic,
                               Type::Survey_Acre_Foot, Type::US_Dry_Pint, Type::US_Dry_Quart, Type::US_Dry_Gallon, Type::Peck,
                               Type::US_Bushel, Type::Dry_Barrel, Type::Minim, Type::US_Fluid_Dram, Type::Teaspoon, Type::Tablespoon,
                               Type::Fluid_Ounce, Type::US_Shot, Type::US_Gill, Type::US_Cup, Type::US_Pint, Type::US_Quart, Type::US_Pottle,
                               Type::US_Gallon, Type::Barrel, Type::Oil_Barrel, Type::Hogshead};
const std::vector<Volume_Type::Prefix> Volume_Type::prefixes_ = {Prefix::None, Prefix::yocto, Prefix::zepto, Prefix::atto, Prefix::femto, Prefix::pico, Prefix::nano,
                                 Prefix::micro, Prefix::milli, Prefix::centi, Prefix::deci, Prefix::deca, Prefix::hecto, Prefix::kilo,
                                                           Prefix::mega, Prefix::giga, Prefix::tera, Prefix::peta, Prefix::exa, Prefix::zetta, Prefix::yotta};

std::string Volume_Type::getTypeName(Volume_Type::Type type, Volume_Type::Prefix prefix){
    switch (type)
    {
    case Type::Metre_Cubic:
        switch (prefix)
        {
        case Prefix::yocto:
            return "Cubic yoctometre";
            break;
        case Prefix::zepto:
            return "Cubic zeptometre";
            break;
        case Prefix::atto:
            return "Cubic attometre";
            break;
        case Prefix::femto:
            return "Cubic femtometre";
            break;
        case Prefix::pico:
            return "Cubic picometre";
            break;
        case Prefix::nano:
            return "Cubic nanometre";
            break;
        case Prefix::micro:
            return "Cubic micrometre";
            break;
        case Prefix::milli:
            return "Cubic millimetre";
            break;
        case Prefix::centi:
            return "Cubic centimetre";
            break;
        case Prefix::deci:
            return "Cubic decimetre";
            break;
        case Prefix::deca:
            return "Cubic decametre";
            break;
        case Prefix::hecto:
            return "Cubic hectometre";
            break;
        case Prefix::kilo:
            return "Cubic kilometre";
            break;
        case Prefix::mega:
            return "Cubic megametre";
            break;
        case Prefix::giga:
            return "Cubic gigametre";
            break;
        case Prefix::tera:
            return "Cubic terametre";
            break;
        case Prefix::peta:
            return "Cubic petametre";
            break;
        case Prefix::exa:
            return "Cubic exametre";
            break;
        case Prefix::zetta:
            return "Cubic zettametre";
            break;
        case Prefix::yotta:
            return "Cubic yottametre";
            break;

        default:
            return "Cubic metre";
            break;
        }
        break;
    case Type::Litre:
        switch(prefix)
        {
        case Prefix::yocto:
            return "yoctolitre";
            break;
        case Prefix::zepto:
            return "zeptolitre";
            break;
        case Prefix::atto:
            return "attolitre";
            break;
        case Prefix::femto:
            return "femtolitre";
            break;
        case Prefix::pico:
            return "picolitre";
            break;
        case Prefix::nano:
            return "nanolitre";
            break;
        case Prefix::micro:
            return "microlitre";
            break;
        case Prefix::milli:
            return "millilitre";
            break;
        case Prefix::centi:
            return "centilitre";
            break;
        case Prefix::deci:
            return "decilitre";
            break;
        case Prefix::deca:
            return "decalitre";
            break;
        case Prefix::hecto:
            return "hectolitre";
            break;
        case Prefix::kilo:
            return "kilolitre";
            break;
        case Prefix::mega:
            return "megalitre";
            break;
        case Prefix::giga:
            return "gigalitre";
            break;
        case Prefix::tera:
            return "teralitre";
            break;
        case Prefix::peta:
            return "petalitre";
            break;
        case Prefix::exa:
            return "exalitre";
            break;
        case Prefix::zetta:
            return "zettalitre";
            break;
        case Prefix::yotta:
            return "yottalitre";
            break;

        default:
            return "Litre";
            break;
        }
        break;
    case Type::Fermi_Cubic:
        return "Cubic fermi";
        break;
    case Type::Angstrom_Cubic:
        return "Cubic ångström";
        break;
    case Type::Micron_Cubic:
        return "Cubic micron";
        break;
    case Type::Myriametre_Cubic:
        return "Cubic myriametre";
        break;
    case Type::X_Unit_Cubic:
        return "Cubic x unit";
        break;
    case Type::Point_Cubic:
        return "Cubic point";
        break;
    case Type::Pica_Cubic:
        return "Cubic pica";
        break;
    case Type::Thou_Cubic:
        return "Cubic thou";
        break;
    case Type::Inch_Cubic:
        return "Cubic inch";
        break;
    case Type::Foot_Cubic:
        return "Cubic foot";
        break;
    case Type::Yard_Cubic:
        return "Cubic yard";
        break;
    case Type::Chain_Cubic:
        return "Cubic chain (short)";
        break;
    case Type::Furlong_Cubic:
        return "Cubic furlong";
        break;
    case Type::Mile_Cubic:
        return "Cubic mile";
        break;
    case Type::League_Cubic:
        return "Cubic league";
        break;
    case Type::Fluid_Ounce:
        return "Fluid ounce";
        break;
    case Type::Gill:
        return "Gill";
        break;
    case Type::Pint:
        return "Pint";
        break;
    case Type::Quart:
        return "Quart";
        break;
    case Type::Gallon:
        return "Gallon";
        break;
    case Type::Bushel:
        return "Bushel";
        break;
    case Type::Quarter:
        return "Quarter";
        break;
    case Type::Survey_Link_Cubic:
        return "Cubic survey link";
        break;
    case Type::Survey_Foot_Cubic:
        return "Cubic survey foot";
        break;
    case Type::Rod_Cubic:
        return "Cubic rod";
        break;
    case Type::Survey_Chain_Cubic:
        return "Cubic survey chain";
        break;
    case Type::Survey_Furlong_Cubic:
        return "Cubic survey furlong";
        break;
    case Type::Survey_Mile_Cubic:
        return "Cubic survey mile";
        break;
    case Type::Survey_League_Cubic:
        return "Cubic survey league";
        break;
    case Type::Survey_Acre_Foot:
        return "Cubic survey league";
        break;
    case Type::US_Dry_Pint:
        return "Dry pint (US)";
        break;
    case Type::US_Dry_Quart:
        return "Dry quart (US)";
        break;
    case Type::US_Dry_Gallon:
        return "Dry gallon (US)";
        break;
    case Type::Peck:
        return "Peck";
        break;
    case Type::US_Bushel:
        return "Bushel (US)";
        break;
    case Type::Dry_Barrel:
        return "Dry barrel";
        break;
    case Type::Minim:
        return "Minim";
        break;
    case Type::US_Fluid_Dram:
        return "Fluid dram (US)";
        break;
    case Type::Teaspoon:
        return "Teaspoon";
        break;
    case Type::Tablespoon:
        return "Tablespoon";
        break;
    case Type::US_Fluid_Ounce:
        return "Fluid ounce (US)";
        break;
    case Type::US_Shot:
        return "Shot";
        break;
    case Type::US_Gill:
        return "Gill (US)";
        break;
    case Type::US_Cup:
        return "Cup";
        break;
    case Type::US_Pint:
        return "Pint (US)";
        break;
    case Type::US_Quart:
        return "Quart (US)";
        break;
    case Type::US_Pottle:
        return "Pottle";
        break;
    case Type::US_Gallon:
        return "Gallon (US)";
        break;
    case Type::Barrel:
        return "Barrel";
        break;
    case Type::Oil_Barrel:
        return "Oil barrel";
        break;
    case Type::Hogshead:
        return "Hogshead";
        break;

    default:
        return "None";
    }
}

std::string Volume_Type::getSystemName(Volume_Type::Type type){
    switch (type)
    {
    case Type::Metre_Cubic:
    case Type::Litre:
    case Type::Fermi_Cubic:
    case Type::Angstrom_Cubic:
    case Type::Micron_Cubic:
    case Type::Myriametre_Cubic:
    case Type::X_Unit_Cubic:
        return "Metric";
        break;
    case Type::Point_Cubic:
    case Type::Pica_Cubic:
    case Type::Thou_Cubic:
    case Type::Inch_Cubic:
    case Type::Foot_Cubic:
    case Type::Yard_Cubic:
    case Type::Chain_Cubic:
    case Type::Furlong_Cubic:
    case Type::Mile_Cubic:
    case Type::League_Cubic:
    case Type::Fluid_Ounce:
    case Type::Gill:
    case Type::Pint:
    case Type::Quart:
    case Type::Gallon:
    case Type::Bushel:
    case Type::Quarter:
        return "Imperial";
        break;
    case Type::Survey_Link_Cubic:
    case Type::Survey_Inch_Cubic:
    case Type::Survey_Foot_Cubic:
    case Type::Rod_Cubic:
    case Type::Survey_Chain_Cubic:
    case Type::Survey_Furlong_Cubic:
    case Type::Survey_Mile_Cubic:
    case Type::Survey_League_Cubic:
    case Type::Survey_Acre_Foot:
    case Type::US_Dry_Pint:
    case Type::US_Dry_Quart:
    case Type::US_Dry_Gallon:
    case Type::Peck:
    case Type::US_Bushel:
    case Type::Dry_Barrel:
    case Type::Minim:
    case Type::US_Fluid_Dram:
    case Type::Teaspoon:
    case Type::Tablespoon:
    case Type::US_Fluid_Ounce:
    case Type::US_Shot:
    case Type::US_Gill:
    case Type::US_Cup:
    case Type::US_Pint:
    case Type::US_Quart:
    case Type::US_Pottle:
    case Type::US_Gallon:
    case Type::Barrel:
    case Type::Oil_Barrel:
    case Type::Hogshead:
        return "US Customary";
        break;

    default:
        return "None";
    }
}

std::string Volume_Type::getSystemName(Volume_Type::System system){
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

std::string Volume_Type::getPrefixName(Volume_Type::Prefix prefix){
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

Volume_Type::System Volume_Type::getSystem(Volume_Type::Type type){
    switch (type)
    {
    case Type::Metre_Cubic:
    case Type::Litre:
    case Type::Fermi_Cubic:
    case Type::Angstrom_Cubic:
    case Type::Micron_Cubic:
    case Type::Myriametre_Cubic:
    case Type::X_Unit_Cubic:
        return System::Metric;
        break;
    case Type::Point_Cubic:
    case Type::Pica_Cubic:
    case Type::Thou_Cubic:
    case Type::Inch_Cubic:
    case Type::Foot_Cubic:
    case Type::Yard_Cubic:
    case Type::Chain_Cubic:
    case Type::Furlong_Cubic:
    case Type::Mile_Cubic:
    case Type::League_Cubic:
    case Type::Fluid_Ounce:
    case Type::Gill:
    case Type::Pint:
    case Type::Quart:
    case Type::Gallon:
    case Type::Bushel:
    case Type::Quarter:
        return System::Imperial;
        break;
    case Type::Survey_Link_Cubic:
    case Type::Survey_Inch_Cubic:
    case Type::Survey_Foot_Cubic:
    case Type::Rod_Cubic:
    case Type::Survey_Chain_Cubic:
    case Type::Survey_Furlong_Cubic:
    case Type::Survey_Mile_Cubic:
    case Type::Survey_League_Cubic:
    case Type::Survey_Acre_Foot:
    case Type::US_Dry_Pint:
    case Type::US_Dry_Quart:
    case Type::US_Dry_Gallon:
    case Type::Peck:
    case Type::US_Bushel:
    case Type::Dry_Barrel:
    case Type::Minim:
    case Type::US_Fluid_Dram:
    case Type::Teaspoon:
    case Type::Tablespoon:
    case Type::US_Fluid_Ounce:
    case Type::US_Shot:
    case Type::US_Gill:
    case Type::US_Cup:
    case Type::US_Pint:
    case Type::US_Quart:
    case Type::US_Pottle:
    case Type::US_Gallon:
    case Type::Barrel:
    case Type::Oil_Barrel:
    case Type::Hogshead:
        return System::US_Customary;
        break;

    default:
        return System::None;
    }
}

Volume_Type::System Volume_Type::getSystemEnum(const std::string& name)
{
    for(const auto& system: systems_){
        if (name == getSystemName(system)){
            return system;
        }
    }
    return System::None;
}

Volume_Type::Type Volume_Type::getTypeEnum(const std::string& name)
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

Volume_Type::Prefix Volume_Type::getPrefixEnum(const std::string& name)
{
    for(const auto& prefix: prefixes_){
        if (name == getPrefixName(prefix)){
            return prefix;
        }
    }
    return Prefix::None;
}

};
