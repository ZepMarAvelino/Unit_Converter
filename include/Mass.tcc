#ifndef __MASS_TCC__
#define __MASS_TCC__

//Used for development
#ifndef __MASS_HPP__
#include "Mass.hpp"
#endif


namespace afzm{


template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(){
	this->value_ = 0;
	this->system_ = Mass_Type::System::Metric;
	this->type_ = Mass_Type::Type::Gram;
	this->prefix_ = Mass_Type::Prefix::kilo;
	this->symbol_ = "kg";
	this->name_ = "";
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(T_Arithmetic value){
	this->value_ = value;
	this->system_ = Mass_Type::System::Metric;
	this->type_ = Mass_Type::Type::Gram;
	this->prefix_ = Mass_Type::Prefix::kilo;
	this->symbol_ = "kg";
	this->name_ = "";
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(T_Arithmetic value, Mass_Type::Type type, Mass_Type::Prefix prefix){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(T_Arithmetic value, std::string name){
	this->value_ = value;
	this->system_ = Mass_Type::System::Metric;
	this->type_ = Mass_Type::Type::Gram;
	this->prefix_ = Mass_Type::Prefix::kilo;
	this->symbol_ = "kg";
	this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(T_Arithmetic value, Mass_Type::Type type, std::string name){
	this->value_ = value;
	setType(type);
    this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(T_Arithmetic value, Mass_Type::Type type, Mass_Type::Prefix prefix, std::string name){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(std::string name){
	this->value_ = 0;
	this->system_ = Mass_Type::System::Metric;
	this->type_ = Mass_Type::Type::Gram;
	this->prefix_ = Mass_Type::Prefix::kilo;
	this->symbol_ = "kg";
	this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(Mass_Type::Type type, std::string name){
	this->value_ = 0;
	setType(type);
	this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(Mass_Type::Type type, Mass_Type::Prefix prefix, std::string name){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::Mass(Mass_Type::Type type, Mass_Type::Prefix prefix){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Mass<T_Arithmetic>::~Mass(){}


template<typename T_Arithmetic>
void Mass<T_Arithmetic>::changeType(std::string type, std::string prefix){ setType(Mass_Type::getTypeEnum(type), Mass_Type::getPrefixEnum(prefix)); }

template<typename T_Arithmetic>
void Mass<T_Arithmetic>::changeType(Mass_Type::Type type, Mass_Type::Prefix prefix){ setType(type, prefix); }


template<typename T_Arithmetic>
Mass_Type::System Mass<T_Arithmetic>::getSystem() const{ return this->system_; }

template<typename T_Arithmetic>
Mass_Type::Type Mass<T_Arithmetic>::getType() const{ return this->type_; }

template<typename T_Arithmetic>
Mass_Type::Prefix Mass<T_Arithmetic>::getPrefix() const{ return this->prefix_; }

template<typename T_Arithmetic>
std::string Mass<T_Arithmetic>::getSystemName() const{ return Mass_Type::getSystemName(this->system_); }

template<typename T_Arithmetic>
std::string Mass<T_Arithmetic>::getTypeName() const{ return Mass_Type::getTypeName(this->type_); }

template<typename T_Arithmetic>
std::string Mass<T_Arithmetic>::getPrefixName() const{ return Mass_Type::getPrefixName(this->prefix_); }

template<typename T_Arithmetic>
std::string Mass<T_Arithmetic>::getTypeWPrefixName() const{ return Mass_Type::getTypeName(this->type_, this->prefix_); }


template<typename T_Arithmetic>
T_Arithmetic Mass<T_Arithmetic>::convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit){
    Mass<T_Arithmetic>* temp = dynamic_cast< Mass<T_Arithmetic>* >(target);
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
T_Arithmetic Mass<T_Arithmetic>::convertTo(Mass_Type::Type type, bool in_place){
	switch (Mass_Type::getSystem(type))
	{
	case Mass_Type::System::Metric:
		return convertToMetric(type, Mass_Type::Prefix::None, in_place);
		break;
	case Mass_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Mass_Type::System::US_Customary:
		return convertToUSCustomary(type, in_place);
		break;
	
	default:
		std::cerr << "Unknown Type";
        return 0;
		break;
	}
}

template<typename T_Arithmetic>
T_Arithmetic Mass<T_Arithmetic>::convertTo(Mass_Type::Type type, Mass_Type::Prefix prefix, bool in_place){
	switch (Mass_Type::getSystem(type))
	{
	case Mass_Type::System::Metric:
		return convertToMetric(type, prefix, in_place);
		break;
	case Mass_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Mass_Type::System::US_Customary:
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
void Mass<T_Arithmetic>::setSystem(Mass_Type::System system){ this->system_ = system; }

template<typename T_Arithmetic>
void Mass<T_Arithmetic>::setType(Mass_Type::Type type, Mass_Type::Prefix prefix){
	this->type_ = type;

	if(type == Mass_Type::Type::Gram){
		setPrefix(prefix);
	}
	else{
		setPrefix(Mass_Type::Prefix::None);
	}

	setSystem(Mass_Type::getSystem(type));
	setSymbol();
}

template<typename T_Arithmetic>
void Mass<T_Arithmetic>::setPrefix(Mass_Type::Prefix prefix){ this->prefix_ = prefix; }

template<typename T_Arithmetic>
void Mass<T_Arithmetic>::setSymbol(){
	switch(this->system_){
		case Mass_Type::System::Metric:
			switch (this->type_){
				case Mass_Type::Type::Gram:
					switch (this->prefix_){
						case Mass_Type::Prefix::yocto:
							this->symbol_ = "yg";
							break;
						case Mass_Type::Prefix::zepto:
							this->symbol_ = "zg";
							break;
						case Mass_Type::Prefix::atto:
							this->symbol_ = "ag";
							break;
						case Mass_Type::Prefix::femto:
							this->symbol_ = "fg";
							break;
						case Mass_Type::Prefix::pico:
							this->symbol_ = "pg";
							break;
						case Mass_Type::Prefix::nano:
							this->symbol_ = "ng";
							break;
						case Mass_Type::Prefix::micro:
							this->symbol_ = "μg";
							break;
						case Mass_Type::Prefix::milli:
							this->symbol_ = "mg";
							break;
						case Mass_Type::Prefix::centi:
							this->symbol_ = "cg";
							break;
						case Mass_Type::Prefix::deci:
							this->symbol_ = "dg";
							break;
						case Mass_Type::Prefix::deca:
							this->symbol_ = "dag";
							break;
						case Mass_Type::Prefix::hecto:
							this->symbol_ = "hg";
							break;
						case Mass_Type::Prefix::kilo:
							this->symbol_ = "kg";
							break;
						case Mass_Type::Prefix::mega:
							this->symbol_ = "Mg";
							break;
						case Mass_Type::Prefix::giga:
							this->symbol_ = "Gg";
							break;
						case Mass_Type::Prefix::tera:
							this->symbol_ = "Tg";
							break;
						case Mass_Type::Prefix::peta:
							this->symbol_ = "Pg";
							break;
						case Mass_Type::Prefix::exa:
							this->symbol_ = "Eg";
							break;
						case Mass_Type::Prefix::zetta:
							this->symbol_ = "Zg";
							break;
						case Mass_Type::Prefix::yotta:
							this->symbol_ = "Yg";
							break;
						
						default:
							this->symbol_ = "g";
							break;
					}
					break;
				case Mass_Type::Type::Tonne:
					this->symbol_ = "t";
					break;
				case Mass_Type::Type::Carat:
					this->symbol_ = "ct";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Mass_Type::System::Imperial:
			switch(this->type_){
				case Mass_Type::Type::Grain:
					this->symbol_ = "gr";
					break;
				case Mass_Type::Type::Drachm:
					this->symbol_ = "dr";
					break;
				case Mass_Type::Type::Ounce:
					this->symbol_ = "Oz";
					break;
				case Mass_Type::Type::Pound:
					this->symbol_ = "lb";
					break;
				case Mass_Type::Type::Stone:
					this->symbol_ = "st";
					break;
				case Mass_Type::Type::Quarter:
					this->symbol_ = "qr";
					break;
				case Mass_Type::Type::Hundredweight:
					this->symbol_ = "cwt";
					break;
				case Mass_Type::Type::Ton:
					this->symbol_ = "t";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Mass_Type::System::US_Customary:
			switch(this->type_){
				case Mass_Type::Type::Dram:
					this->symbol_ = "dr";
					break;
				case Mass_Type::Type::US_Hundredweight:
					this->symbol_ = "cwt";
					break;
				case Mass_Type::Type::US_Ton:
					this->symbol_ = "t";
					break;
				case Mass_Type::Type::Pennyweight:
					this->symbol_ = "dwt";
					break;
				case Mass_Type::Type::Troy_Ounce:
					this->symbol_ = "oz t";
					break;
				case Mass_Type::Type::Troy_Pound:
					this->symbol_ = "lb t";
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
T_Arithmetic Mass<T_Arithmetic>::convertToMetric(Mass_Type::Type type, Mass_Type::Prefix prefix, bool in_place){

	//Obtains the current value converted to Grams
	double temp_value = convertToBasicUnit(Mass_Type::System::Metric);
	
	//Converts Gram to the appropriate Metric value
	switch (type){
		case Mass_Type::Type::Gram:
			switch (prefix){
				case Mass_Type::Prefix::yocto:
					temp_value *= 1e24;
					break;
				case Mass_Type::Prefix::zepto:
					temp_value *= 1e21;
					break;
				case Mass_Type::Prefix::atto:
					temp_value *= 1e18;
					break;
				case Mass_Type::Prefix::femto:
					temp_value *= 1e15;
					break;
				case Mass_Type::Prefix::pico:
					temp_value *= 1e12;
					break;
				case Mass_Type::Prefix::nano:
					temp_value *= 1e9;
					break;
				case Mass_Type::Prefix::micro:
					temp_value *= 1e6;
					break;
				case Mass_Type::Prefix::milli:
					temp_value *= 1e3;
					break;
				case Mass_Type::Prefix::centi:
					temp_value *= 1e2;
					break;
				case Mass_Type::Prefix::deci:
					temp_value *= 1e1;
					break;
				case Mass_Type::Prefix::deca:
					temp_value *= 1e-1;
					break;
				case Mass_Type::Prefix::hecto:
					temp_value *= 1e-2;
					break;
				case Mass_Type::Prefix::kilo:
					temp_value *= 1e-3;
					break;
				case Mass_Type::Prefix::mega:
					temp_value *= 1e-6;
					break;
				case Mass_Type::Prefix::giga:
					temp_value *= 1e-9;
					break;
				case Mass_Type::Prefix::tera:
					temp_value *= 1e-12;
					break;
				case Mass_Type::Prefix::peta:
					temp_value *= 1e-15;
					break;
				case Mass_Type::Prefix::exa:
					temp_value *= 1e-18;
					break;
				case Mass_Type::Prefix::zetta:
					temp_value *= 1e-21;
					break;
				case Mass_Type::Prefix::yotta:
					temp_value *= 1e-24;
					break;
				
				default:
					break;
			}
			break;
		case Mass_Type::Type::Tonne:
			temp_value *= 1e-6;
			prefix = Mass_Type::Prefix::None;
			break;
		case Mass_Type::Type::Carat:
			temp_value *= 5;
			prefix = Mass_Type::Prefix::None;
			break;
		default:
			prefix = Mass_Type::Prefix::None;
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Mass_Type::System::Metric;
		this->type_ = type;
		this->prefix_ = prefix;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Mass<T_Arithmetic>::convertToImperial(Mass_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Pounds
	double temp_value = convertToBasicUnit(Mass_Type::System::Imperial);

	//Converts Pounds to the appropriate Imperial value
	switch(type){
		case Mass_Type::Type::Grain:
			temp_value *= 7000.0;
			break;
		case Mass_Type::Type::Drachm:
			temp_value *= 256.0;
			break;
		case Mass_Type::Type::Ounce:
			temp_value *= 16.0;
			break;
		case Mass_Type::Type::Stone:
			temp_value /= 14.0;
			break;
		case Mass_Type::Type::Quarter:
			temp_value /= 28.0;
			break;
		case Mass_Type::Type::Hundredweight:
			temp_value /= 112.0;
			break;
		case Mass_Type::Type::Ton:
			temp_value /= 2240.0;
			break;
		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Mass_Type::System::Imperial;
		this->type_ = type;
		this->prefix_ = Mass_Type::Prefix::None;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Mass<T_Arithmetic>::convertToUSCustomary(Mass_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Pounds (same as Imperial)
	double temp_value = convertToBasicUnit(Mass_Type::System::US_Customary);

	//Converts Pound to the appropriate US Customary value
	switch(type){
		case Mass_Type::Type::Dram:
			temp_value *= 256.0;
			break;
		case Mass_Type::Type::US_Hundredweight:
			temp_value /= 100.0;
			break;
		case Mass_Type::Type::US_Ton:
			temp_value /= 2000.0;
			break;
		case Mass_Type::Type::Pennyweight:
			temp_value *= (3.0 / 875.0);
			break;
		case Mass_Type::Type::Troy_Ounce:
			temp_value *= (12.0 / 175);
			break;
		case Mass_Type::Type::Troy_Pound:
			temp_value /= (144.0 / 175.0);
			break;

		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Mass_Type::System::US_Customary;
		this->type_ = type;
		this->prefix_ = Mass_Type::Prefix::None;
		setSymbol();
	}

	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
double Mass<T_Arithmetic>::convertToBasicUnit(Mass_Type::System system){

	double temp_value = static_cast<double>(this->value_);

	//Convert to the basic unit of each system
	switch(this->system_){
		//Converts all metric units to Gram
		case Mass_Type::System::Metric:
			switch (this->type_){
				case Mass_Type::Type::Gram:
					switch (this->prefix_){
						case Mass_Type::Prefix::yocto:
							temp_value *= 1e-24;
							break;
						case Mass_Type::Prefix::zepto:
							temp_value *= 1e-21;
							break;
						case Mass_Type::Prefix::atto:
							temp_value *= 1e-18;
							break;
						case Mass_Type::Prefix::femto:
							temp_value *= 1e-15;
							break;
						case Mass_Type::Prefix::pico:
							temp_value *= 1e-12;
							break;
						case Mass_Type::Prefix::nano:
							temp_value *= 1e-9;
							break;
						case Mass_Type::Prefix::micro:
							temp_value *= 1e-6;
							break;
						case Mass_Type::Prefix::milli:
							temp_value *= 1e-3;
							break;
						case Mass_Type::Prefix::centi:
							temp_value *= 1e-2;
							break;
						case Mass_Type::Prefix::deci:
							temp_value *= 1e-1;
							break;
						case Mass_Type::Prefix::deca:
							temp_value *= 1e1;
							break;
						case Mass_Type::Prefix::hecto:
							temp_value *= 1e2;
							break;
						case Mass_Type::Prefix::kilo:
							temp_value *= 1e3;
							break;
						case Mass_Type::Prefix::mega:
							temp_value *= 1e6;
							break;
						case Mass_Type::Prefix::giga:
							temp_value *= 1e9;
							break;
						case Mass_Type::Prefix::tera:
							temp_value *= 1e12;
							break;
						case Mass_Type::Prefix::peta:
							temp_value *= 1e15;
							break;
						case Mass_Type::Prefix::exa:
							temp_value *= 1e18;
							break;
						case Mass_Type::Prefix::zetta:
							temp_value *= 1e21;
							break;
						case Mass_Type::Prefix::yotta:
							temp_value *= 1e24;
							break;
						default:
							break;
					}
					break;
				case Mass_Type::Type::Tonne:
					temp_value *= 1e6;
					break;
				case Mass_Type::Type::Carat:
					temp_value *= 0.2;
					break;
				default:
					break;
			}
			break;
		//Converts all Imperial units to Pounds
		case Mass_Type::System::Imperial:
			switch(this->type_){
				case Mass_Type::Type::Grain:
					temp_value /= 7000.0;
					break;
				case Mass_Type::Type::Drachm:
					temp_value /= 256.0;
					break;
				case Mass_Type::Type::Ounce:
					temp_value /= 16.0;
					break;
				case Mass_Type::Type::Stone:
					temp_value *= 14.0;
					break;
				case Mass_Type::Type::Quarter:
					temp_value *= 28.0;
					break;
				case Mass_Type::Type::Hundredweight:
					temp_value *= 112.0;
					break;
				case Mass_Type::Type::Ton:
					temp_value *= 2240.0;
					break;
				default:
					break;
			}
			break;
		//Converts all US_Customary units to Pounds (Same as Imperial)
		case Mass_Type::System::US_Customary:
			switch(this->type_){
				case Mass_Type::Type::Dram:
					temp_value /= 256.0;
					break;
				case Mass_Type::Type::US_Hundredweight:
					temp_value *= 100.0;
					break;
				case Mass_Type::Type::US_Ton:
					temp_value *= 2000.0;
					break;
				case Mass_Type::Type::Pennyweight:
					temp_value /= (3.0 / 875.0);
					break;
				case Mass_Type::Type::Troy_Ounce:
					temp_value /= (12.0 / 175);
					break;
				case Mass_Type::Type::Troy_Pound:
					temp_value *= (144.0 / 175.0);
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
		case Mass_Type::System::Metric:
			if(system != this->system_){
				//Convert grams to pounds
				temp_value /= 453.59237;
			}
			break;
		case Mass_Type::System::Imperial:
		case Mass_Type::System::US_Customary:
			if(system == Mass_Type::System::Metric){
				//Convert pounds to grams
				temp_value *= 453.59237;
			}
			break;
		default:
			std::cerr << "Unknown System";
			break;
	}

	return temp_value;
}

};

#endif //__MASS_TCC__
