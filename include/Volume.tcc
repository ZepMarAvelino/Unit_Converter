#ifndef __VOLUME_TCC__
#define __VOLUME_TCC__

//Used for development
#ifndef __VOLUME_HPP__
#include "Volume.hpp"
#endif

namespace afzm{


template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(){
	this->value_ = 0;
	this->system_ = Volume_Type::System::Metric;
	this->type_ = Volume_Type::Type::Metre_Cubic;
	this->prefix_ = Volume_Type::Prefix::None;
	this->symbol_ = "m^3";
	this->name_ = "";
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(T_Arithmetic value){
	this->value_ = value;
	this->system_ = Volume_Type::System::Metric;
	this->type_ = Volume_Type::Type::Metre_Cubic;
	this->prefix_ = Volume_Type::Prefix::None;
	this->symbol_ = "m^3";
	this->name_ = "";
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(T_Arithmetic value, Volume_Type::Type type, Volume_Type::Prefix prefix){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(T_Arithmetic value, std::string name){
	this->value_ = value;
	this->system_ = Volume_Type::System::Metric;
	this->type_ = Volume_Type::Type::Metre_Cubic;
	this->prefix_ = Volume_Type::Prefix::None;
	this->symbol_ = "m^3";
	this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(T_Arithmetic value, Volume_Type::Type type, std::string name){
	this->value_ = value;
	setType(type);
    this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(T_Arithmetic value, Volume_Type::Type type, Volume_Type::Prefix prefix, std::string name){
	this->value_ = value;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(std::string name){
	this->value_ = 0;
	this->system_ = Volume_Type::System::Metric;
	this->type_ = Volume_Type::Type::Metre_Cubic;
	this->prefix_ = Volume_Type::Prefix::None;
	this->symbol_ = "m^3";
	this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(Volume_Type::Type type, std::string name){
	this->value_ = 0;
	setType(type);
	this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(Volume_Type::Type type, Volume_Type::Prefix prefix, std::string name){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = name;
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::Volume(Volume_Type::Type type, Volume_Type::Prefix prefix){
	this->value_ = 0;
	setType(type, prefix);
	this->name_ = "";
}

template<typename T_Arithmetic>
Volume<T_Arithmetic>::~Volume(){}


template<typename T_Arithmetic>
void Volume<T_Arithmetic>::changeType(std::string type, std::string prefix){ setType(Volume_Type::getTypeEnum(type), Volume_Type::getPrefixEnum(prefix)); }

template<typename T_Arithmetic>
void Volume<T_Arithmetic>::changeType(Volume_Type::Type type, Volume_Type::Prefix prefix){ setType(type, prefix); }



template<typename T_Arithmetic>
Volume_Type::System Volume<T_Arithmetic>::getSystem() const{ return this->system_; }

template<typename T_Arithmetic>
Volume_Type::Type Volume<T_Arithmetic>::getType() const{ return this->type_; }

template<typename T_Arithmetic>
Volume_Type::Prefix Volume<T_Arithmetic>::getPrefix() const{ return this->prefix_; }

template<typename T_Arithmetic>
std::string Volume<T_Arithmetic>::getSystemName() const{ return Volume_Type::getSystemName(this->system_); }

template<typename T_Arithmetic>
std::string Volume<T_Arithmetic>::getTypeName() const{ return Volume_Type::getTypeName(this->type_); }

template<typename T_Arithmetic>
std::string Volume<T_Arithmetic>::getPrefixName() const{ return Volume_Type::getPrefixName(this->prefix_); }

template<typename T_Arithmetic>
std::string Volume<T_Arithmetic>::getTypeWPrefixName() const{ return Volume_Type::getTypeName(this->type_, this->prefix_); }


template<typename T_Arithmetic>
T_Arithmetic Volume<T_Arithmetic>::convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit){
    Volume<T_Arithmetic>* temp = dynamic_cast< Volume<T_Arithmetic>* >(target);
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
T_Arithmetic Volume<T_Arithmetic>::convertTo(Volume_Type::Type type, bool in_place){
	switch (Volume_Type::getSystem(type))
	{
	case Volume_Type::System::Metric:
		return convertToMetric(type, Volume_Type::Prefix::None, in_place);
		break;
	case Volume_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Volume_Type::System::US_Customary:
		return convertToUSCustomary(type, in_place);
		break;
	
	default:
		std::cerr << "Unknown Type";
        return 0;
		break;
	}
}

template<typename T_Arithmetic>
T_Arithmetic Volume<T_Arithmetic>::convertTo(Volume_Type::Type type, Volume_Type::Prefix prefix, bool in_place){
	switch (Volume_Type::getSystem(type))
	{
	case Volume_Type::System::Metric:
		return convertToMetric(type, prefix, in_place);
		break;
	case Volume_Type::System::Imperial:
		return convertToImperial(type, in_place);
		break;
	case Volume_Type::System::US_Customary:
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
void Volume<T_Arithmetic>::setSystem(Volume_Type::System system){ this->system_ = system; }

template<typename T_Arithmetic>
void Volume<T_Arithmetic>::setType(Volume_Type::Type type, Volume_Type::Prefix prefix){
	this->type_ = type;

	if((type == Volume_Type::Type::Metre_Cubic) || (type == Volume_Type::Type::Litre)){
		setPrefix(prefix);
	}
	else{
		setPrefix(Volume_Type::Prefix::None);
	}

	setSystem(Volume_Type::getSystem(type));
	setSymbol();
}

template<typename T_Arithmetic>
void Volume<T_Arithmetic>::setPrefix(Volume_Type::Prefix prefix){ this->prefix_ = prefix; }

template<typename T_Arithmetic>
void Volume<T_Arithmetic>::setSymbol(){
	switch(this->system_){
		case Volume_Type::System::Metric:
			switch (this->type_){
				case Volume_Type::Type::Metre_Cubic:
					switch (this->prefix_){
						case Volume_Type::Prefix::yocto:
							this->symbol_ = "ym^3";
							break;
						case Volume_Type::Prefix::zepto:
							this->symbol_ = "zm^3";
							break;
						case Volume_Type::Prefix::atto:
							this->symbol_ = "am^3";
							break;
						case Volume_Type::Prefix::femto:
							this->symbol_ = "fm^3";
							break;
						case Volume_Type::Prefix::pico:
							this->symbol_ = "pm^3";
							break;
						case Volume_Type::Prefix::nano:
							this->symbol_ = "nm^3";
							break;
						case Volume_Type::Prefix::micro:
							this->symbol_ = "μm^3";
							break;
						case Volume_Type::Prefix::milli:
							this->symbol_ = "mm^3";
							break;
						case Volume_Type::Prefix::centi:
							this->symbol_ = "cm^3";
							break;
						case Volume_Type::Prefix::deci:
							this->symbol_ = "dm^3";
							break;
						case Volume_Type::Prefix::deca:
							this->symbol_ = "dam^3";
							break;
						case Volume_Type::Prefix::hecto:
							this->symbol_ = "hm^3";
							break;
						case Volume_Type::Prefix::kilo:
							this->symbol_ = "km^3";
							break;
						case Volume_Type::Prefix::mega:
							this->symbol_ = "Mm^3";
							break;
						case Volume_Type::Prefix::giga:
							this->symbol_ = "Gm^3";
							break;
						case Volume_Type::Prefix::tera:
							this->symbol_ = "Tm^3";
							break;
						case Volume_Type::Prefix::peta:
							this->symbol_ = "Pm^3";
							break;
						case Volume_Type::Prefix::exa:
							this->symbol_ = "Em^3";
							break;
						case Volume_Type::Prefix::zetta:
							this->symbol_ = "Zm^3";
							break;
						case Volume_Type::Prefix::yotta:
							this->symbol_ = "Ym^3";
							break;
						
						default:
							this->symbol_ = "m^3";
							break;
					}
					break;
				case Volume_Type::Type::Litre:
					switch (this->prefix_){
						case Volume_Type::Prefix::yocto:
							this->symbol_ = "yl";
							break;
						case Volume_Type::Prefix::zepto:
							this->symbol_ = "zl";
							break;
						case Volume_Type::Prefix::atto:
							this->symbol_ = "al";
							break;
						case Volume_Type::Prefix::femto:
							this->symbol_ = "fl";
							break;
						case Volume_Type::Prefix::pico:
							this->symbol_ = "pl";
							break;
						case Volume_Type::Prefix::nano:
							this->symbol_ = "nl";
							break;
						case Volume_Type::Prefix::micro:
							this->symbol_ = "μl";
							break;
						case Volume_Type::Prefix::milli:
							this->symbol_ = "ml";
							break;
						case Volume_Type::Prefix::centi:
							this->symbol_ = "cl";
							break;
						case Volume_Type::Prefix::deci:
							this->symbol_ = "dl";
							break;
						case Volume_Type::Prefix::deca:
							this->symbol_ = "dal";
							break;
						case Volume_Type::Prefix::hecto:
							this->symbol_ = "hl";
							break;
						case Volume_Type::Prefix::kilo:
							this->symbol_ = "kl";
							break;
						case Volume_Type::Prefix::mega:
							this->symbol_ = "Ml";
							break;
						case Volume_Type::Prefix::giga:
							this->symbol_ = "Gl";
							break;
						case Volume_Type::Prefix::tera:
							this->symbol_ = "Tl";
							break;
						case Volume_Type::Prefix::peta:
							this->symbol_ = "Pl";
							break;
						case Volume_Type::Prefix::exa:
							this->symbol_ = "El";
							break;
						case Volume_Type::Prefix::zetta:
							this->symbol_ = "Zl";
							break;
						case Volume_Type::Prefix::yotta:
							this->symbol_ = "Yl";
							break;
						
						default:
							this->symbol_ = "l";
							break;
					}
					break;
				case Volume_Type::Type::Fermi_Cubic:
					this->symbol_ = "fm^3";
					break;
				case Volume_Type::Type::Angstrom_Cubic:
					this->symbol_ = "Å^3";
					break;
				case Volume_Type::Type::Micron_Cubic:
					this->symbol_ = "μm^3";
					break;
				case Volume_Type::Type::Myriametre_Cubic:
                    this->symbol_ = "myriametre^3";
					break;
				case Volume_Type::Type::X_Unit_Cubic:
					this->symbol_ = "xu^3";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Volume_Type::System::Imperial:
			switch(this->type_){
				case Volume_Type::Type::Point_Cubic:
					this->symbol_ = "p^3";
					break;
				case Volume_Type::Type::Pica_Cubic:
					this->symbol_ = "pc^3";
					break;
				case Volume_Type::Type::Thou_Cubic:
					this->symbol_ = "th^3";
					break;
				case Volume_Type::Type::Inch_Cubic:
					this->symbol_ = "in^3";
					break;
				case Volume_Type::Type::Foot_Cubic:
					this->symbol_ = "ft^3";
					break;
				case Volume_Type::Type::Yard_Cubic:
					this->symbol_ = "yd^3";
					break;
				case Volume_Type::Type::Chain_Cubic:
					this->symbol_ = "ch^3";
					break;
				case Volume_Type::Type::Furlong_Cubic:
					this->symbol_ = "fur^3";
					break;
				case Volume_Type::Type::Mile_Cubic:
					this->symbol_ = "mi^3";
					break;
				case Volume_Type::Type::League_Cubic:
					this->symbol_ = "lea^3";
					break;
				case Volume_Type::Type::Fluid_Ounce:
					this->symbol_ = "fl oz";
					break;
				case Volume_Type::Type::Gill:
					this->symbol_ = "gi";
					break;
				case Volume_Type::Type::Pint:
					this->symbol_ = "pt";
					break;
				case Volume_Type::Type::Quart:
					this->symbol_ = "qt";
					break;
				case Volume_Type::Type::Gallon:
					this->symbol_ = "gal";
					break;
				case Volume_Type::Type::Bushel:
					this->symbol_ = "bsh";
					break;
				case Volume_Type::Type::Quarter:
					this->symbol_ = "qr";
					break;
				default:
					this->symbol_ = "";
					break;
			}
			break;
		case Volume_Type::System::US_Customary:
			switch(this->type_){
				case Volume_Type::Type::Survey_Link_Cubic:
					this->symbol_ = "li^3";
					break;
				case Volume_Type::Type::Survey_Inch_Cubic:
					this->symbol_ = "in^3";
					break;
				case Volume_Type::Type::Survey_Foot_Cubic:
					this->symbol_ = "ft^3";
					break;
				case Volume_Type::Type::Rod_Cubic:
					this->symbol_ = "rd^3";
					break;
				case Volume_Type::Type::Survey_Chain_Cubic:
					this->symbol_ = "ch^3";
					break;
				case Volume_Type::Type::Survey_Furlong_Cubic:
					this->symbol_ = "fur^3";
					break;
				case Volume_Type::Type::Survey_Mile_Cubic:
					this->symbol_ = "mi^3";
					break;
				case Volume_Type::Type::Survey_League_Cubic:
					this->symbol_ = "lea^3";
					break;
				case Volume_Type::Type::Survey_Acre_Foot:
					this->symbol_ = "ac-ft";
					break;
				case Volume_Type::Type::Pint:
					this->symbol_ = "pt";
					break;
				case Volume_Type::Type::Quart:
					this->symbol_ = "qt";
					break;
				case Volume_Type::Type::Gallon:
					this->symbol_ = "gal";
					break;
				case Volume_Type::Type::Peck:
					this->symbol_ = "pk";
					break;
				case Volume_Type::Type::US_Bushel:
					this->symbol_ = "bsh";
					break;
				case Volume_Type::Type::Dry_Barrel:
					this->symbol_ = "bbl";
					break;
				case Volume_Type::Type::Minim:
					this->symbol_ = "min";
					break;
				case Volume_Type::Type::US_Fluid_Dram:
					this->symbol_ = "fl dr";
					break;
				case Volume_Type::Type::Teaspoon:
					this->symbol_ = "tsp";
					break;
				case Volume_Type::Type::Tablespoon:
					this->symbol_ = "Tbsp";
					break;
				case Volume_Type::Type::US_Fluid_Ounce:
					this->symbol_ = "fl oz";
					break;
				case Volume_Type::Type::US_Shot:
					this->symbol_ = "jig";
					break;
				case Volume_Type::Type::US_Gill:
					this->symbol_ = "gi";
					break;
				case Volume_Type::Type::US_Cup:
					this->symbol_ = "cp";
					break;
				case Volume_Type::Type::US_Pint:
					this->symbol_ = "pt";
					break;
				case Volume_Type::Type::US_Quart:
					this->symbol_ = "qt";
					break;
				case Volume_Type::Type::US_Pottle:
					this->symbol_ = "pot";
					break;
				case Volume_Type::Type::US_Gallon:
					this->symbol_ = "gal";
					break;
				case Volume_Type::Type::Barrel:
					this->symbol_ = "bbl";
					break;
				case Volume_Type::Type::Oil_Barrel:
					this->symbol_ = "bbl";
					break;
				case Volume_Type::Type::Hogshead:
					this->symbol_ = "hhd";
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
T_Arithmetic Volume<T_Arithmetic>::convertToMetric(Volume_Type::Type type, Volume_Type::Prefix prefix, bool in_place){

	//Obtains the current value converted to Cubic Metres
	double temp_value = convertToBasicUnit(Volume_Type::System::Metric);
	
	//Converts Cubic Metre to the appropriate Metric value
	switch (type){
		case Volume_Type::Type::Metre_Cubic:
			switch (prefix){
				case Volume_Type::Prefix::yocto:
					temp_value *= 1e72;
					break;
				case Volume_Type::Prefix::zepto:
					temp_value *= 1e63;
					break;
				case Volume_Type::Prefix::atto:
					temp_value *= 1e54;
					break;
				case Volume_Type::Prefix::femto:
					temp_value *= 1e45;
					break;
				case Volume_Type::Prefix::pico:
					temp_value *= 1e36;
					break;
				case Volume_Type::Prefix::nano:
					temp_value *= 1e27;
					break;
				case Volume_Type::Prefix::micro:
					temp_value *= 1e18;
					break;
				case Volume_Type::Prefix::milli:
					temp_value *= 1e9;
					break;
				case Volume_Type::Prefix::centi:
					temp_value *= 1e6;
					break;
				case Volume_Type::Prefix::deci:
					temp_value *= 1e3;
					break;
				case Volume_Type::Prefix::deca:
					temp_value *= 1e-3;
					break;
				case Volume_Type::Prefix::hecto:
					temp_value *= 1e-6;
					break;
				case Volume_Type::Prefix::kilo:
					temp_value *= 1e-9;
					break;
				case Volume_Type::Prefix::mega:
					temp_value *= 1e-18;
					break;
				case Volume_Type::Prefix::giga:
					temp_value *= 1e-27;
					break;
				case Volume_Type::Prefix::tera:
					temp_value *= 1e-36;
					break;
				case Volume_Type::Prefix::peta:
					temp_value *= 1e-45;
					break;
				case Volume_Type::Prefix::exa:
					temp_value *= 1e-54;
					break;
				case Volume_Type::Prefix::zetta:
					temp_value *= 1e-63;
					break;
				case Volume_Type::Prefix::yotta:
					temp_value *= 1e-72;
					break;
				
				default:
					break;
			}
			break;
		case Volume_Type::Type::Litre:
			switch (prefix){
                case Volume_Type::Prefix::yocto:
					temp_value *= 1e27;
					break;
                case Volume_Type::Prefix::zepto:
					temp_value *= 1e24;
					break;
                case Volume_Type::Prefix::atto:
					temp_value *= 1e21;
					break;
                case Volume_Type::Prefix::femto:
					temp_value *= 1e18;
					break;
                case Volume_Type::Prefix::pico:
					temp_value *= 1e15;
					break;
                case Volume_Type::Prefix::nano:
					temp_value *= 1e12;
					break;
                case Volume_Type::Prefix::micro:
					temp_value *= 1e9;
					break;
                case Volume_Type::Prefix::milli:
					temp_value *= 1e6;
					break;
                case Volume_Type::Prefix::centi:
					temp_value *= 1e5;
					break;
                case Volume_Type::Prefix::deci:
					temp_value *= 1e4;
					break;
                case Volume_Type::Prefix::deca:
					temp_value *= 1e2;
					break;
                case Volume_Type::Prefix::hecto:
					temp_value *= 1e1;
					break;
                case Volume_Type::Prefix::kilo:
					break;
                case Volume_Type::Prefix::mega:
					temp_value *= 1e-3;
					break;
                case Volume_Type::Prefix::giga:
					temp_value *= 1e-6;
					break;
                case Volume_Type::Prefix::tera:
					temp_value *= 1e-9;
					break;
                case Volume_Type::Prefix::peta:
					temp_value *= 1e-12;
					break;
                case Volume_Type::Prefix::exa:
					temp_value *= 1e-15;
					break;
                case Volume_Type::Prefix::zetta:
					temp_value *= 1e-18;
					break;
                case Volume_Type::Prefix::yotta:
					temp_value *= 1e-21;
                    break;
				
				default:
					temp_value *= 1e3;
					break;
			}
		case Volume_Type::Type::Fermi_Cubic:
			temp_value *= 1e45;
			prefix = Volume_Type::Prefix::None;
			break;
		case Volume_Type::Type::Angstrom_Cubic:
			temp_value *= 1e30;
			prefix = Volume_Type::Prefix::None;
			break;
		case Volume_Type::Type::Micron_Cubic:
			temp_value *= 1e18;
			prefix = Volume_Type::Prefix::None;
			break;
		case Volume_Type::Type::Myriametre_Cubic:
			temp_value *= 1e-12;
			prefix = Volume_Type::Prefix::None;
			break;
		case Volume_Type::Type::X_Unit_Cubic:
			temp_value *= 1e39;
			prefix = Volume_Type::Prefix::None;
			break;
		default:
			prefix = Volume_Type::Prefix::None;
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Volume_Type::System::Metric;
		this->type_ = type;
		this->prefix_ = prefix;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Volume<T_Arithmetic>::convertToImperial(Volume_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Cubic Feet
	double temp_value = convertToBasicUnit(Volume_Type::System::Imperial);

	//Converts Cubic Feet to the appropriate Imperial value
	switch(type){
		case Volume_Type::Type::Point_Cubic:
			temp_value *= 644972544.0;
			break;
		case Volume_Type::Type::Pica_Cubic:
			temp_value *= 373248.0;
			break;
		case Volume_Type::Type::Thou_Cubic:
			temp_value *= 1728000000000.0;
			break;
		case Volume_Type::Type::Inch_Cubic:
			temp_value *= 1728.0;
			break;
		case Volume_Type::Type::Yard_Cubic:
			temp_value /= 27.0;
			break;
		case Volume_Type::Type::Chain_Cubic:
			temp_value /= 287496.0;
			break;
		case Volume_Type::Type::Furlong_Cubic:
			temp_value /= 287496000.0;
			break;
		case Volume_Type::Type::Mile_Cubic:
			temp_value /= 147197952000.0;
			break;
		case Volume_Type::Type::League_Cubic:
			temp_value /= 3974344704000.0;
			break;
		case Volume_Type::Type::Fluid_Ounce:
			temp_value *= 996.613673447;
			break;
		case Volume_Type::Type::Gill:
			temp_value *= 199.3227346894;
			break;
		case Volume_Type::Type::Pint:
			temp_value *= 49.83068367235;
			break;
		case Volume_Type::Type::Quart:
			temp_value *= 24.915341836175;
			break;
		case Volume_Type::Type::Gallon:
			temp_value *= 6.22883545904375;
			break;
		case Volume_Type::Type::Bushel:
			temp_value *= 0.7786044323804688;
			break;
		case Volume_Type::Type::Quarter:
			temp_value *= 0.0973255540475586;
			break;
		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Volume_Type::System::Imperial;
		this->type_ = type;
		this->prefix_ = Volume_Type::Prefix::None;
		setSymbol();
	}
	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
T_Arithmetic Volume<T_Arithmetic>::convertToUSCustomary(Volume_Type::Type type, bool in_place){
	
	//Obtains the current value converted to Cubic Survey Feet
	double temp_value = convertToBasicUnit(Volume_Type::System::US_Customary);

	//Converts Cubic Survey Feet to the appropriate US Customary value
	switch(type){
		case Volume_Type::Type::Survey_Link_Cubic:
			temp_value /= (3597.0 / 166375.0);
			break;
		case Volume_Type::Type::Survey_Inch_Cubic:
			temp_value *= 1728.0;
			break;
		case Volume_Type::Type::Rod_Cubic:
			temp_value /= 4492.125;
			break;
		case Volume_Type::Type::Survey_Chain_Cubic:
			temp_value /= 287496.0;
			break;
		case Volume_Type::Type::Survey_Furlong_Cubic:
			temp_value /= 287496000.0;
			break;
		case Volume_Type::Type::Survey_Mile_Cubic:
			temp_value /= 147197952000.0;
			break;
		case Volume_Type::Type::Survey_League_Cubic:
			temp_value /= 3974344704000.0;
			break;
		case Volume_Type::Type::Survey_Acre_Foot:
			temp_value /= 43560.0;
			break;
		case Volume_Type::Type::US_Dry_Pint:
			temp_value *= 51.42809311669348;
			break;
		case Volume_Type::Type::US_Dry_Quart:
			temp_value *= 25.71404655834674;
			break;
		case Volume_Type::Type::US_Dry_Gallon:
			temp_value *= 6.428511639586685;
			break;
		case Volume_Type::Type::Peck:
			temp_value *= 3.214255819793343;
			break;
		case Volume_Type::Type::US_Bushel:
			temp_value /= 1.244456018518519;
			break;
		case Volume_Type::Type::Dry_Barrel:
			temp_value /= 4.083333333333333;
			break;
		case Volume_Type::Type::Minim:
			temp_value *= 459603.11688336;
			break;
		case Volume_Type::Type::US_Fluid_Dram:
			temp_value *= 7660.051948056;
			break;
		case Volume_Type::Type::Teaspoon:
			temp_value *= 5745.038961042;
			break;
		case Volume_Type::Type::Tablespoon:
			temp_value *= 1915.012987014;
			break;
		case Volume_Type::Type::US_Fluid_Ounce:
			temp_value *= 957.506493507;
			break;
		case Volume_Type::Type::US_Shot:
			temp_value *= 638.337662338;
			break;
		case Volume_Type::Type::US_Gill:
			temp_value *= 239.37662337675;
			break;
		case Volume_Type::Type::US_Cup:
			temp_value *= 119.688311688375;
			break;
		case Volume_Type::Type::US_Pint:
			temp_value *= 59.8441558441875;
			break;
		case Volume_Type::Type::US_Quart:
			temp_value *= 29.92207792209375;
			break;
		case Volume_Type::Type::US_Pottle:
			temp_value *= 14.96103896104688;
			break;
		case Volume_Type::Type::US_Gallon:
			temp_value *= 7.480519480523438;
			break;
		case Volume_Type::Type::Barrel:
			temp_value /= 4.210937499997773;
			break;
		case Volume_Type::Type::Oil_Barrel:
			temp_value /= 5.614583333330363;
			break;
		case Volume_Type::Type::Hogshead:
			temp_value /= 8.421874999995545;
			break;
		default:
			break;
	}

	//If the conversion is meant to be in place, change all the appropriate values
	if(in_place){
		this->value_ = static_cast<T_Arithmetic>(temp_value);
		this->system_ = Volume_Type::System::US_Customary;
		this->type_ = type;
		this->prefix_ = Volume_Type::Prefix::None;
		setSymbol();
	}

	return static_cast<T_Arithmetic>(temp_value);

}

template<typename T_Arithmetic>
double Volume<T_Arithmetic>::convertToBasicUnit(Volume_Type::System system){

	double temp_value = static_cast<double>(this->value_);

	//Convert to the basic unit of each system
	switch(this->system_){
		//Converts all metric units to Cubic Metre
		case Volume_Type::System::Metric:
			switch (this->type_){
				case Volume_Type::Type::Metre_Cubic:
                    switch (this->prefix_){
						case Volume_Type::Prefix::yocto:
							temp_value *= 1e-72;
							break;
						case Volume_Type::Prefix::zepto:
							temp_value *= 1e-63;
							break;
						case Volume_Type::Prefix::atto:
							temp_value *= 1e-54;
							break;
						case Volume_Type::Prefix::femto:
							temp_value *= 1e-45;
							break;
						case Volume_Type::Prefix::pico:
							temp_value *= 1e-36;
							break;
						case Volume_Type::Prefix::nano:
							temp_value *= 1e-27;
							break;
						case Volume_Type::Prefix::micro:
							temp_value *= 1e-18;
							break;
						case Volume_Type::Prefix::milli:
							temp_value *= 1e-9;
							break;
						case Volume_Type::Prefix::centi:
							temp_value *= 1e-6;
							break;
						case Volume_Type::Prefix::deci:
							temp_value *= 1e-3;
							break;
						case Volume_Type::Prefix::deca:
							temp_value *= 1e3;
							break;
						case Volume_Type::Prefix::hecto:
							temp_value *= 1e6;
							break;
						case Volume_Type::Prefix::kilo:
							temp_value *= 1e9;
							break;
						case Volume_Type::Prefix::mega:
							temp_value *= 1e18;
							break;
						case Volume_Type::Prefix::giga:
							temp_value *= 1e27;
							break;
						case Volume_Type::Prefix::tera:
							temp_value *= 1e36;
							break;
						case Volume_Type::Prefix::peta:
							temp_value *= 1e45;
							break;
						case Volume_Type::Prefix::exa:
							temp_value *= 1e54;
							break;
						case Volume_Type::Prefix::zetta:
							temp_value *= 1e63;
							break;
						case Volume_Type::Prefix::yotta:
							temp_value *= 1e72;
							break;
						default:
							break;
					}
					break;
				case Volume_Type::Type::Litre:
                    switch (this->prefix_){
                        case Volume_Type::Prefix::yocto:
							temp_value *= 1e-27;
							break;
                        case Volume_Type::Prefix::zepto:
							temp_value *= 1e-24;
							break;
                        case Volume_Type::Prefix::atto:
							temp_value *= 1e-21;
							break;
                        case Volume_Type::Prefix::femto:
							temp_value *= 1e-18;
							break;
                        case Volume_Type::Prefix::pico:
							temp_value *= 1e-15;
							break;
                        case Volume_Type::Prefix::nano:
							temp_value *= 1e-12;
							break;
                        case Volume_Type::Prefix::micro:
							temp_value *= 1e-9;
							break;
                        case Volume_Type::Prefix::milli:
							temp_value *= 1e-6;
							break;
                        case Volume_Type::Prefix::centi:
							temp_value *= 1e-5;
							break;
                        case Volume_Type::Prefix::deci:
							temp_value *= 1e-4;
							break;
                        case Volume_Type::Prefix::deca:
							temp_value *= 1e-2;
							break;
                        case Volume_Type::Prefix::hecto:
							temp_value *= 1e-1;
							break;
                        case Volume_Type::Prefix::kilo:
							break;
                        case Volume_Type::Prefix::mega:
							temp_value *= 1e3;
							break;
                        case Volume_Type::Prefix::giga:
							temp_value *= 1e6;
							break;
                        case Volume_Type::Prefix::tera:
							temp_value *= 1e9;
							break;
                        case Volume_Type::Prefix::peta:
							temp_value *= 1e12;
							break;
                        case Volume_Type::Prefix::exa:
							temp_value *= 1e15;
							break;
                        case Volume_Type::Prefix::zetta:
							temp_value *= 1e18;
							break;
                        case Volume_Type::Prefix::yotta:
							temp_value *= 1e21;
							break;
						default:
							temp_value *= 1e-3;
							break;
					}
					break;
				case Volume_Type::Type::Fermi_Cubic:
					temp_value *= 1e-45;
					break;
				case Volume_Type::Type::Angstrom_Cubic:
					temp_value *= 1e-30;
					break;
				case Volume_Type::Type::Micron_Cubic:
					temp_value *= 1e-18;
					break;
				case Volume_Type::Type::Myriametre_Cubic:
					temp_value *= 1e12;
					break;
				case Volume_Type::Type::X_Unit_Cubic:
					temp_value *= 1e-39;
					break;
				default:
					break;
			}
			break;
		//Converts all Imperial units to Cubic Feet
		case Volume_Type::System::Imperial:
			switch(this->type_){
				case Volume_Type::Type::Point_Cubic:
					temp_value /= 644972544.0;
					break;
				case Volume_Type::Type::Pica_Cubic:
					temp_value /= 373248.0;
					break;
				case Volume_Type::Type::Thou_Cubic:
					temp_value /= 1728000000000.0;
					break;
				case Volume_Type::Type::Inch_Cubic:
					temp_value /= 1728.0;
					break;
				case Volume_Type::Type::Yard_Cubic:
					temp_value *= 27.0;
					break;
				case Volume_Type::Type::Chain_Cubic:
					temp_value *= 287496.0;
					break;
				case Volume_Type::Type::Furlong_Cubic:
					temp_value *= 287496000.0;
					break;
				case Volume_Type::Type::Mile_Cubic:
					temp_value *= 147197952000.0;
					break;
				case Volume_Type::Type::League_Cubic:
					temp_value *= 3974344704000.0;
					break;
				case Volume_Type::Type::Fluid_Ounce:
					temp_value /= 996.613673447;
					break;
				case Volume_Type::Type::Gill:
					temp_value /= 199.3227346894;
					break;
				case Volume_Type::Type::Pint:
					temp_value /= 49.83068367235;
					break;
				case Volume_Type::Type::Quart:
					temp_value /= 24.915341836175;
					break;
				case Volume_Type::Type::Gallon:
					temp_value /= 6.22883545904375;
					break;
				case Volume_Type::Type::Bushel:
					temp_value /= 0.7786044323804688;
					break;
				case Volume_Type::Type::Quarter:
					temp_value /= 0.0973255540475586;
					break;
				default:
					break;
			}
			break;
		//Converts all US_Customary units to Cubic Survey Feet
		case Volume_Type::System::US_Customary:
			switch(this->type_){
				case Volume_Type::Type::Survey_Link_Cubic:
					temp_value *= (3597.0 / 166375.0);
					break;
				case Volume_Type::Type::Survey_Inch_Cubic:
					temp_value /= 1728.0;
					break;
				case Volume_Type::Type::Rod_Cubic:
					temp_value *= 4492.125;
					break;
				case Volume_Type::Type::Survey_Chain_Cubic:
					temp_value *= 287496.0;
					break;
				case Volume_Type::Type::Survey_Furlong_Cubic:
					temp_value *= 287496000.0;
					break;
				case Volume_Type::Type::Survey_Mile_Cubic:
					temp_value *= 147197952000.0;
					break;
				case Volume_Type::Type::Survey_League_Cubic:
					temp_value *= 3974344704000.0;
					break;
				case Volume_Type::Type::Survey_Acre_Foot:
					temp_value *= 43560.0;
					break;
				case Volume_Type::Type::US_Dry_Pint:
					temp_value /= 51.42809311669348;
					break;
				case Volume_Type::Type::US_Dry_Quart:
					temp_value /= 25.71404655834674;
					break;
				case Volume_Type::Type::US_Dry_Gallon:
					temp_value /= 6.428511639586685;
					break;
				case Volume_Type::Type::Peck:
					temp_value /= 3.214255819793343;
					break;
				case Volume_Type::Type::US_Bushel:
					temp_value *= 1.244456018518519;
					break;
				case Volume_Type::Type::Dry_Barrel:
					temp_value *= 4.083333333333333;
					break;
				case Volume_Type::Type::Minim:
					temp_value /= 459603.11688336;
					break;
				case Volume_Type::Type::US_Fluid_Dram:
					temp_value /= 7660.051948056;
					break;
				case Volume_Type::Type::Teaspoon:
					temp_value /= 5745.038961042;
					break;
				case Volume_Type::Type::Tablespoon:
					temp_value /= 1915.012987014;
					break;
				case Volume_Type::Type::US_Fluid_Ounce:
					temp_value /= 957.506493507;
					break;
				case Volume_Type::Type::US_Shot:
					temp_value /= 638.337662338;
					break;
				case Volume_Type::Type::US_Gill:
					temp_value /= 239.37662337675;
					break;
				case Volume_Type::Type::US_Cup:
					temp_value /= 119.688311688375;
					break;
				case Volume_Type::Type::US_Pint:
					temp_value /= 59.8441558441875;
					break;
				case Volume_Type::Type::US_Quart:
					temp_value /= 29.92207792209375;
					break;
				case Volume_Type::Type::US_Pottle:
					temp_value /= 14.96103896104688;
					break;
				case Volume_Type::Type::US_Gallon:
					temp_value /= 7.480519480523438;
					break;
				case Volume_Type::Type::Barrel:
					temp_value *= 4.210937499997773;
					break;
				case Volume_Type::Type::Oil_Barrel:
					temp_value *= 5.614583333330363;
					break;
				case Volume_Type::Type::Hogshead:
					temp_value *= 8.421874999995545;
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
		case Volume_Type::System::Metric:
			if(system == Volume_Type::System::Imperial){
				//Convert cubic metres to cubic feet
				temp_value /= 0.028316846592;
			}
			else if(system == Volume_Type::System::US_Customary){
				//Convert cubic metres to cubic survey feet
				temp_value /= 0.028318518879638616;
			}
			break;
		case Volume_Type::System::Imperial:
			if(system == Volume_Type::System::Metric){
				//Convert cubic feet to cubic metres
				temp_value *= 0.028316846592;
			}
			else if(system == Volume_Type::System::US_Customary){
				//Convert cubic feet to cubic survey feet
				temp_value *= 0.999994;
			}
            break;
		case Volume_Type::System::US_Customary:
			if(system == Volume_Type::System::Metric){
				//Convert cubic survey feet to cubic metres
				temp_value *= 0.028318518879638616;
			}
			else if(system == Volume_Type::System::Imperial){
				//Convert cubic survey feet to cubic feet
				temp_value /= 0.999994;
			}
			break;
		default:
			std::cerr << "Unknown System";
			break;
	}

	return temp_value;
}

};

#endif //__VOLUME_TCC__
