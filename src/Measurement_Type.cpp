#include "Measurement_Type.hpp"

namespace afzm {

const std::vector<Measurement_Type::Measurement> Measurement_Type::measurement_ {Measurement::None, Measurement::Length, Measurement::Area,
                                                                                 Measurement::Volume, Measurement::Mass, Measurement::Temperature};

std::string Measurement_Type::getMeasurementName(Measurement_Type::Measurement measurement)
{
    switch (measurement) {
    case Measurement::Length:
        return "Length";
        break;
    case Measurement::Area:
        return "Area";
        break;
    case Measurement::Volume:
        return "Volume";
        break;
    case Measurement::Mass:
        return "Mass";
        break;
    case Measurement::Temperature:
        return "Temperature";
        break;
    default:
        return "";
        break;
    }
}

Measurement_Type::Measurement Measurement_Type::getMeasurementEnum(const std::string& name)
{

    for(const auto& measurement: measurement_){
        if (name == getMeasurementName(measurement)){
            return measurement;
        }
    }
    return Measurement::None;
}

};
