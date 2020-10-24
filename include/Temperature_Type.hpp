#ifndef TEMPERATURE_TYPE_HPP
#define TEMPERATURE_TYPE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace afzm{

/**
 * @brief Temperature_Type Struct - Defines all units, prefixes, and measurement systems used by the Temperature class
 */
struct Temperature_Type{

    /**
     * @brief Enum Class that exists for compatibility with the other types of measurement
     */
    enum class System {None};
    /**
     * @brief Enum Class that holds the unit types available for the Temperature_Type
     */
    enum class Type {None, Celsius, Kelvin, Fahrenheit, Rankine, Delisle, Newton, Reaumur, Romer};
    /**
     * @brief Enum Class that exists for compatibility with the other types of measurement
     */
    enum class Prefix {None};

    /**
     * @brief Vector that holds the members of the System enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<System> systems_;
    /**
     * @brief Vector that holds the units of the Type enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Type> types_;
    /**
     * @brief Vector that holds the members of the Prefix enum class. Used for iterating through the enum if needed.
     */
    static const std::vector<Prefix> prefixes_;


    //************Methods********************

    /**
     * @brief Get the name of the type of unit
     * 
     * @param type Enum Class Type 
     * @return std::string 
     */
    static std::string getTypeName(Type type);

    /**
     * @brief Get the name of the measurement system. Used for compatibility with other types of measurement
     * 
     * @return std::string 
     */
    static std::string getSystemName();

    /**
     * @brief Get the name of the prefix. Used for compatibility with other types of measurement
     * 
     * @return std::string 
     */
    static std::string getPrefixName();

    /**
     * @brief Get the System Enum. Used for compatibility with other types of measurement
     * 
     * @return System 
     */
    static System getSystem();

    /**
     * @brief Get the System Enum. Used for compatibility with other types of measurement
     * 
     * @return System 
     */
    static System getSystemEnum();

    /**
     * @brief Get the Type Enum that matches the string
     * 
     * @param name std::string
     * @return Type 
     */
    static Type getTypeEnum(const std::string& name);

    /**
     * @brief Get the Prefix Enum. Used for compatibility with other types of measurement
     * 
     * @return System 
     */
    static Prefix getPrefixEnum();
};


};

#endif // TEMPERATURE_TYPE_HPP
