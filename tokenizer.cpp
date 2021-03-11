#include <iostream>
#include "token.h"
#include <fstream>
#include <vector>


std::vector <int> tokens;

void tokenize(std::string part) {
	std::cout << part << std::endl;
}

void parser(std::string filename) {
	std::ifstream file;
	file.open (filename);
	if (!file.is_open()) return;

	std::string part;
	// Read each word in the file
	while (file >> part) {
		// Give the part to tokenize
		tokenize(part);
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		parser("test.ff");
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
