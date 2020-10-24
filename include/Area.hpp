#ifndef __AREA_HPP__
#define __AREA_HPP__

#include <iostream>
#include <string>
#include <type_traits>

#include "Area_Type.hpp"
#include "Unit.hpp"

namespace afzm{

//Area Class - Inherits Unit
// - Uses Area_Type struct
template<typename T_Arithmetic>
class Area : public Unit<T_Arithmetic> {
/**
 * @brief Ensures that the template type is either Integral or Floating-point
 */
static_assert(std::is_arithmetic<T_Arithmetic>::value, "Type must be integral or floating-point");

protected:
	Area_Type::System system_;
	Area_Type::Type type_;
	Area_Type::Prefix prefix_;

public:
	Area();
	Area(T_Arithmetic value);
	Area(T_Arithmetic value, Area_Type::Type type, Area_Type::Prefix prefix = Area_Type::Prefix::None);
	Area(T_Arithmetic value, std::string name);
	Area(T_Arithmetic value, Area_Type::Type type, std::string name);
	Area(T_Arithmetic value, Area_Type::Type type, Area_Type::Prefix prefix, std::string name);
	Area(std::string name);
	Area(Area_Type::Type type, std::string name);
	Area(Area_Type::Type type, Area_Type::Prefix prefix, std::string name);
	Area(Area_Type::Type type, Area_Type::Prefix prefix = Area_Type::Prefix::None);
	virtual ~Area();


    virtual void changeType(std::string type, std::string prefix = "None");
	virtual void changeType(Area_Type::Type type, Area_Type::Prefix prefix = Area_Type::Prefix::None);


	virtual Area_Type::System getSystem() const;
	virtual Area_Type::Type getType() const;
	virtual Area_Type::Prefix getPrefix() const;
	virtual std::string getSystemName() const;
	virtual std::string getTypeName() const;
    virtual std::string getPrefixName() const;
    virtual std::string getTypeWPrefixName() const;


    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE);

    virtual T_Arithmetic convertTo(Area_Type::Type type, bool in_place);
    virtual T_Arithmetic convertTo(Area_Type::Type type, Area_Type::Prefix prefix = Area_Type::Prefix::None, bool in_place = false);

protected:
    virtual void setSystem(Area_Type::System system);
    virtual void setType(Area_Type::Type type, Area_Type::Prefix prefix = Area_Type::Prefix::None);
	virtual void setPrefix(Area_Type::Prefix prefix);
	virtual void setSymbol();

	T_Arithmetic convertToMetric(Area_Type::Type type, Area_Type::Prefix prefix, bool in_place = false);
	T_Arithmetic convertToImperial(Area_Type::Type type, bool in_place = false);
	T_Arithmetic convertToUSCustomary(Area_Type::Type type, bool in_place = false);
	
	double convertToBasicUnit(Area_Type::System system);

private:
};

};

#include "Area.tcc"

#endif //__AREA_HPP__
