#ifndef __LENGTH_HPP__
#define __LENGTH_HPP__

#include <iostream>
#include <string>
#include <type_traits>

#include "Length_Type.hpp"
#include "Unit.hpp"


namespace afzm{

//Length Class - Inherits Unit
// - Uses Length_Type struct
template<typename T_Arithmetic>
class Length : public Unit<T_Arithmetic> {
/**
 * @brief Ensures that the template type is either Integral or Floating-point
 */
static_assert(std::is_arithmetic<T_Arithmetic>::value, "Type must be integral or floating-point");

protected:
	Length_Type::System system_;
	Length_Type::Type type_;
	Length_Type::Prefix prefix_;

public:
	Length();
	Length(T_Arithmetic value);
	Length(T_Arithmetic value, Length_Type::Type type, Length_Type::Prefix prefix = Length_Type::Prefix::None);
	Length(T_Arithmetic value, std::string name);
	Length(T_Arithmetic value, Length_Type::Type type, std::string name);
	Length(T_Arithmetic value, Length_Type::Type type, Length_Type::Prefix prefix, std::string name);
	Length(std::string name);
	Length(Length_Type::Type type, std::string name);
	Length(Length_Type::Type type, Length_Type::Prefix prefix, std::string name);
	Length(Length_Type::Type type, Length_Type::Prefix prefix = Length_Type::Prefix::None);
	virtual ~Length();

    virtual void changeType(std::string type, std::string prefix = "None");
	virtual void changeType(Length_Type::Type type, Length_Type::Prefix prefix = Length_Type::Prefix::None);

	virtual Length_Type::System getSystem() const;
	virtual Length_Type::Type getType() const;
	virtual Length_Type::Prefix getPrefix() const;
	virtual std::string getSystemName() const;
	virtual std::string getTypeName() const;
    virtual std::string getPrefixName() const;
    virtual std::string getTypeWPrefixName() const;


    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE);
    virtual T_Arithmetic convertTo(Length_Type::Type type, bool in_place);
    virtual T_Arithmetic convertTo(Length_Type::Type type, Length_Type::Prefix prefix = Length_Type::Prefix::None, bool in_place = false);

protected:
    virtual void setSystem(Length_Type::System system);
    virtual void setType(Length_Type::Type type, Length_Type::Prefix prefix = Length_Type::Prefix::None);
	virtual void setPrefix(Length_Type::Prefix prefix);
	virtual void setSymbol();

	T_Arithmetic convertToMetric(Length_Type::Type type, Length_Type::Prefix prefix, bool in_place = false);
	T_Arithmetic convertToImperial(Length_Type::Type type, bool in_place = false);
	T_Arithmetic convertToUSCustomary(Length_Type::Type type, bool in_place = false);
	
	double convertToBasicUnit(Length_Type::System system);

private:
};

};

#include "Length.tcc"

#endif //__LENGTH_HPP__
