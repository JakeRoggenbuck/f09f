#include <iostream>
#include <fstream>
#include <vector>

#include "token.h"
#include "lexer.h"


Lexer::Lexer() { }

bool Lexer::doesCharacterBeginToken(char character, char theCharacterComingBefore) { return 0; }

void Lexer::tokenize(std::string part) {
}

void Lexer::lex(std::string filename) {
	std::fstream file(filename, std::ios::in);

    file.seekg(start, std::ios::beg);
     
    // Read the next 5 characters from the file into a buffer
    char A[20];
    file.read(A, 19);
     
    // End the buffer with a null terminating character
    A[19] = 0;
     
    // Output the contents read from the file and close it 
	std::cout << "Start:" << A << std::endl;

    file.close();
	start += 19;
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
