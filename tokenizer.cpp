#include <iostream>
#include "token.h"
#include <fstream>
#include <vector>


std::vector <int> tokens;

void tokenize(char part) {
	std::cout << part << std::endl;
}

void parser(std::string filename) {
	// Read each word in the file
	// That will be the part
	char* part;
	// Give the part to tokenize
	tokenize(part);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		parser("test.ff");
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
