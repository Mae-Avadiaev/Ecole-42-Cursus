#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen {

public:

	void complain(std::string level);

private:

	int calc_level(std::string level);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif