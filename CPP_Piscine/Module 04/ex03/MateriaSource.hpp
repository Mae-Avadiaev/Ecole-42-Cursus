#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource &other);

	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const & type);

private:

	AMateria *_learnedMateria[4];
};

#endif