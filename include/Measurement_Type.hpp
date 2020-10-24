#ifndef MEASUREMENT_TYPE_HPP
#define MEASUREMENT_TYPE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace afzm {

/**
 * @brief Measurement_Type Struct - Defines the types of measurement available to the library
 */
struct Measurement_Type
{

    /**
     * @brief Enum Class that holds the types of measurement available in the library
     */
    enum class Measurement {None, Length, Area, Volume, Mass, Temperature};

    /**
     * @brief Vector that holds the members of the Measurement enum class. Used for iterating through the enum if needed
     */
    static const std::vector<Measurement> measurement_;


    //***********************METHODS****************************

    /**
     * @brief Get the string name of the enum
     * 
     * @param measurement Enum Class Measurement
     * @return std::string 
     */
    static std::string getMeasurementName(Measurement measurement);

    /**
     * @brief Get the Enum that matches the string
     * 
     * @param name std::string
     * @return Measurement 
     */
    static Measurement getMeasurementEnum(const std::string& name);

};

};

#endif // MEASUREMENT_TYPE_HPP
