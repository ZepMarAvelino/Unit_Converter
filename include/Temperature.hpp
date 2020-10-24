#ifndef __TEMPERATURE_HPP__
#define __TEMPERATURE_HPP__

#include <iostream>
#include <string>
#include <type_traits>

#include "Temperature_Type.hpp"
#include "Unit.hpp"

namespace afzm{

//Celsius Scale limits
#define C_ABSZERO -237.15
#define C_PLANCKS 1.417e+32
//Kelvin Scale limits
#define K_ABSZERO 0
#define K_PLANCKS 1.417e+32
//Fahrenheit Scale limits
#define F_ABSZERO -459.67
#define F_PLANCKS 2.55e+32
//Rankine Scale limits
#define R_ABSZERO 0
#define R_PLANCKS 2.55e+32
//Delisle Scale limits
#define DE_ABSZERO 559.73
#define DE_PLANCKS -2.1255e+32
//Newton Scale limits
#define N_ABSZERO -90.14
#define N_PLANCKS 4.6761e+31
//Reaumur Scale limits
#define RE_ABSZERO -218.52
#define RE_PLANCKS 1.1336e+32
//Romer Scale limits
#define RO_ABSZERO -135.9
#define RO_PLANCKS 7.43925e+31


//Temperature Class - Inherits Unit
// - Uses Temperature_Type struct
template<typename T_Arithmetic>
class Temperature :	public Unit<T_Arithmetic> {
/**
 * @brief Ensures that the template type is either Integral or Floating-point
 */
static_assert(std::is_arithmetic<T_Arithmetic>::value, "Type must be integral or floating-point");

protected:
	Temperature_Type::System system_;
	Temperature_Type::Type type_;
	Temperature_Type::Prefix prefix_;

public:
	Temperature();
	Temperature(T_Arithmetic value);
	Temperature(T_Arithmetic value, Temperature_Type::Type type);
	Temperature(T_Arithmetic value, std::string name);
	Temperature(T_Arithmetic value, Temperature_Type::Type type, std::string name);
	Temperature(std::string name);
	Temperature(Temperature_Type::Type type, std::string name);
	Temperature(Temperature_Type::Type type);
	virtual ~Temperature();

    virtual void changeType(std::string type, std::string prefix = "None");
	virtual void changeType(Temperature_Type::Type type);

	virtual Temperature_Type::System getSystem() const;
	virtual Temperature_Type::Type getType() const;
	virtual Temperature_Type::Prefix getPrefix() const;
    virtual std::string getSystemName() const;
	virtual std::string getTypeName() const;
    virtual std::string getPrefixName() const;
    virtual std::string getTypeWPrefixName() const;

    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE);

    virtual T_Arithmetic convertTo(Temperature_Type::Type type, bool in_place = false);

protected:
    virtual void setSystem(Temperature_Type::System system);
    virtual void setType(Temperature_Type::Type type);
	virtual void setPrefix(Temperature_Type::Prefix prefix);
	virtual void setSymbol();

private:
	T_Arithmetic convertFromC(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromK(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromF(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromR(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromDe(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromN(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromRe(Temperature_Type::Type type, bool in_place);
	T_Arithmetic convertFromRo(Temperature_Type::Type type, bool in_place);
};

};

#include "Temperature.tcc"

#endif
