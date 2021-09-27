#include "Converter.hpp"
#include <cmath>
#include <iomanip>

Converter::Converter() {
	_pseudoLiterals[0] = "-inff";
	_pseudoLiterals[1] = "+inff";
	_pseudoLiterals[2] = "nanf";
	_pseudoLiterals[3] = "+inf";
	_pseudoLiterals[4] = "-inf";
	_pseudoLiterals[5] = "nan";

	_fPLiterals[0] = "-inff";
	_fPLiterals[1] = "+inff";
	_fPLiterals[2] = "nanf";

}

Converter::Converter(const Converter &other) {
	std::copy(std::begin(other._pseudoLiterals),
					  	std::end(other._pseudoLiterals),
						std::begin(_pseudoLiterals));
	std::copy(std::begin(other._fPLiterals),
						 std::end(other._fPLiterals),
								  std::begin(_fPLiterals));
}

Converter::~Converter() {}

Converter &Converter::operator=(__attribute__((unused)) const Converter &other) {
	return *this;
}

void Converter::displayConversions(std::string arg) {

	if (std::find(std::begin(_pseudoLiterals),
			   std::end(_pseudoLiterals),
			   arg) != std::end(_pseudoLiterals))
		displayPseudoLiteral(arg);
	else if ((_iValue = static_cast<int>(arg)) != NULL) {
		displayItoC();
		std::cout << "int: " << _iValue << std::endl;
		displayItoF();
		displayItoD();
	}
//	} else if (sscanf(arg.c_str(), "%c", &_cValue) == 1) {
//
//	} else if (sscanf(arg.c_str(), "%f", &_fValue) == 1) {
//
//	} else if (sscanf(arg.c_str(), "%lf", &_dValue) == 1) {
//
//	} else {
//
//	}

}

void Converter::displayPseudoLiteral(std::string arg) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (std::find(std::begin(_fPLiterals),
			   std::end(_fPLiterals),
			   arg) != std::end(_fPLiterals)) {
		std::cout << "float: " << arg << std::endl;
		arg.pop_back();
		std::cout << "double: " << arg << std::endl;
	} else {
		std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
	}
}

void Converter::displayItoC() {
	std::cout << "char: ";
	if (_iValue >= 32 && _iValue <= 126) {
		_cValue = static_cast<char>(_iValue);
		std::cout << _cValue;
	} else if (_iValue >= 0 && _iValue <= 127)
		std::cout << "Non displayable";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void Converter::displayItoF() {
	_fValue = static_cast<float>(_iValue);
	std::cout << "float: ";
	if (static_cast<int>(_fValue) != _iValue)
		std::cout << "impossible";
	else
		std::cout 	<< std::fixed << std::setprecision(1)
					<< _fValue << typeid(_fValue).name();
	std::cout << std::endl;
}
//	(std::modf(_fValue, &_) == 0)

void Converter::displayItoD() {
	_dValue = static_cast<double>(_iValue);
	std::cout << "double: ";
	if (static_cast<int>(_dValue) != _iValue)
		std::cout << "impossible";
	else
		std::cout	<< std::fixed << std::setprecision(1)
					<< _dValue;
	std::cout << std::endl;
}