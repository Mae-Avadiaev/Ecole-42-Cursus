#include "Converter.hpp"
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>

Converter::Converter() {
	_pseudoLiterals[0] = "-inff";
	_pseudoLiterals[1] = "+inff";
	_pseudoLiterals[1] = "inff";
	_pseudoLiterals[2] = "nanf";
	_pseudoLiterals[3] = "+inf";
	_pseudoLiterals[3] = "inf";
	_pseudoLiterals[4] = "-inf";
	_pseudoLiterals[5] = "nan";

	_fPLiterals[0] = "-inff";
	_fPLiterals[1] = "+inff";
	_fPLiterals[1] = "inff";
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
	char *ptrEnd = 0;
	errno = 0;
	if (std::find(std::begin(_pseudoLiterals),
			   std::end(_pseudoLiterals),
			   arg) != std::end(_pseudoLiterals))
		displayPseudoLiteral(arg);
	else if (arg.length() == 1 && std::isprint(*arg.c_str())) {
		_iValue = static_cast<int>(*arg.c_str());
		std::cout << "char: " << arg << std::endl;
		std::cout << "int: " << _iValue << std::endl;
		displayItoF();
		displayItoD();
	} else if (((_dValue = std::strtod(arg.c_str(), &ptrEnd)) != 0.0
	|| arg[0] == '0') && ((arg.find(".") != std::string::npos && strlen(ptrEnd) == 1
	&& *ptrEnd == 'f') || *ptrEnd == 0) && errno != ERANGE) {
		displayDtoC();
		displayDtoI();
		displayDtoF();
		displayD();
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void Converter::displayPseudoLiteral(std::string arg) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (std::find(std::begin(_fPLiterals),
			   std::end(_fPLiterals),
			   arg) != std::end(_fPLiterals)) {
		std::cout << "float: " << arg << std::endl;
		arg = arg.substr(0, arg.size() - 1);
		std::cout << "double: " << arg << std::endl;
	} else {
		std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
	}
}

void Converter::displayItoF() {
	_fValue = static_cast<float>(_iValue);
	std::cout << "float: ";
	if (static_cast<double>(_fValue) != _iValue)
		std::cout << "impossible";
	else
		std::cout 	<< std::fixed << std::setprecision(1)
					 << _fValue << typeid(_fValue).name();
	std::cout << std::endl;
}

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

void Converter::displayDtoC() {
	_iValue = static_cast<int>(_dValue);
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

void Converter::displayDtoI() {
	std::cout << "int: ";
	if (_dValue > std::numeric_limits<int>::max()
	|| _dValue < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else {
		_iValue = static_cast<int>(_dValue);
		std::cout << _iValue;
	}
	std::cout << std::endl;
}

void Converter::displayDtoF() {
	float integralF;
	double integralD;
	_fValue = static_cast<float>(_dValue);
	std::cout << "float: ";
	if (_dValue > std::numeric_limits<float>::max()
		|| _dValue < -std::numeric_limits<float>::max())
		std::cout << "impossible";
	else if (modf(_fValue, &integralF) == 0 && modf(_dValue, &integralD) == 0)
		std::cout << std::fixed << std::setprecision(1)
				  << _fValue << typeid(_fValue).name();
	else if (modf(_fValue, &integralF) == 0 && modf(_dValue, &integralD) != 0)
		std::cout 	<< std::fixed << std::setprecision(1)
					 <<_fValue << typeid(_fValue).name() << " (loss of precision)";
	else
		std::cout << _fValue << typeid(_fValue).name();
	std::cout << std::endl;
}

void Converter::displayD() {
	double integral;
	std::cout << "double: ";
	if (modf(_dValue, &integral) == 0)
		std::cout	<< std::fixed << std::setprecision(1) << _dValue;
	else
		std::cout	<< std::fixed << std::setprecision(10) << _dValue;
	std::cout << std::endl;
}