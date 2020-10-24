#ifndef __TEMPERATURE_TCC__
#define __TEMPERATURE_TCC__

//Used for development
#ifndef __TEMPERATURE_HPP__
#include "Temperature.hpp"
#endif



// ******** Temperature **********

//*** Public Methods *** 

namespace afzm{
//** -- Constructors -- **
template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature() : system_(Temperature_Type::System::None), 
                                            type_(Temperature_Type::Type::Kelvin), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = 0;
    this->symbol_ = "K";
    this->name_ = "";
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(T_Arithmetic value) : system_(Temperature_Type::System::None), 
                                            type_(Temperature_Type::Type::Kelvin), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = value;
    this->symbol_ = "K";
    this->name_ = "";
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(T_Arithmetic value, Temperature_Type::Type type) : system_(Temperature_Type::System::None), 
                                            type_(type), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = value;
    setSymbol();
    this->name_ = "";
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(T_Arithmetic value, std::string name) : system_(Temperature_Type::System::None), 
                                            type_(Temperature_Type::Type::Kelvin), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = value;
    this->symbol_ = "K";
    this->name_ = name;
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(T_Arithmetic value, Temperature_Type::Type type, std::string name) : system_(Temperature_Type::System::None), 
                                            type_(type), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = value;
    setSymbol();
    this->name_ = name;
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(std::string name) : system_(Temperature_Type::System::None), 
                                            type_(Temperature_Type::Type::Kelvin), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = 0;
    this->symbol_ = "K";
    this->name_ = name;
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(Temperature_Type::Type type, std::string name) : system_(Temperature_Type::System::None), 
                                            type_(type), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = 0;
    setSymbol();
    this->name_ = name;
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::Temperature(Temperature_Type::Type type) : system_(Temperature_Type::System::None), 
                                            type_(type), 
                                            prefix_(Temperature_Type::Prefix::None){
    this->value_ = 0;
    setSymbol();
    this->name_ = "";
}

template<typename T_Arithmetic>
Temperature<T_Arithmetic>::~Temperature(){}


//** -- Setters -- **

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::changeType(std::string type, std::string prefix){
    setType(Temperature_Type::getTypeEnum(type));
    setSymbol();
    prefix = "None";
}

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::changeType(Temperature_Type::Type type){ 
    type_ = type;
    setSymbol();
}


//** -- Getters -- **

template<typename T_Arithmetic>
Temperature_Type::System Temperature<T_Arithmetic>::getSystem() const{ return system_; }

template<typename T_Arithmetic>
Temperature_Type::Type Temperature<T_Arithmetic>::getType() const{ return type_; }

template<typename T_Arithmetic>
Temperature_Type::Prefix Temperature<T_Arithmetic>::getPrefix() const{ return prefix_; }

template<typename T_Arithmetic>
std::string Temperature<T_Arithmetic>::getSystemName() const{ return Temperature_Type::getSystemName(); }

template<typename T_Arithmetic>
std::string Temperature<T_Arithmetic>::getTypeName() const{ return Temperature_Type::getTypeName(this->type_); }

template<typename T_Arithmetic>
std::string Temperature<T_Arithmetic>::getPrefixName() const{ return Temperature_Type::getPrefixName(); }

template<typename T_Arithmetic>
std::string Temperature<T_Arithmetic>::getTypeWPrefixName() const{ return Temperature_Type::getTypeName(this->type_); }


template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit){
    Temperature<T_Arithmetic>* temp = dynamic_cast< Temperature<T_Arithmetic>* >(target);
    switch(data_edit){
    case Conversion_Type::IN_PLACE:
        return convertTo(temp->getType(), true);
        break;
    case Conversion_Type::TARGET:
        target->setValue(convertTo(temp->getType(), false));
        return target->getValue();
        break;
    case Conversion_Type::BOTH:
        target->setValue(convertTo(temp->getType(), true));
        return target->getValue();
        break;

    case Conversion_Type::NONE:
    default:
        return convertTo(temp->getType(), false);
        break;
    }
}


