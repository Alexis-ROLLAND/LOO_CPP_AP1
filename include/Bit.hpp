#ifndef __BIT_H__
#define	__BIT_H__

#include <cstdint>
#include <string>
#include <iostream>

class Bit{
	public:
	enum class bit_t:std::int8_t {SET,CLEAR,HIZ,X};		// enum as imbricated class
	
	private:
	bit_t	Value;		// bit value, only attribute.
	
	public:
	
	Bit():Value{bit_t::X}{};						// Default Ctor - Value is set to 'X'
	Bit(bit_t InitialValue):Value{InitialValue}{};	// Ctor with initial bit value
	virtual ~Bit(){};								// Trivial Dtor
	
	bit_t	getValue() const {return this->Value;};		// getter for the bit value - callable with const bit type
	std::string	toString() const;					// toString "classic" method - callable with const bit type
	
	void	set(){this->Value=bit_t::SET;};			// set to SET
	void	clear(){this->Value=bit_t::CLEAR;};		// set to CLEAR
	void	unregister(){this->Value=bit_t::X;};	// set to X
	void	disconnect(){this->Value=bit_t::HIZ;};	// set to HIZ

};

std::ostream& operator<<(std::ostream& os, const Bit& bit);

#endif

