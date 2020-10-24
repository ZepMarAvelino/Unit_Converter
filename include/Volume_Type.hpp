#ifndef VOLUME_TYPE_HPP
#define VOLUME_TYPE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace afzm {

/**
 * @brief Volume_Type Struct - Defines all units, prefixes, and measurement systems used by the Volume class
 */
struct Volume_Type{

    //Used for declaring the enum class. Undefined immediately after.
    #define UNIT_SYSTEM_BASE_VALUES None, Metric, Imperial, US_Customary
    #define UNIT_TYPE_BASE_VALUES None
    #define UNIT_PREFIX_BASE_VALUES None
    #define METRIC_TYPES Metre_Cubic, Litre, Fermi_Cubic, Angstrom_Cubic, Micron_Cubic, Myriametre_Cubic, X_Unit_Cubic
    #define IMPERIAL_TYPES Point_Cubic, Pica_Cubic, Thou_Cubic, Inch_Cubic, Foot_Cubic, Yard_Cubic, Chain_Cubic
    #define IMPERIAL_TYPES_PT2 Furlong_Cubic, Mile_Cubic, League_Cubic
    #define IMPERIAL_LIQUID_DRY_TYPES Fluid_Ounce, Gill, Pint, Quart, Gallon, Bushel, Quarter
    #define US_TYPES Survey_Link_Cubic, Survey_Inch_Cubic, Survey_Foot_Cubic, Rod_Cubic, Survey_Chain_Cubic
    #define US_TYPES_PT2 Survey_Furlong_Cubic, Survey_Mile_Cubic, Survey_League_Cubic, Survey_Acre_Foot
    #define US_DRY_TYPES US_Dry_Pint, US_Dry_Quart, US_Dry_Gallon, Peck, US_Bushel, Dry_Barrel
    #define US_LIQUID_TYPES Minim, US_Fluid_Dram, Teaspoon, Tablespoon, US_Fluid_Ounce, US_Shot, US_Gill, US_Cup
    #define US_LIQUID_TYPES_PT2 US_Pint, US_Quart, US_Pottle, US_Gallon, Barrel, Oil_Barrel, Hogshead

    /**
     * @brief Enum Class that holds the measurement systems available for the Volume_Type
     */
    enum class System {UNIT_SYSTEM_BASE_VALUES};

    /**
     * @brief Enum Class that holds the unit types available for the Volume_Type
     */
    enum class Type {UNIT_TYPE_BASE_VALUES, METRIC_TYPES, IMPERIAL_TYPES, IMPERIAL_TYPES_PT2, IMPERIAL_LIQUID_DRY_TYPES,
                     US_TYPES, US_TYPES_PT2, US_DRY_TYPES, US_LIQUID_TYPES, US_LIQUID_TYPES_PT2};
    
    /**
     * @brief Enum Class that holds the prefixes available for the Volume_Type
     */
    enum class Prefix {UNIT_PREFIX_BASE_VALUES, yocto, zepto, atto, femto, pico, nano, micro,
                        milli, centi, deci, deca, hecto, kilo, mega, giga, tera, peta, exa, zetta, yotta};

    #undef UNIT_SYSTEM_BASE_VALUES
    #undef UNIT_TYPE_BASE_VALUES
    #undef UNIT_PREFIX_BASE_VALUES
    #undef METRIC_TYPES
    #undef IMPERIAL_TYPES
    #undef IMPERIAL_TYPES_PT2
    #undef IMPERIAL_LIQUID_DRY_TYPES
    #undef US_TYPES
    #undef US_TYPES_PT2
    #undef US_DRY_TYPES
    #undef US_LIQUID_TYPES
    #undef US_LIQUID_TYPES_PT2

    /**
     * @brief Vector that holds the members of the System enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<System> systems_;

    /**
     * @brief Vector that holds the metric units of the Type enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Type> metric_types_;

    /**
     * @brief Vector that holds the imperial units of the Type enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Type> imperial_types_;

    /**
     * @brief Vector that holds the us customary units of the Type enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Type> us_types_;

    /**
     * @brief Vector that holds the members of the Prefix enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Prefix> prefixes_;


    //Methods

    /**
     * @brief Get the name of the type of unit
     * 
     * @param type Enum Class Type 
     * @param prefix Enum Class Prefix
     * @return std::string 
     */
    static std::string getTypeName(Type type, Prefix prefix = Prefix::None);

    /**
     * @brief Get the name of the measurement system to which the argument belongs to
     * 
     * @param type Enum Class Type
     * @return std::string 
     */
    static std::string getSystemName(Type type);

    /**
     * @brief Get the name of the measurement system
     * 
     * @param system Enum Class System
     * @return std::string 
     */
    static std::string getSystemName(System system);

    /**
     * @brief Get the name of the prefixt
     * 
     * @param prefix Enum Class Prefix
     * @return std::string 
     */
    static std::string getPrefixName(Prefix prefix);

    /**
     * @brief Get the System Enum to which the argument belongs to
     * 
     * @param type Enum Class Type
     * @return System 
     */
    static System getSystem(Type type);

    /**
     * @brief Get the System Enum that matches the string
     * 
     * @param name std::string
     * @return System 
     */
    static System getSystemEnum(const std::string& name);

    /**
     * @brief Get the Type Enum that matches the string
     * 
     * @param name std::string
     * @return Type 
     */
    static Type getTypeEnum(const std::string& name);

    /**
     * @brief Get the Prefix Enum that matches the string
     * 
     * @param name std::string
     * @return Prefix 
     */
    static Prefix getPrefixEnum(const std::string& name);
};


};

#endif // VOLUME_TYPE_HPP
