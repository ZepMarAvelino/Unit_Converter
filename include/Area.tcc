#ifndef __AREA_TCC__
#define __AREA_TCC__

//Used for development
#ifndef __AREA_HPP__
#include "Area.hpp"
#endif

namespace afzm{


template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(){
	this->value_ = 0;
	this->system_ = Area_Type::System::Metric;
	this->type_ = Area_Type::Type::Metre_Square;
	this->prefix_ = Area_Type::Prefix::None;
	this->symbol_ = "m^2";
	this->name_ = "";
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(T_Arithmetic value){
	this->value_ = value;
	this->system_ = Area_Type::System::Metric;
	this->type_ = Area_Type::Type::Metre_Square;
	this->prefix_ = Area_Type::Prefix::None;
	this->symbol_ = "m^2";
	this->name_ = "";
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(T_Arithmetic value, Area_Type::Type type, Area_Type::Prefix prefix){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(T_Arithmetic value, std::string name){
	this->value_ = value;
	this->system_ = Area_Type::System::Metric;
	this->type_ = Area_Type::Type::Metre_Square;
	this->prefix_ = Area_Type::Prefix::None;
	this->symbol_ = "m^2";
	this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(T_Arithmetic value, Area_Type::Type type, std::string name){
	this->value_ = value;
	setType(type);
    this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(T_Arithmetic value, Area_Type::Type type, Area_Type::Prefix prefix, std::string name){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(std::string name){
	this->value_ = 0;
	this->system_ = Area_Type::System::Metric;
	this->type_ = Area_Type::Type::Metre_Square;
	this->prefix_ = Area_Type::Prefix::None;
	this->symbol_ = "m^2";
	this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(Area_Type::Type type, std::string name){
	this->value_ = 0;
	setType(type);
	this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(Area_Type::Type type, Area_Type::Prefix prefix, std::string name){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::Area(Area_Type::Type type, Area_Type::Prefix prefix){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Area<T_Arithmetic>::~Area(){}

template<typename T_Arithmetic>
void Area<T_Arithmetic>::changeType(std::string type, std::string prefix){ setType(Area_Type::getTypeEnum(type), Area_Type::getPrefixEnum(prefix)); }

template<typename T_Arithmetic>
void Area<T_Arithmetic>::changeType(Area_Type::Type type, Area_Type::Prefix prefix){ setType(type, prefix); }


template<typename T_Arithmetic>
Area_Type::System Area<T_Arithmetic>::getSystem() const{ return this->system_; }

template<typename T_Arithmetic>
Area_Type::Type Area<T_Arithmetic>::getType() const{ return this->type_; }

template<typename T_Arithmetic>
Area_Type::Prefix Area<T_Arithmetic>::getPrefix() const{ return this->prefix_; }

template<typename T_Arithmetic>
std::string Area<T_Arithmetic>::getSystemName() const{ return Area_Type::getSystemName(this->system_); }

template<typename T_Arithmetic>
std::string Area<T_Arithmetic>::getTypeName() const{ return Area_Type::getTypeName(this->type_); }

template<typename T_Arithmetic>
std::string Area<T_Arithmetic>::getPrefixName() const{ return Area_Type::getPrefixName(this->prefix_); }

template<typename T_Arithmetic>
std::string Area<T_Arithmetic>::getTypeWPrefixName() const{ return Area_Type::getTypeName(this->type_, this->prefix_); }

template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit){
    Area<T_Arithmetic>* temp = dynamic_cast< Area<T_Arithmetic>* >(target);
    switch(data_edit){
    case Conversion_Type::IN_PLACE:
        return convertTo(temp->getType(), temp->getPrefix(), true);
        break;
    case Conversion_Type::TARGET:
        target->setValue(convertTo(temp->getType(), temp->getPrefix(), false));
        return target->getValue();
        break;
    case Conversion_Type::BOTH:
        target->setValue(convertTo(temp->getType(), temp->getPrefix(), true));
        return target->getValue();
        break;

    case Conversion_Type::NONE:
    default:
        return convertTo(temp->getType(), temp->getPrefix(), false);
        break;
    }
}

template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertTo(Area_Type::Type type, bool in_place){
	switch (Area_Type::getSystem(type))
	{
	case Area_Type::System::Metric:
		return convertToMetric(type, Area_Type::Prefix::None, in_place);
		break;
	case Area_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Area_Type::System::US_Customary:
		return convertToUSCustomary(type, in_place);
		break;
	
	default:
		std::cerr << "Unknown Type";
        return 0;
		break;
	}
}

template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertTo(Area_Type::Type type, Area_Type::Prefix prefix, bool in_place){
	switch (Area_Type::getSystem(type))
	{
	case Area_Type::System::Metric:
		return convertToMetric(type, prefix, in_place);
		break;
	case Area_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Area_Type::System::US_Customary:
		return convertToUSCustomary(type, in_place);
		break;
	
	default:
		std::cerr << "Unknown Type";
		return 0;
		break;
	}
}


// **** Protected ****

template<typename T_Arithmetic>
void Area<T_Arithmetic>::setSystem(Area_Type::System system){ this->system_ = system; }

template<typename T_Arithmetic>
void Area<T_Arithmetic>::setType(Area_Type::Type type, Area_Type::Prefix prefix){
	this->type_ = type;

	if(type == Area_Type::Type::Metre_Square){
		setPrefix(prefix);
	}
	else{
		setPrefix(Area_Type::Prefix::None);
	}

	setSystem(Area_Type::getSystem(type));
	setSymbol();
}

template<typename T_Arithmetic>
void Area<T_Arithmetic>::setPrefix(Area_Type::Prefix prefix){ this->prefix_ = prefix; }

template<typename T_Arithmetic>
void Area<T_Arithmetic>::setSymbol(){
	switch(this->system_){
		case Area_Type::System::Metric:
			switch (this->type_){
				case Area_Type::Type::Metre_Square:
					switch (this->prefix_){
						case Area_Type::Prefix::yocto:
							this->symbol_ = "ym^2";
							break;
						case Area_Type::Prefix::zepto:
							this->symbol_ = "zm^2";
							break;
						case Area_Type::Prefix::atto:
							this->symbol_ = "am^2";
							break;
						case Area_Type::Prefix::femto:
							this->symbol_ = "fm^2";
							break;
						case Area_Type::Prefix::pico:
							this->symbol_ = "pm^2";
							break;
						case Area_Type::Prefix::nano:
							this->symbol_ = "nm^2";
							break;
						case Area_Type::Prefix::micro:
							this->symbol_ = "μm^2";
							break;
						case Area_Type::Prefix::milli:
							this->symbol_ = "mm^2";
							break;
						case Area_Type::Prefix::centi:
							this->symbol_ = "cm^2";
							break;
						case Area_Type::Prefix::deci:
							this->symbol_ = "dm^2";
							break;
						case Area_Type::Prefix::deca:
							this->symbol_ = "dam^2";
							break;
						case Area_Type::Prefix::hecto:
							this->symbol_ = "hm^2";
							break;
						case Area_Type::Prefix::kilo:
							this->symbol_ = "km^2";
							break;
						case Area_Type::Prefix::mega:
							this->symbol_ = "Mm^2";
							break;
						case Area_Type::Prefix::giga:
							this->symbol_ = "Gm^2";
							break;
						case Area_Type::Prefix::tera:
							this->symbol_ = "Tm^2";
							break;
						case Area_Type::Prefix::peta:
							this->symbol_ = "Pm^2";
							break;
						case Area_Type::Prefix::exa:
							this->symbol_ = "Em^2";
							break;
						case Area_Type::Prefix::zetta:
							this->symbol_ = "Zm^2";
							break;
						case Area_Type::Prefix::yotta:
							this->symbol_ = "Ym^2";
							break;
						
						default:
							this->symbol_ = "m^2";
							break;
					}
					break;
				case Area_Type::Type::Fermi_Square:
					this->symbol_ = "fm^2";
					break;
				case Area_Type::Type::Angstrom_Square:
					this->symbol_ = "Å^2";
					break;
				case Area_Type::Type::Micron_Square:
					this->symbol_ = "μm^2";
					break;
				case Area_Type::Type::Myriametre_Square:
                    this->symbol_ = "myriametre^2";
					break;
				case Area_Type::Type::X_Unit_Square:
					this->symbol_ = "xu^2";
					break;
				case Area_Type::Type::Hectare:
					this->symbol_ = "ha";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Area_Type::System::Imperial:
			switch(this->type_){
				case Area_Type::Type::Point_Square:
					this->symbol_ = "p^2";
					break;
				case Area_Type::Type::Pica_Square:
					this->symbol_ = "pc^2";
					break;
				case Area_Type::Type::Thou_Square:
					this->symbol_ = "th^2";
					break;
				case Area_Type::Type::Inch_Square:
					this->symbol_ = "in^2";
					break;
				case Area_Type::Type::Foot_Square:
					this->symbol_ = "ft^2";
					break;
				case Area_Type::Type::Yard_Square:
					this->symbol_ = "yd^2";
					break;
				case Area_Type::Type::Chain_Square:
					this->symbol_ = "ch^2";
					break;
				case Area_Type::Type::Furlong_Square:
					this->symbol_ = "fur^2";
					break;
				case Area_Type::Type::Mile_Square:
					this->symbol_ = "mi^2";
					break;
				case Area_Type::Type::League_Square:
					this->symbol_ = "lea^2";
					break;
				case Area_Type::Type::Rood:
					this->symbol_ = "ro";
					break;
				case Area_Type::Type::Acre:
					this->symbol_ = "ac";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Area_Type::System::US_Customary:
			switch(this->type_){
				case Area_Type::Type::Survey_Link_Square:
					this->symbol_ = "li^2";
					break;
				case Area_Type::Type::Survey_Inch_Square:
					this->symbol_ = "in^2";
					break;
				case Area_Type::Type::Survey_Foot_Square:
					this->symbol_ = "ft^2";
					break;
				case Area_Type::Type::Rod_Square:
					this->symbol_ = "rd^2";
					break;
				case Area_Type::Type::Survey_Chain_Square:
					this->symbol_ = "ch^2";
					break;
				case Area_Type::Type::Survey_Furlong_Square:
					this->symbol_ = "fur^2";
					break;
				case Area_Type::Type::Section:
					this->symbol_ = "mi^2";
					break;
				case Area_Type::Type::Survey_League_Square:
					this->symbol_ = "lea^2";
					break;
				case Area_Type::Type::Survey_Township:
					this->symbol_ = "twp";
					break;

				default:
					this->symbol_ = "";
					break;
			}
			break;
		default:
			this->symbol_ = "";
			break;
		}
}


template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertToMetric(Area_Type::Type type, Area_Type::Prefix prefix, bool in_place){

	//Obtains the current value converted to Square Metres
	double temp_value = convertToBasicUnit(Area_Type::System::Metric);
	
	//Converts Square Metre to the appropriate Metric value
	switch (type){
		case Area_Type::Type::Metre_Square:
			switch (prefix){
				case Area_Type::Prefix::yocto:
					temp_value *= 1e48;
					break;
				case Area_Type::Prefix::zepto:
					temp_value *= 1e42;
					break;
				case Area_Type::Prefix::atto:
					temp_value *= 1e36;
					break;
				case Area_Type::Prefix::femto:
					temp_value *= 1e30;
					break;
				case Area_Type::Prefix::pico:
					temp_value *= 1e24;
					break;
				case Area_Type::Prefix::nano:
					temp_value *= 1e18;
					break;
				case Area_Type::Prefix::micro:
					temp_value *= 1e12;
					break;
				case Area_Type::Prefix::milli:
					temp_value *= 1e6;
					break;
				case Area_Type::Prefix::centi:
					temp_value *= 1e4;
					break;
				case Area_Type::Prefix::deci:
					temp_value *= 1e2;
					break;
				case Area_Type::Prefix::deca:
					temp_value *= 1e-2;
					break;
				case Area_Type::Prefix::hecto:
					temp_value *= 1e-4;
					break;
				case Area_Type::Prefix::kilo:
					temp_value *= 1e-6;
					break;
				case Area_Type::Prefix::mega:
					temp_value *= 1e-12;
					break;
				case Area_Type::Prefix::giga:
					temp_value *= 1e-18;
					break;
				case Area_Type::Prefix::tera:
					temp_value *= 1e-24;
					break;
				case Area_Type::Prefix::peta:
					temp_value *= 1e-30;
					break;
				case Area_Type::Prefix::exa:
					temp_value *= 1e-36;
					break;
				case Area_Type::Prefix::zetta:
					temp_value *= 1e-42;
					break;
				case Area_Type::Prefix::yotta:
					temp_value *= 1e-48;
					break;
				
				default:
					break;
			}
			break;
		case Area_Type::Type::Fermi_Square:
			temp_value *= 1e30;
			prefix = Area_Type::Prefix::None;
			break;
		case Area_Type::Type::Angstrom_Square:
			temp_value *= 1e20;
			prefix = Area_Type::Prefix::None;
			break;
		case Area_Type::Type::Micron_Square:
			temp_value *= 1e12;
			prefix = Area_Type::Prefix::None;
			break;
		case Area_Type::Type::Myriametre_Square:
			temp_value *= 1e-8;
			prefix = Area_Type::Prefix::None;
			break;
		case Area_Type::Type::X_Unit_Square:
			temp_value *= 1e26;
			prefix = Area_Type::Prefix::None;
			break;
		case Area_Type::Type::Hectare:
			temp_value *= 1e-4;
			prefix = Area_Type::Prefix::None;
			break;
		default:
			prefix = Area_Type::Prefix::None;
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Area_Type::System::Metric;
		this->type_ = type;
		this->prefix_ = prefix;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertToImperial(Area_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Square Feet
	double temp_value = convertToBasicUnit(Area_Type::System::Imperial);

	//Converts Square Feet to the appropriate Imperial value
	switch(type){
		case Area_Type::Type::Point_Square:
			temp_value *= 746496.0;
			break;
		case Area_Type::Type::Pica_Square:
			temp_value *= 5184.0;
			break;
		case Area_Type::Type::Thou_Square:
			temp_value *= 144000000.0;
			break;
		case Area_Type::Type::Inch_Square:
			temp_value *= 144.0;
			break;
		case Area_Type::Type::Yard_Square:
			temp_value /= 9.0;
			break;
		case Area_Type::Type::Chain_Square:
			temp_value /= 4356.0;
			break;
		case Area_Type::Type::Furlong_Square:
			temp_value /= 435600.0;
			break;
		case Area_Type::Type::Mile_Square:
			temp_value /= 27878400.0;
			break;
		case Area_Type::Type::League_Square:
			temp_value /= 250905600.0;
			break;
		case Area_Type::Type::Rood:
			temp_value /= 10890.0;
			break;
		case Area_Type::Type::Acre:
			temp_value /= 43560.0;
			break;
		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Area_Type::System::Imperial;
		this->type_ = type;
		this->prefix_ = Area_Type::Prefix::None;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Area<T_Arithmetic>::convertToUSCustomary(Area_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Square Survey Feet
	double temp_value = convertToBasicUnit(Area_Type::System::US_Customary);

	//Converts Square Survey Feet to the appropriate US Customary value
	switch(type){
		case Area_Type::Type::Survey_Link_Square:
			temp_value /= (1089.0 / 2500.0);
			break;
		case Area_Type::Type::Survey_Inch_Square:
			temp_value *= 144.0;
			break;
		case Area_Type::Type::Rod_Square:
			temp_value /= 272.25;
			break;
		case Area_Type::Type::Survey_Chain_Square:
			temp_value /= 4356.0;
			break;
		case Area_Type::Type::Survey_Furlong_Square:
			temp_value /= 435600;
			break;
		case Area_Type::Type::Section:
			temp_value /= 27878400.0;
			break;
		case Area_Type::Type::Survey_League_Square:
			temp_value /= 250905600.0;
			break;
		case Area_Type::Type::Survey_Acre:
			temp_value /= 43560.0;
			break;
		case Area_Type::Type::Survey_Township:
			temp_value /= 1003622400.0;
			break;

		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Area_Type::System::US_Customary;
		this->type_ = type;
		this->prefix_ = Area_Type::Prefix::None;
		setSymbol();
	}

	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
double Area<T_Arithmetic>::convertToBasicUnit(Area_Type::System system){

	double temp_value = static_cast<double>(this->value_);

	//Convert to the basic unit of each system
	switch(this->system_){
		//Converts all metric units to Square Metre
		case Area_Type::System::Metric:
			switch (this->type_){
				case Area_Type::Type::Metre_Square:
					switch (this->prefix_){
						case Area_Type::Prefix::yocto:
							temp_value *= 1e-48;
							break;
						case Area_Type::Prefix::zepto:
							temp_value *= 1e-42;
							break;
						case Area_Type::Prefix::atto:
							temp_value *= 1e-36;
							break;
						case Area_Type::Prefix::femto:
							temp_value *= 1e-30;
							break;
						case Area_Type::Prefix::pico:
							temp_value *= 1e-24;
							break;
						case Area_Type::Prefix::nano:
							temp_value *= 1e-18;
							break;
						case Area_Type::Prefix::micro:
							temp_value *= 1e-12;
							break;
						case Area_Type::Prefix::milli:
							temp_value *= 1e-6;
							break;
						case Area_Type::Prefix::centi:
							temp_value *= 1e-4;
							break;
						case Area_Type::Prefix::deci:
							temp_value *= 1e-2;
							break;
						case Area_Type::Prefix::deca:
							temp_value *= 1e2;
							break;
						case Area_Type::Prefix::hecto:
							temp_value *= 1e4;
							break;
						case Area_Type::Prefix::kilo:
							temp_value *= 1e6;
							break;
						case Area_Type::Prefix::mega:
							temp_value *= 1e12;
							break;
						case Area_Type::Prefix::giga:
							temp_value *= 1e18;
							break;
						case Area_Type::Prefix::tera:
							temp_value *= 1e24;
							break;
						case Area_Type::Prefix::peta:
							temp_value *= 1e30;
							break;
						case Area_Type::Prefix::exa:
							temp_value *= 1e36;
							break;
						case Area_Type::Prefix::zetta:
							temp_value *= 1e42;
							break;
						case Area_Type::Prefix::yotta:
							temp_value *= 1e48;
							break;
						default:
							break;
					}
					break;
				case Area_Type::Type::Fermi_Square:
					temp_value *= 1e-30;
					break;
				case Area_Type::Type::Angstrom_Square:
					temp_value *= 1e-20;
					break;
				case Area_Type::Type::Micron_Square:
					temp_value *= 1e-12;
					break;
				case Area_Type::Type::Myriametre_Square:
					temp_value *= 1e8;
					break;
				case Area_Type::Type::X_Unit_Square:
					temp_value *= 1e-26;
					break;
				case Area_Type::Type::Hectare:
					temp_value *= 1e4;
					break;
				default:
					break;
			}
			break;
		//Converts all Imperial units to Square Feet
		case Area_Type::System::Imperial:
			switch(this->type_){
				case Area_Type::Type::Point_Square:
					temp_value /= 746496.0;
					break;
				case Area_Type::Type::Pica_Square:
					temp_value /= 5184.0;
					break;
				case Area_Type::Type::Thou_Square:
					temp_value /= 144000000.0;
					break;
				case Area_Type::Type::Inch_Square:
					temp_value /= 144.0;
					break;
				case Area_Type::Type::Yard_Square:
					temp_value *= 9.0;
					break;
				case Area_Type::Type::Chain_Square:
					temp_value *= 4356.0;
					break;
				case Area_Type::Type::Furlong_Square:
					temp_value *= 435600.0;
					break;
				case Area_Type::Type::Mile_Square:
					temp_value *= 27878400.0;
					break;
				case Area_Type::Type::League_Square:
					temp_value *= 250905600.0;
					break;
				case Area_Type::Type::Rood:
					temp_value *= 10890.0;
					break;
				case Area_Type::Type::Acre:
					temp_value *= 43560.0;
					break;
				default:
					break;
			}
			break;
		//Converts all US_Customary units to Square Survey Feet
		case Area_Type::System::US_Customary:
			switch(this->type_){
				case Area_Type::Type::Survey_Link_Square:
					temp_value *= (1089.0 / 3025.0);
					break;
				case Area_Type::Type::Survey_Inch_Square:
					temp_value /= 144.0;
					break;
				case Area_Type::Type::Rod_Square:
					temp_value *= 272.25;
					break;
				case Area_Type::Type::Survey_Chain_Square:
					temp_value *= 4356.0;
					break;
				case Area_Type::Type::Survey_Furlong_Square:
					temp_value *= 435600;
					break;
				case Area_Type::Type::Section:
					temp_value *= 27878400.0;
					break;
				case Area_Type::Type::Survey_League_Square:
					temp_value *= 250905600.0;
					break;
				case Area_Type::Type::Survey_Acre:
					temp_value *= 43560.0;
					break;
				case Area_Type::Type::Survey_Township:
					temp_value *= 1003622400.0;
					break;
				default:
					break;
			}
			break;
		default:
			std::cerr << "Unknown Type";
			break;
		}

	//Once they are converted to their basic unit, we do cross system conversion
	//Can be done in the previous switch, but for readability we will accept the minor overhead.
	switch(this->system_){
		case Area_Type::System::Metric:
			if(system == Area_Type::System::Imperial){
				//Convert square metres to square feet
				temp_value /= 0.09290304;
			}
			else if(system == Area_Type::System::US_Customary){
				//Convert square metres to square survey feet
				temp_value /= 0.092906697636;
			}
			break;
		case Area_Type::System::Imperial:
			if(system == Area_Type::System::Metric){
				//Convert square feet to square metres
				temp_value *= 0.09290304;
			}
			else if(system == Area_Type::System::US_Customary){
				//Convert square feet to square survey feet
				temp_value *= 0.999996;
			}
            break;
		case Area_Type::System::US_Customary:
			if(system == Area_Type::System::Metric){
				//Convert square survey feet to square metres
				temp_value *= 0.092906697636;
			}
			else if(system == Area_Type::System::Imperial){
				//Convert Survey feet to feet
				temp_value /= 0.999996;
			}
			break;
		default:
			std::cerr << "Unknown System";
			break;
	}

	return temp_value;
}

};

#endif //__AREA_TCC__
