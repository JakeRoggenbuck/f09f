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
	else if (currentChar == '\n' || nextChar == '\n') { return 1; }
	else { return 0; }
}

int Lexer::tokenize(std::string part) {
	int token;

	if (part == "include") {
		token = INCLUDE;
	} else if (part == "byte") {
		token = BYTE;
	} else if (part == "char") {
		token = CHAR;
	} else if (part == "int") {
		token = INT;
	} else if (part == "prec") {
		token = PREC;
	} else if (part == "bool") {
		token = BOOL;
	} else if (part == "true") {
		token = TRUE;
	} else if (part == "false") {
		token = FALSE;
	} else if (part == "string") {
		token = STRING;
	} else if (part == "function") {
		token = FUNCTION;
	} else if (part == "returns") {
		token = RETURNS;
	} else if (part == "return") {
		token = RETURN;
	} else if (part == "while") {
		token = WHILE;
	} else if (part == "still") {
		token = STILL;
	} else if (part == "do") {
		token = DO;
	} else if (part == "loop") {
		token = LOOP;
	} else if (part == "for") {
		token = FOR;
	} else if (part == "static") {
		token = STATIC;
	} else if (part == "(") {
		token = LEFT_PAREN;
	} else if (part == ")") {
		token = RIGHT_PAREN;
	} else if (part == "{") {
		token = LEFT_BRACE;
	} else if (part == "}") {
		token = RIGHT_BRACE;
	} else if (part == "[") {
		token = LEFT_BRACKET;
	} else if (part == "]") {
		token = RIGHT_BRACKET;
	} else if (part == "end") {
		token = END;
	} else if (part == " ") {
		token = SPACE;
	} else if (part == "\t") {
		token = TAB
	} else if (part == "\n") {
		token = NEWLINE;
	} else {
		token = NAME;
	}

	return token;
}

int Lexer::lex(std::fstream& file) {
	file.seekg(start, std::ios::beg);

	int buffSize = 36;
	char buffer[buffSize];
	file.read(buffer, buffSize-1);

	// End the buffer with a null terminating character
	buffer[buffSize-1] = 0;

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
	// Convert buffer to string up until index
	std::string part(buffer, index);

	// Get token from part
	int token;
	token = tokenize(part);

	if (mode == DEBUG) {
		std::cout << token << ": " << part << std::endl;
	}

	start += index;

	return token;
}

int main(int argc, char *argv[]) {

	std::fstream file(argv[1], std::ios::in);
	Lexer lexer;

	int token;
	if (argc >= 2) {
		while ( (token = lexer.lex(file)) != END ) {
			std::cout << token << std::endl;
		}
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
