#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		_learnedMateria[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._learnedMateria[i])
			_learnedMateria[i] = other._learnedMateria[i]->clone();
	}
}	

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_learnedMateria[i])
			delete _learnedMateria[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignation operator has been called!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_learnedMateria[i]) {
				delete _learnedMateria[i];
				_learnedMateria[i] = 0;
			}
		}	
		for (int i = 0; i < 4; i++) {
			if (other._learnedMateria[i])
				_learnedMateria[i] = other._learnedMateria[i]->clone();
		}
	}
	return *this;	
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_learnedMateria[i]) {
			_learnedMateria[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_learnedMateria[i])
			if (_learnedMateria[i]->getType() == type)
				return _learnedMateria[i]->clone();
	}
	return 0;
}
