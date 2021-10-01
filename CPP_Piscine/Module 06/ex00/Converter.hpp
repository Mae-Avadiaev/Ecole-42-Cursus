#ifndef CONVERTER_HPP
#define CONVERTER_HPP 

#include <iostream>
#include <string>

class Converter {

public:

    Converter();
    Converter(const Converter &other);
    ~Converter();
    Converter& operator=(const Converter &other);

    void displayConversions(std::string arg);

private:

	void displayPseudoLiteral(std::string arg);

	void displayItoF();
	void displayItoD();

	void displayDtoC();
	void displayDtoI();
	void displayDtoF();
	void displayD();

	std::string _pseudoLiterals[6];
	std::string _fPLiterals[3];

	char _cValue;
	int _iValue;
	float _fValue;
	double _dValue;

};

#endif