//** -- Interface Convert -- **
template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertTo(Temperature_Type::Type type, bool in_place){
    if (type == Temperature_Type::Type::None){
        std::cerr << "Invalid input" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
    switch (type_)
    {
    case Temperature_Type::Type::Celsius:
        return convertFromC(type, in_place);
        break;
    case Temperature_Type::Type::Kelvin:
        return convertFromK(type, in_place);
        break;
    case Temperature_Type::Type::Fahrenheit:
        return convertFromF(type, in_place);
        break;
    case Temperature_Type::Type::Rankine:
        return convertFromR(type, in_place);
        break;
    case Temperature_Type::Type::Delisle:
        return convertFromDe(type, in_place);
        break;
    case Temperature_Type::Type::Newton:
        return convertFromN(type, in_place);
        break;
    case Temperature_Type::Type::Reaumur:
        return convertFromRe(type, in_place);
        break;
    case Temperature_Type::Type::Romer:
        return convertFromRo(type, in_place);
        break;
    
    default:
        std::cerr << "No Type Set" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

//*** Protected Methods ***

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::setSystem(Temperature_Type::System system){ system_ = system; }

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::setType(Temperature_Type::Type type){ type_ = type;}

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::setPrefix(Temperature_Type::Prefix prefix){ prefix_ = prefix; }

template<typename T_Arithmetic>
void Temperature<T_Arithmetic>::setSymbol(){
    switch (type_)
    {
    case Temperature_Type::Type::Celsius:
        this->symbol_ = "°C";
        break;
    case Temperature_Type::Type::Kelvin:
        this->symbol_ = "K";
        break;
    case Temperature_Type::Type::Fahrenheit:
        this->symbol_ = "°F";
        break;
    case Temperature_Type::Type::Rankine:
        this->symbol_ = "°R";
        break;
    case Temperature_Type::Type::Delisle:
        this->symbol_ = "°De";
        break;
    case Temperature_Type::Type::Newton:
        this->symbol_ = "°N";
        break;
    case Temperature_Type::Type::Reaumur:
        this->symbol_ = "°Ré";
        break;
    case Temperature_Type::Type::Romer:
        this->symbol_ = "°Ro";
        break;
    
    default:
        this->symbol_ = "";
    }
}



// *** PRIVATE METHODS ***

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromC(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) + 273.15);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) + 273.15);
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.8) + 32.0);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.8) + 32.0);
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) + 273.15) * (1.8));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) + 273.15) * (1.8));
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((100.0 - static_cast<double>(this->value_)) * (1.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((100.0 - static_cast<double>(this->value_)) * (1.5));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 0.33);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 0.33);
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 0.8);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 0.8);
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 0.525) + (7.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 0.525) + (7.5));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromK(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) - 273.15);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) - 273.15);
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.8) - 459.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.8) - 459.67);
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 1.8);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 1.8);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((373.15 - static_cast<double>(this->value_)) * (1.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((373.15 - static_cast<double>(this->value_)) * (1.5));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 273.15) * 0.33);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 273.15) * 0.33);
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 273.15) * 0.8);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 273.15) * 0.8);
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 273.15) * 0.525) + (7.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 273.15) * 0.525) + (7.5));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromF(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (5.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (5.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) + 459.67) * (5.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) + 459.67) * (5.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) + 459.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) + 459.67);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((212.0 - static_cast<double>(this->value_)) * (5.0 / 6.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((212.0 - static_cast<double>(this->value_)) * (5.0 / 6.0));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (11.0 / 60.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (11.0 / 60.0));
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (4.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 32.0) * (4.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 32.0) * (7.0 / 24.0)) + (7.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 32.0) * (7.0 / 24.0)) + (7.5));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromR(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (5.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (5.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (5.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (5.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) - 459.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) - 459.67);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((671.67 - static_cast<double>(this->value_)) * (5.0 / 6.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((671.67 - static_cast<double>(this->value_)) * (5.0 / 6.0));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (11.0 / 60.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (11.0 / 60.0));
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (4.0 / 9.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 491.67) * (4.0 / 9.0));
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 491.67) * (7.0 / 24.0)) + (7.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 491.67) * (7.0 / 24.0)) + (7.5));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromDe(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>(100.0 - (static_cast<double>(this->value_) * (2.0 / 3.0)));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(100.0 - (static_cast<double>(this->value_) * (2.0 / 3.0)));
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>(373.15 - (static_cast<double>(this->value_) * (2.0 / 3.0)));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(373.15 - (static_cast<double>(this->value_) * (2.0 / 3.0)));
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>(212.0 - (static_cast<double>(this->value_) * 1.2));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(212.0 - (static_cast<double>(this->value_) * 1.2));
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>(671.67 - (static_cast<double>(this->value_) * 1.2));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(671.67 - (static_cast<double>(this->value_) * 1.2));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>(33.0 - (static_cast<double>(this->value_) * 0.22));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(33.0 - (static_cast<double>(this->value_) * 0.22));
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>(80 - (static_cast<double>(this->value_) * (8.0 / 15.0)));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(80 - (static_cast<double>(this->value_) * (8.0 / 15.0)));
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>(60.0 - (static_cast<double>(this->value_) * 0.35));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((60.0 - static_cast<double>(this->value_)) * 0.35);
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromN(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (100.0 / 33.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (100.0 / 33.0));
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (100.0 / 33.0)) + 273.15);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (100.0 / 33.0)) + 273.15);
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (60.0 / 11.0)) + 32);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (60.0 / 11.0)) + 32);
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (60.0 / 11.0)) + 491.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (60.0 / 11.0)) + 491.67);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((33.0 - static_cast<double>(this->value_)) * (50.0 / 11.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((33.0 - static_cast<double>(this->value_)) * (50.0 / 11.0));
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_)* (80.0 / 33.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_)* (80.0 / 33.0));
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (35.0 / 22.0)) + 7.5);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * (35.0 / 22.0)) + 7.5);
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromRe(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 1.25);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * 1.25);
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.25) + 273.15);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 1.25) + 273.15);
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 2.25) + 32);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 2.25) + 32);
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 2.25) + 491.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) * 2.25) + 491.67);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((80.0 - static_cast<double>(this->value_)) * 1.875);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((80.0 - static_cast<double>(this->value_)) * 1.875);
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (33.0 / 80.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(static_cast<double>(this->value_) * (33.0 / 80.0));
        }
        break;
    case Temperature_Type::Type::Romer:
        if(in_place){
            this->symbol_ = "°Ro";
            setType(Temperature_Type::Type::Romer);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) * (21.0 / 32.0)) + 7.5));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) * (21.0 / 32.0)) + 7.5));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

