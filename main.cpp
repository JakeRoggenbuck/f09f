#include <iostream>
#include <fstream>
#include <vector>

#include "token.h"
#include "lexer.h"


Lexer::Lexer() { }

bool Lexer::doesCharacterEndToken(char character, char theCharacterComingBefore) {
	if (character == '{' || character == '}') { return 1; }
	else if (character == '[' || character == ']') { return 1; }
	else if (character == '(' || character == ')') { return 1; }
	else if (character == '+' || character == '-') { return 1; }
	else if (character == '*' || character == '/') { return 1; }
	else if (character == '^') { return 1; }
	else { return 0; }
}

void Lexer::tokenize(char* part) {
	std::cout << part << std::endl;
}

void Lexer::lex(std::string filename) {
	std::fstream file(filename, std::ios::in);

	file.seekg(start, std::ios::beg);
 
	char buffer[36];
	file.read(buffer, 35);
     
	// End the buffer with a null terminating character
	buffer[35] = 0;
	int index = 0;
	// Set the first character
	char currentChar = buffer[0];
	char lastChar;
	bool isEndOfToken = false;
	while (currentChar != 0 && !isEndOfToken) {
		// Remebers the character from the last iteration
		lastChar = buffer[index-1];
		// Get new character
		currentChar = buffer[index];
		isEndOfToken = Lexer::doesCharacterEndToken(currentChar, lastChar);
		index++;
	}
	std::cout << index << std::endl;

	char* tokenChars = malloc(index * sizeof(char));
	memcpy(tokenChars, &(buffer[2]), 2);

	file.close();
	start += index;
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
