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
	int tokenType;

	if (part == "include") {
		tokenType = INCLUDE;
	} else if (part == "byte") {
		tokenType = BYTE;
	} else if (part == "char") {
		tokenType = CHAR;
	} else if (part == "int") {
		tokenType = INT;
	} else if (part == "prec") {
		tokenType = PREC;
	} else if (part == "bool") {
		tokenType = BOOL;
	} else if (part == "true") {
		tokenType = TRUE;
	} else if (part == "false") {
		tokenType = FALSE;
	} else if (part == "string") {
		tokenType = STRING;
	} else if (part == "function") {
		tokenType = FUNCTION;
	} else if (part == "returns") {
		tokenType = RETURNS;
	} else if (part == "return") {
		tokenType = RETURN;
	} else if (part == "while") {
		tokenType = WHILE;
	} else if (part == "still") {
		tokenType = STILL;
	} else if (part == "do") {
		tokenType = DO;
	} else if (part == "loop") {
		tokenType = LOOP;
	} else if (part == "for") {
		tokenType = FOR;
	} else if (part == "static") {
		tokenType = STATIC;
	} else if (part == "(") {
		tokenType = LEFT_PAREN;
	} else if (part == ")") {
		tokenType = RIGHT_PAREN;
	} else if (part == "{") {
		tokenType = LEFT_BRACE;
	} else if (part == "}") {
		tokenType = RIGHT_BRACE;
	} else if (part == "[") {
		tokenType = LEFT_BRACKET;
	} else if (part == "]") {
		tokenType = RIGHT_BRACKET;
	} else if (part == "=") {
		tokenType = ASSIGNMENT;
	} else if (part == "end") {
		tokenType = END;
	} else if (part == " ") {
		tokenType = SPACE;
	} else if (part == "\t") {
		tokenType = TAB;
	} else if (part == "\n") {
		tokenType = NEWLINE;
	} else if (part.find('~') != std::string::npos) {
		tokenType = COMMENT;
	} else if (part.find('"') != std::string::npos) {
		tokenType = LITERAL;
	} else {
		tokenType = IDENTIFIER;
	}

	return tokenType;
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

		if (buffer[index] == '~') { index++; do { index++; } while (buffer[index] != '~'); }
		if (buffer[index] == '"') { index++; do { index++; } while (buffer[index] != '"'); }

		// Remembers the character from the last iteration
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

	// Print tokens in debug mode
	if (mode == DEBUG) {
		std::cout << token << ": " << part << std::endl;
	}

	start += index;

	return token;
}

int main(int argc, char *argv[]) {

	std::fstream file(argv[1], std::ios::in);
	Lexer lexer;
	lexer.mode = NORMAL;

	int token;
	if (argc >= 2) {
		while ( (token = lexer.lex(file)) != END ) {
			// If they shouldn't be ignored
			if (token < 29) {
				std::cout << token << std::endl;
			}
		}
	} else {
		std::cout << "No filepath specified" << std::endl;
	}
	return 0;
}