template<typename T_Arithmetic>
T_Arithmetic Temperature<T_Arithmetic>::convertFromRo(Temperature_Type::Type type, bool in_place){
    switch (type)
    {
    case Temperature_Type::Type::Celsius:
        if(in_place){
            this->symbol_ = "°C";
            setType(Temperature_Type::Type::Celsius);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (40.0 / 21.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (40.0 / 21.0));
        }
        break;
    case Temperature_Type::Type::Kelvin:
        if(in_place){
            this->symbol_ = "K";
            setType(Temperature_Type::Type::Kelvin);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (40.0 / 21.0)) + 273.15);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (40.0 / 21.0)) + 273.15);
        }
        break;
    case Temperature_Type::Type::Fahrenheit:
        if(in_place){
            this->symbol_ = "°F";
            setType(Temperature_Type::Type::Fahrenheit);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (24.0 / 7.0)) + 32);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (24.0 / 7.0)) + 32);
        }
        break;
    case Temperature_Type::Type::Rankine:
        if(in_place){
            this->symbol_ = "°R";
            setType(Temperature_Type::Type::Rankine);
            this->value_ = static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (24.0 / 7.0)) + 491.67);
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>(((static_cast<double>(this->value_) - 7.5) * (24.0 / 7.0)) + 491.67);
        }
        break;
    case Temperature_Type::Type::Delisle:
        if(in_place){
            this->symbol_ = "°De";
            setType(Temperature_Type::Type::Delisle);
            this->value_ = static_cast<T_Arithmetic>((60.0 - static_cast<double>(this->value_)) * (20.0 / 7.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((60.0 - static_cast<double>(this->value_)) * (20.0 / 7.0));
        }
        break;
    case Temperature_Type::Type::Newton:
        if(in_place){
            this->symbol_ = "°N";
            setType(Temperature_Type::Type::Newton);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (22.0 / 35.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (22.0 / 35.0));
        }
        break;
    case Temperature_Type::Type::Reaumur:
        if(in_place){
            this->symbol_ = "°Ré";
            setType(Temperature_Type::Type::Reaumur);
            this->value_ = static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (32.0 / 21.0));
            return this->value_;
        }
        else{
            return static_cast<T_Arithmetic>((static_cast<double>(this->value_) - 7.5) * (32.0 / 21.0));
        }
        break;
    
    default:
        std::cerr << "No conversion performed" << std::flush;
        return static_cast<T_Arithmetic>(0);
    }
}

};

#endif //__TEMPERATURE_TCC__
