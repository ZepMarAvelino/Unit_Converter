#ifndef __MASS_HPP__
#define __MASS_HPP__

#include <iostream>
#include <string>
#include <type_traits>

#include "Mass_Type.hpp"
#include "Unit.hpp"

namespace afzm{

//Mass Class - Inherits Unit
// - Uses Mass_Type struct
template<typename T_Arithmetic>
class Mass : public Unit<T_Arithmetic> {
/**
 * @brief Ensures that the template type is either Integral or Floating-point
 */
static_assert(std::is_arithmetic<T_Arithmetic>::value, "Type must be integral or floating-point");

protected:
	Mass_Type::System system_;
	Mass_Type::Type type_;
	Mass_Type::Prefix prefix_;

public:
	Mass();
	Mass(T_Arithmetic value);
	Mass(T_Arithmetic value, Mass_Type::Type type, Mass_Type::Prefix prefix = Mass_Type::Prefix::None);
	Mass(T_Arithmetic value, std::string name);
	Mass(T_Arithmetic value, Mass_Type::Type type, std::string name);
	Mass(T_Arithmetic value, Mass_Type::Type type, Mass_Type::Prefix prefix, std::string name);
	Mass(std::string name);
	Mass(Mass_Type::Type type, std::string name);
	Mass(Mass_Type::Type type, Mass_Type::Prefix prefix, std::string name);
	Mass(Mass_Type::Type type, Mass_Type::Prefix prefix = Mass_Type::Prefix::None);
	virtual ~Mass();

	// virtual void setValue(T_Arithmetic value);
    // virtual void setName(std::string name);
	
    virtual void changeType(std::string type, std::string prefix = "None");
	virtual void changeType(Mass_Type::Type type, Mass_Type::Prefix prefix = Mass_Type::Prefix::None);

	// virtual T_Arithmetic getValue() const;
	// virtual std::string getSymbol() const;
    // virtual std::string getName() const;

	virtual Mass_Type::System getSystem() const;
	virtual Mass_Type::Type getType() const;
	virtual Mass_Type::Prefix getPrefix() const;
	virtual std::string getSystemName() const;
	virtual std::string getTypeName() const;
    virtual std::string getPrefixName() const;
    virtual std::string getTypeWPrefixName() const;

    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE);

    virtual T_Arithmetic convertTo(Mass_Type::Type type, bool in_place);
    virtual T_Arithmetic convertTo(Mass_Type::Type type, Mass_Type::Prefix prefix = Mass_Type::Prefix::None, bool in_place = false);

protected:
    virtual void setSystem(Mass_Type::System system);
    virtual void setType(Mass_Type::Type type, Mass_Type::Prefix prefix = Mass_Type::Prefix::None);
	virtual void setPrefix(Mass_Type::Prefix prefix);
	virtual void setSymbol();

	T_Arithmetic convertToMetric(Mass_Type::Type type, Mass_Type::Prefix prefix, bool in_place = false);
	T_Arithmetic convertToImperial(Mass_Type::Type type, bool in_place = false);
	T_Arithmetic convertToUSCustomary(Mass_Type::Type type, bool in_place = false);
	
	double convertToBasicUnit(Mass_Type::System system);

private:
};

};

#include "Mass.tcc"

#endif //__MASS_HPP__
