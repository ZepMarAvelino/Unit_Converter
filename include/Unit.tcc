#ifndef __UNIT_TCC__
#define __UNIT_TCC__

//Used for development
#ifndef __UNIT_HPP__
#include "Unit.hpp"
#endif

namespace afzm{

template<typename T_Arithmetic>
void Unit<T_Arithmetic>::setValue(T_Arithmetic value){ this->value_ = value; }

template<typename T_Arithmetic>
void Unit<T_Arithmetic>::setName(std::string name){ this->name_ = name;}


template<typename T_Arithmetic>
T_Arithmetic Unit<T_Arithmetic>::getValue() const{ return this->value_; }

template<typename T_Arithmetic>
std::string Unit<T_Arithmetic>::getSymbol() const{ return this->symbol_; }

template<typename T_Arithmetic>
std::string Unit<T_Arithmetic>::getName() const{ return this->name_; }

};

#endif //__UNIT_TCC__