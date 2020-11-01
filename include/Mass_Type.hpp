#ifndef MASS_TYPE_HPP
#define MASS_TYPE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace afzm{

/**
 * @brief Mass_Type Struct - Defines all units, prefixes, and measurement systems used by the Mass class
 */
struct Mass_Type{

    //For simplicity, Grams will be used as the basic unit of the metric system, rather than Kilograms
    //Used for declaring the enum class. Undefined immediately after.
    #define UNIT_SYSTEM_BASE_VALUES None, Metric, Imperial, US_Customary
    #define UNIT_TYPE_BASE_VALUES None
    #define UNIT_PREFIX_BASE_VALUES None
    #define METRIC_TYPES Gram, Tonne, Carat
    #define IMPERIAL_TYPES Grain, Drachm, Ounce, Pound, Stone, Quarter, Hundredweight, Ton
    #define US_TYPES Dram, US_Hundredweight, US_Ton, Pennyweight, Troy_Ounce, Troy_Pound
    
    /**
     * @brief Enum Class that holds the measurement systems available for the Mass_Type
     */
    enum class System {UNIT_SYSTEM_BASE_VALUES};
    
    /**
     * @brief Enum Class that holds the unit types available for the Mass_Type
     */
    enum class Type {UNIT_TYPE_BASE_VALUES, METRIC_TYPES, IMPERIAL_TYPES, US_TYPES};
    
    /**
     * @brief Enum Class that holds the prefixes available for the Mass_Type
     */
    enum class Prefix {UNIT_PREFIX_BASE_VALUES, yocto, zepto, atto, femto, pico, nano, micro,
                        milli, centi, deci, deca, hecto, kilo, mega, giga, tera, peta, exa, zetta, yotta};

    #undef UNIT_SYSTEM_BASE_VALUES
    #undef UNIT_TYPE_BASE_VALUES
    #undef UNIT_PREFIX_BASE_VALUES
    #undef METRIC_TYPES
    #undef IMPERIAL_TYPES
    #undef US_TYPES

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
     * @brief Vector that holds all the units of the Type enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Type> all_types_;

    /**
     * @brief Vector that holds the members of the Prefix enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Prefix> prefixes_;


    //************Methods********************

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

#endif // MASS_TYPE_HPP
