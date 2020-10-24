#ifndef __UNIT_H__
#define __UNIT_H__

#include <iostream>
#include <string>
#include <type_traits>

namespace afzm{

enum class Conversion_Type{NONE, IN_PLACE, TARGET, BOTH};

template <typename T_Arithmetic>
class Unit
{

protected:
	T_Arithmetic value_;
	std::string symbol_;
    std::string name_;

public:
	virtual void setValue(T_Arithmetic value);
    virtual void setName(std::string name);

    virtual void changeType(std::string type, std::string prefix = "None") = 0;

    virtual T_Arithmetic convertTo(Unit<T_Arithmetic>* target, Conversion_Type data_edit = Conversion_Type::NONE) = 0;

    virtual T_Arithmetic getValue() const;
	virtual std::string getSymbol() const;
    virtual std::string getName() const;

    virtual std::string getSystemName() const = 0;
    virtual std::string getTypeName() const = 0;
    virtual std::string getPrefixName() const = 0;
    virtual std::string getTypeWPrefixName() const = 0;


protected:
	virtual void setSymbol() = 0;

};

};

#include "Unit.tcc"

#endif //__UNIT_H__
