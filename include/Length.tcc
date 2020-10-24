#ifndef __LENGTH_TCC__
#define __LENGTH_TCC__

//Used for development
#ifndef __LENGTH_HPP__
#include "Length.hpp"
#endif


namespace afzm{

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(){
	this->value_ = 0;
	this->system_ = Length_Type::System::Metric;
	this->type_ = Length_Type::Type::Metre;
	this->prefix_ = Length_Type::Prefix::None;
	this->symbol_ = "m";
    this->name_ = "";
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(T_Arithmetic value){
	this->value_ = value;
	this->system_ = Length_Type::System::Metric;
	this->type_ = Length_Type::Type::Metre;
	this->prefix_ = Length_Type::Prefix::None;
	this->symbol_ = "m";
	this->name_ = "";
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(T_Arithmetic value, Length_Type::Type type, Length_Type::Prefix prefix){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(T_Arithmetic value, std::string name){
	this->value_ = value;
	this->system_ = Length_Type::System::Metric;
	this->type_ = Length_Type::Type::Metre;
	this->prefix_ = Length_Type::Prefix::None;
	this->symbol_ = "m";
	this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(T_Arithmetic value, Length_Type::Type type, std::string name){
	this->value_ = value;
	setType(type);
    this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(T_Arithmetic value, Length_Type::Type type, Length_Type::Prefix prefix, std::string name){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(std::string name){
	this->value_ = 0;
	this->system_ = Length_Type::System::Metric;
	this->type_ = Length_Type::Type::Metre;
	this->prefix_ = Length_Type::Prefix::None;
	this->symbol_ = "m";
	this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(Length_Type::Type type, std::string name){
	this->value_ = 0;
	setType(type);
	this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(Length_Type::Type type, Length_Type::Prefix prefix, std::string name){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::Length(Length_Type::Type type, Length_Type::Prefix prefix){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Length<T_Arithmetic>::~Length(){}


template<typename T_Arithmetic>
void Length<T_Arithmetic>::changeType(std::string type, std::string prefix){ setType(Length_Type::getTypeEnum(type), Length_Type::getPrefixEnum(prefix)); }

template<typename T_Arithmetic>
void Length<T_Arithmetic>::changeType(Length_Type::Type type, Length_Type::Prefix prefix){ setType(type, prefix); }


template<typename T_Arithmetic>
Length_Type::System Length<T_Arithmetic>::getSystem() const{ return this->system_; }

template<typename T_Arithmetic>
Length_Type::Type Length<T_Arithmetic>::getType() const{ return this->type_; }

template<typename T_Arithmetic>
Length_Type::Prefix Length<T_Arithmetic>::getPrefix() const{ return this->prefix_; }

template<typename T_Arithmetic>
std::string Length<T_Arithmetic>::getSystemName() const{ return Length_Type::getSystemName(this->system_); }

template<typename T_Arithmetic>
std::string Length<T_Arithmetic>::getTypeName() const{ return Length_Type::getTypeName(this->type_); }

template<typename T_Arithmetic>
std::string Length<T_Arithmetic>::getPrefixName() const{ return Length_Type::getPrefixName(this->prefix_); }

template<typename T_Arithmetic>
std::string Length<T_Arithmetic>::getTypeWPrefixName() const{ return Length_Type::getTypeName(this->type_, this->prefix_); }

template<typename T_Arithmetic>
T_Arithmetic Length<T_Arithmetic>::convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit){
    Length<T_Arithmetic>* temp = dynamic_cast< Length<T_Arithmetic>* >(target);
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
T_Arithmetic Length<T_Arithmetic>::convertTo(Length_Type::Type type, bool in_place){
	switch (Length_Type::getSystem(type))
	{
	case Length_Type::System::Metric:
		return convertToMetric(type, Length_Type::Prefix::None, in_place);
		break;
	case Length_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Length_Type::System::US_Customary:
		return convertToUSCustomary(type, in_place);
		break;
	
	default:
		std::cerr << "Unknown Type";
        return 0;
		break;
	}
}

template<typename T_Arithmetic>
T_Arithmetic Length<T_Arithmetic>::convertTo(Length_Type::Type type, Length_Type::Prefix prefix, bool in_place){
	switch (Length_Type::getSystem(type))
	{
	case Length_Type::System::Metric:
		return convertToMetric(type, prefix, in_place);
		break;
	case Length_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Length_Type::System::US_Customary:
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
void Length<T_Arithmetic>::setSystem(Length_Type::System system){ this->system_ = system; }

template<typename T_Arithmetic>
void Length<T_Arithmetic>::setType(Length_Type::Type type, Length_Type::Prefix prefix){
	this->type_ = type;

	if(type == Length_Type::Type::Metre){
		setPrefix(prefix);
	}
	else{
		setPrefix(Length_Type::Prefix::None);
	}

	setSystem(Length_Type::getSystem(type));
	setSymbol();
}

template<typename T_Arithmetic>
void Length<T_Arithmetic>::setPrefix(Length_Type::Prefix prefix){ this->prefix_ = prefix; }

template<typename T_Arithmetic>
void Length<T_Arithmetic>::setSymbol(){
	switch(this->system_){
		case Length_Type::System::Metric:
			switch (this->type_){
				case Length_Type::Type::Metre:
					switch (this->prefix_){
						case Length_Type::Prefix::yocto:
							this->symbol_ = "ym";
							break;
						case Length_Type::Prefix::zepto:
							this->symbol_ = "zm";
							break;
						case Length_Type::Prefix::atto:
							this->symbol_ = "am";
							break;
						case Length_Type::Prefix::femto:
							this->symbol_ = "fm";
							break;
						case Length_Type::Prefix::pico:
							this->symbol_ = "pm";
							break;
						case Length_Type::Prefix::nano:
							this->symbol_ = "nm";
							break;
						case Length_Type::Prefix::micro:
							this->symbol_ = "μm";
							break;
						case Length_Type::Prefix::milli:
							this->symbol_ = "mm";
							break;
						case Length_Type::Prefix::centi:
							this->symbol_ = "cm";
							break;
						case Length_Type::Prefix::deci:
							this->symbol_ = "dm";
							break;
						case Length_Type::Prefix::deca:
							this->symbol_ = "dam";
							break;
						case Length_Type::Prefix::hecto:
							this->symbol_ = "hm";
							break;
						case Length_Type::Prefix::kilo:
							this->symbol_ = "km";
							break;
						case Length_Type::Prefix::mega:
							this->symbol_ = "Mm";
							break;
						case Length_Type::Prefix::giga:
							this->symbol_ = "Gm";
							break;
						case Length_Type::Prefix::tera:
							this->symbol_ = "Tm";
							break;
						case Length_Type::Prefix::peta:
							this->symbol_ = "Pm";
							break;
						case Length_Type::Prefix::exa:
							this->symbol_ = "Em";
							break;
						case Length_Type::Prefix::zetta:
							this->symbol_ = "Zm";
							break;
						case Length_Type::Prefix::yotta:
							this->symbol_ = "Ym";
							break;
						
						default:
							this->symbol_ = "m";
							break;
					}
					break;
				case Length_Type::Type::Fermi:
					this->symbol_ = "fm";
					break;
				case Length_Type::Type::Angstrom:
					this->symbol_ = "Å";
					break;
				case Length_Type::Type::Micron:
					this->symbol_ = "μm";
					break;
				case Length_Type::Type::Myriametre:
                    this->symbol_ = "myriametre";
					break;
				case Length_Type::Type::X_Unit:
					this->symbol_ = "xu";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Length_Type::System::Imperial:
			switch(this->type_){
				case Length_Type::Type::Point:
					this->symbol_ = "p";
					break;
				case Length_Type::Type::Pica:
					this->symbol_ = "pc";
					break;
				case Length_Type::Type::Thou:
					this->symbol_ = "th";
					break;
				case Length_Type::Type::Inch:
					this->symbol_ = "in";
					break;
				case Length_Type::Type::Foot:
					this->symbol_ = "ft";
					break;
				case Length_Type::Type::Yard:
					this->symbol_ = "yd";
					break;
				case Length_Type::Type::Chain:
					this->symbol_ = "ch";
					break;
				case Length_Type::Type::Furlong:
					this->symbol_ = "fur";
					break;
				case Length_Type::Type::Mile:
					this->symbol_ = "mi";
					break;
				case Length_Type::Type::League:
					this->symbol_ = "lea";
					break;
				case Length_Type::Type::Fathom:
					this->symbol_ = "ftm";
					break;
				case Length_Type::Type::Short_Cable:
					this->symbol_ = "cb";
					break;
				case Length_Type::Type::Long_Cable:
					this->symbol_ = "cb";
					break;
				case Length_Type::Type::Nautical_Mile:
					this->symbol_ = "NM";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Length_Type::System::US_Customary:
			switch(this->type_){
				case Length_Type::Type::Link:
					this->symbol_ = "li";
					break;
				case Length_Type::Type::Survey_Inch:
					this->symbol_ = "in";
					break;
				case Length_Type::Type::Survey_Foot:
					this->symbol_ = "ft";
					break;
				case Length_Type::Type::Rod:
					this->symbol_ = "rd";
					break;
				case Length_Type::Type::Survey_Furlong:
					this->symbol_ = "fur";
					break;
				case Length_Type::Type::Survey_Mile:
					this->symbol_ = "mi";
					break;
				case Length_Type::Type::Survey_League:
					this->symbol_ = "lea";
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
T_Arithmetic Length<T_Arithmetic>::convertToMetric(Length_Type::Type type, Length_Type::Prefix prefix, bool in_place){

	//Obtains the current value converted to Metres
	double temp_value = convertToBasicUnit(Length_Type::System::Metric);
	
	//Converts Metre to the appropriate Metric value
	switch (type){
		case Length_Type::Type::Metre:
			switch (prefix){
				case Length_Type::Prefix::yocto:
					temp_value *= 1e24;
					break;
				case Length_Type::Prefix::zepto:
					temp_value *= 1e21;
					break;
				case Length_Type::Prefix::atto:
					temp_value *= 1e18;
					break;
				case Length_Type::Prefix::femto:
					temp_value *= 1e15;
					break;
				case Length_Type::Prefix::pico:
					temp_value *= 1e12;
					break;
				case Length_Type::Prefix::nano:
					temp_value *= 1e9;
					break;
				case Length_Type::Prefix::micro:
					temp_value *= 1e6;
					break;
				case Length_Type::Prefix::milli:
					temp_value *= 1e3;
					break;
				case Length_Type::Prefix::centi:
					temp_value *= 1e2;
					break;
				case Length_Type::Prefix::deci:
					temp_value *= 1e1;
					break;
				case Length_Type::Prefix::deca:
					temp_value *= 1e-1;
					break;
				case Length_Type::Prefix::hecto:
					temp_value *= 1e-2;
					break;
				case Length_Type::Prefix::kilo:
					temp_value *= 1e-3;
					break;
				case Length_Type::Prefix::mega:
					temp_value *= 1e-6;
					break;
				case Length_Type::Prefix::giga:
					temp_value *= 1e-9;
					break;
				case Length_Type::Prefix::tera:
					temp_value *= 1e-12;
					break;
				case Length_Type::Prefix::peta:
					temp_value *= 1e-15;
					break;
				case Length_Type::Prefix::exa:
					temp_value *= 1e-18;
					break;
				case Length_Type::Prefix::zetta:
					temp_value *= 1e-21;
					break;
				case Length_Type::Prefix::yotta:
					temp_value *= 1e-24;
					break;
				
				default:
					break;
			}
			break;
		case Length_Type::Type::Fermi:
			temp_value *= 1e15;
			prefix = Length_Type::Prefix::None;
			break;
		case Length_Type::Type::Angstrom:
			temp_value *= 1e10;
			prefix = Length_Type::Prefix::None;
			break;
		case Length_Type::Type::Micron:
			temp_value *= 1e6;
			prefix = Length_Type::Prefix::None;
			break;
		case Length_Type::Type::Myriametre:
			temp_value *= 1e-4;
			prefix = Length_Type::Prefix::None;
			break;
		case Length_Type::Type::X_Unit:
			temp_value *= 1e13;
			prefix = Length_Type::Prefix::None;
			break;
		default:
			prefix = Length_Type::Prefix::None;
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Length_Type::System::Metric;
		this->type_ = type;
		this->prefix_ = prefix;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Length<T_Arithmetic>::convertToImperial(Length_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Feet
	double temp_value = convertToBasicUnit(Length_Type::System::Imperial);

	//Converts Feet to the appropriate Imperial value
	switch(type){
		case Length_Type::Type::Point:
			temp_value *= 864.0;
			break;
		case Length_Type::Type::Pica:
			temp_value *= 72.0;
			break;
		case Length_Type::Type::Thou:
			temp_value *= 12000.0;
			break;
		case Length_Type::Type::Inch:
			temp_value *= 12.0;
			break;
		case Length_Type::Type::Yard:
			temp_value /= 3.0;
			break;
		case Length_Type::Type::Chain:
			temp_value /= 66.0;
			break;
		case Length_Type::Type::Furlong:
			temp_value /= 660.0;
			break;
		case Length_Type::Type::Mile:
			temp_value /= 5280.0;
			break;
		case Length_Type::Type::League:
			temp_value /= 15840.0;
			break;
		case Length_Type::Type::Fathom:
			temp_value /= 6.0;
			break;
		case Length_Type::Type::Short_Cable:
			temp_value /= 607.61;
			break;
		case Length_Type::Type::Long_Cable:
			temp_value /= 720.0;
			break;
		case Length_Type::Type::Nautical_Mile:
			temp_value /= 6076.1;
			break;
		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Length_Type::System::Imperial;
		this->type_ = type;
		this->prefix_ = Length_Type::Prefix::None;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Length<T_Arithmetic>::convertToUSCustomary(Length_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Survey Feet
	double temp_value = convertToBasicUnit(Length_Type::System::US_Customary);

	//Converts Survey Feet to the appropriate US Customary value
	switch(type){
		case Length_Type::Type::Link:
			temp_value /= (33.0 / 55.0);
			break;
		case Length_Type::Type::Survey_Inch:
			temp_value *= 12.0;
			break;
		case Length_Type::Type::Rod:
			temp_value /= 16.5;
			break;
		case Length_Type::Type::Survey_Chain:
			temp_value /= 66.0;
			break;
		case Length_Type::Type::Survey_Furlong:
			temp_value /= 660.0;
			break;
		case Length_Type::Type::Survey_Mile:
			temp_value /= 5280.0;
			break;
		case Length_Type::Type::Survey_League:
			temp_value /= 15840.0;
			break;

		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Length_Type::System::US_Customary;
		this->type_ = type;
		this->prefix_ = Length_Type::Prefix::None;
		setSymbol();
	}

	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
double Length<T_Arithmetic>::convertToBasicUnit(Length_Type::System system){

	double temp_value = static_cast<double>(this->value_);

	//Convert to the basic unit of each system
	switch(this->system_){
		//Converts all metric units to Metre
		case Length_Type::System::Metric:
			switch (this->type_){
				case Length_Type::Type::Metre:
					switch (this->prefix_){
						case Length_Type::Prefix::yocto:
							temp_value *= 1e-24;
							break;
						case Length_Type::Prefix::zepto:
							temp_value *= 1e-21;
							break;
						case Length_Type::Prefix::atto:
							temp_value *= 1e-18;
							break;
						case Length_Type::Prefix::femto:
							temp_value *= 1e-15;
							break;
						case Length_Type::Prefix::pico:
							temp_value *= 1e-12;
							break;
						case Length_Type::Prefix::nano:
							temp_value *= 1e-9;
							break;
						case Length_Type::Prefix::micro:
							temp_value *= 1e-6;
							break;
						case Length_Type::Prefix::milli:
							temp_value *= 1e-3;
							break;
						case Length_Type::Prefix::centi:
							temp_value *= 1e-2;
							break;
						case Length_Type::Prefix::deci:
							temp_value *= 1e-1;
							break;
						case Length_Type::Prefix::deca:
							temp_value *= 1e1;
							break;
						case Length_Type::Prefix::hecto:
							temp_value *= 1e2;
							break;
						case Length_Type::Prefix::kilo:
							temp_value *= 1e3;
							break;
						case Length_Type::Prefix::mega:
							temp_value *= 1e6;
							break;
						case Length_Type::Prefix::giga:
							temp_value *= 1e9;
							break;
						case Length_Type::Prefix::tera:
							temp_value *= 1e12;
							break;
						case Length_Type::Prefix::peta:
							temp_value *= 1e15;
							break;
						case Length_Type::Prefix::exa:
							temp_value *= 1e18;
							break;
						case Length_Type::Prefix::zetta:
							temp_value *= 1e21;
							break;
						case Length_Type::Prefix::yotta:
							temp_value *= 1e24;
							break;
						default:
							break;
					}
					break;
				case Length_Type::Type::Fermi:
					temp_value *= 1e-15;
					break;
				case Length_Type::Type::Angstrom:
					temp_value *= 1e-10;
					break;
				case Length_Type::Type::Micron:
					temp_value *= 1e-6;
					break;
				case Length_Type::Type::Myriametre:
					temp_value *= 1e4;
					break;
				case Length_Type::Type::X_Unit:
					temp_value *= 1e-13;
					break;
				default:
					break;
			}
			break;
		//Converts all Imperial units to Feet
		case Length_Type::System::Imperial:
			switch(this->type_){
				case Length_Type::Type::Point:
					temp_value /= 864.0;
					break;
				case Length_Type::Type::Pica:
					temp_value /= 72.0;
					break;
				case Length_Type::Type::Thou:
					temp_value /= 12000.0;
					break;
				case Length_Type::Type::Inch:
					temp_value /= 12.0;
					break;
				case Length_Type::Type::Yard:
					temp_value *= 3.0;
					break;
				case Length_Type::Type::Chain:
					temp_value *= 66.0;
					break;
				case Length_Type::Type::Furlong:
					temp_value *= 660.0;
					break;
				case Length_Type::Type::Mile:
					temp_value *= 5280.0;
					break;
				case Length_Type::Type::League:
					temp_value *= 15840.0;
					break;
				case Length_Type::Type::Fathom:
					temp_value *= 6.0;
					break;
				case Length_Type::Type::Short_Cable:
					temp_value *= 607.61;
					break;
				case Length_Type::Type::Long_Cable:
					temp_value *= 720.0;
					break;
				case Length_Type::Type::Nautical_Mile:
					temp_value *= 6076.1;
					break;
				default:
					break;
			}
			break;
		//Converts all US_Customary units to Survey Feet
		case Length_Type::System::US_Customary:
			switch(this->type_){
				case Length_Type::Type::Link:
					temp_value *= (33.0 / 50.0);
					break;
				case Length_Type::Type::Survey_Inch:
					temp_value /= 12.0;
					break;
				case Length_Type::Type::Rod:
					temp_value *= 16.5;
					break;
				case Length_Type::Type::Survey_Chain:
					temp_value *= 66.0;
					break;
				case Length_Type::Type::Survey_Furlong:
					temp_value *= 660.0;
					break;
				case Length_Type::Type::Survey_Mile:
					temp_value *= 5280.0;
					break;
				case Length_Type::Type::Survey_League:
					temp_value *= 15840.0;
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
		case Length_Type::System::Metric:
			if(system == Length_Type::System::Imperial){
				//Convert metres to feet
				temp_value /= 0.3048;
			}
			else if(system == Length_Type::System::US_Customary){
				//Convert metres to survey feet
				temp_value /= 0.304806;
			}
			break;
		case Length_Type::System::Imperial:
			if(system == Length_Type::System::Metric){
				//Convert feet to metres
				temp_value *= 0.3048;
			}
			else if(system == Length_Type::System::US_Customary){
				//Convert feet to survey feet
				temp_value *= 0.999998;
			}
        break;
		case Length_Type::System::US_Customary:
			if(system == Length_Type::System::Metric){
				//Convert Survey feet to metres
				temp_value *= 0.304806;
			}
			else if(system == Length_Type::System::Imperial){
				//Convert Survey feet to feet
				temp_value /= 0.999998;
			}
			break;
		default:
			std::cerr << "Unknown System";
			break;
	}

	return temp_value;
}

};

#endif //__LENGTH_TCC__
