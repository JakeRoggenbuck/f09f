#include <iostream>
#include <fstream>
#include <vector>

#include "token.h"
#include "lexer.h"


Lexer::Lexer() { }


bool Lexer::doesCharacterEndToken(char lastChar, char currentChar, char nextChar) {
	if (currentChar == '{' || nextChar == '{') { return 1; }
	else if (currentChar == '}' || nextChar == '}') { return 1; }

	else if (currentChar == '[' || nextChar == '[') { return 1; }
	else if (currentChar == ']' || nextChar == ']') { return 1; }

	else if (currentChar == '(' || nextChar == '(') { return 1; }
	else if (currentChar == ')' || nextChar == ')') { return 1; }

	else if (currentChar == '+' || currentChar == '-') { return 1; }
	else if (currentChar == '*' || currentChar == '/') { return 1; }

	else if (currentChar == ',' || nextChar == ',') { return 1; }
	else if (currentChar == ' ' || nextChar == ' ') { return 1; }
	else if (currentChar == '^' || nextChar == '^') { return 1; }
	else { return 0; }
}

void Lexer::tokenize(std::string part) {
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
	char nextChar;
	bool isEndOfToken = false;
	while (currentChar != 0 && !isEndOfToken) {
		// Remebers the character from the last iteration
		lastChar = buffer[index-1];
		nextChar = buffer[index+1];
		// Get new character
		currentChar = buffer[index];
		isEndOfToken = Lexer::doesCharacterEndToken(lastChar, currentChar, nextChar);
		index++;
	}
	std::string part(buffer, index);

	if (part != " " && part != "\n") {
		tokenize(part);
	}

	file.close();
	start += index;
}

int main(int argc, char *argv[]) {
	Lexer lexer;

	if (argc >= 2) {
		for (int i = 0; i < 40; i++) {
			lexer.lex(argv[1]);
		}
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
