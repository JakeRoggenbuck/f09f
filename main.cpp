#include <iostream>
#include <fstream>
#include <vector>

#include "token.h"
#include "lexer.h"


Lexer::Lexer() {
	std::vector <int> tokens;
}

bool Lexer::doesCharacterBeginToken(char character, char theCharacterComingBefore) { return 0; }

void Lexer::tokenize(std::string part) {
	std::cout << part << std::endl;
}

void Lexer::lex(std::string filename) {
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
	Lexer lexer;

	if (argc >= 2) {
		lexer.lex(argv[1]);
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
