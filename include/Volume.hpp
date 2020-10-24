#ifndef __VOLUME_HPP__
#define __VOLUME_HPP__

#include <iostream>
#include <string>
#include <type_traits>

#include "Unit.hpp"
#include "Volume_Type.hpp"

namespace afzm{

//Volume Class - Inherits Unit
// - Uses Volume_Type struct
template<typename T_Arithmetic>
class Volume : public Unit<T_Arithmetic> {
/**
 * @brief Ensures that the template type is either Integral or Floating-point
 */
static_assert(std::is_arithmetic<T_Arithmetic>::value, "Type must be integral or floating-point");

protected:
	Volume_Type::System system_;
	Volume_Type::Type type_;
	Volume_Type::Prefix prefix_;

public:
	Volume();
	Volume(T_Arithmetic value);
	Volume(T_Arithmetic value, Volume_Type::Type type, Volume_Type::Prefix prefix = Volume_Type::Prefix::None);
	Volume(T_Arithmetic value, std::string name);
	Volume(T_Arithmetic value, Volume_Type::Type type, std::string name);
	Volume(T_Arithmetic value, Volume_Type::Type type, Volume_Type::Prefix prefix, std::string name);
	Volume(std::string name);
	Volume(Volume_Type::Type type, std::string name);
	Volume(Volume_Type::Type type, Volume_Type::Prefix prefix, std::string name);
	Volume(Volume_Type::Type type, Volume_Type::Prefix prefix = Volume_Type::Prefix::None);
	virtual ~Volume();

	// virtual void setValue(T_Arithmetic value);
    // virtual void setName(std::string name);
    virtual void changeType(std::string type, std::string prefix = "None");
	virtual void changeType(Volume_Type::Type type, Volume_Type::Prefix prefix = Volume_Type::Prefix::None);

	// virtual T_Arithmetic getValue() const;
	// virtual std::string getSymbol() const;
    // virtual std::string getName() const;

	virtual Volume_Type::System getSystem() const;
	virtual Volume_Type::Type getType() const;
	virtual Volume_Type::Prefix getPrefix() const;
	virtual std::string getSystemName() const;
	virtual std::string getTypeName() const;
    virtual std::string getPrefixName() const;
    virtual std::string getTypeWPrefixName() const;

    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE);

    virtual T_Arithmetic convertTo(Volume_Type::Type type, bool in_place);
    virtual T_Arithmetic convertTo(Volume_Type::Type type, Volume_Type::Prefix prefix = Volume_Type::Prefix::None, bool in_place = false);

protected:
    virtual void setSystem(Volume_Type::System system);
    virtual void setType(Volume_Type::Type type, Volume_Type::Prefix prefix = Volume_Type::Prefix::None);
	virtual void setPrefix(Volume_Type::Prefix prefix);
	virtual void setSymbol();

	T_Arithmetic convertToMetric(Volume_Type::Type type, Volume_Type::Prefix prefix, bool in_place = false);
	T_Arithmetic convertToImperial(Volume_Type::Type type, bool in_place = false);
	T_Arithmetic convertToUSCustomary(Volume_Type::Type type, bool in_place = false);
	
	double convertToBasicUnit(Volume_Type::System system);

private:
};

};

#include "Volume.tcc"

#endif //__VOLUME_HPP__
