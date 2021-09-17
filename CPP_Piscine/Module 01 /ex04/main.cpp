#include "replace.hpp"

void ft_replace(std::string& line, size_t pos, size_t len, std::string s2) {
	line.erase(pos, len);
	line.insert(pos, s2);
}

int main(int ac, char **av) {

	if (ac != 4) {
		std::cout <<  ARG_ERR << std::endl;
		return 1;
	}

	std::string filename = av[1], s1 = av[2], s2 = av[3];

	if (s1.empty() || s2.empty()) {
		std::cout << EMP_ERR << std::endl;
		return 1;
	}

	std::ofstream outfile (filename + ".replace");
	std::ifstream infile;
	std::string line;
	size_t pos;

	infile.open(filename);
	while(std::getline(infile, line)) {
		while ((pos = line.find(s1)) != std::string::npos) {
			ft_replace(line, pos, s1.length(), s2);
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();

	return 0;
}