#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "token.h"
#include "lexer.h"


Lexer::Lexer() { }


bool isSingleCharToken(char character) {
	switch (character) {
		case '{':
		case '}':
		case '[':
		case ']':
		case '(':
		case ')':
		case '.':
		case ',':
		case ':':
		case ';':
			return true;
		default:
			return false;
	}
}


bool isOperator(char character) {
	switch (character) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '>':
		case '<':
			return true;
		default:
			return false;
	}
}


bool isWhitespace(char character) {
	switch (character) {
		case '\t':
		case ' ':
		case '\n':
			return true;
		default:
			return false;
	}
}


bool Lexer::doesCharacterEndToken(char currentChar, char nextChar) {
	if (isSingleCharToken(currentChar) || isSingleCharToken(nextChar)) { return true; }
	else if (isOperator(currentChar) || isOperator(nextChar)) { return true; }
	else if (isWhitespace(currentChar) || isWhitespace(nextChar)) { return true; }
	else { return false; }
}


int Lexer::tokenize(std::string part) {
	if (part == "{") {
		return LEFT_BRACE;
	} else if (part == "}") {
		return RIGHT_BRACE;
	} else if (part == "[") {
		return LEFT_BRACKET;
	} else if (part == "]") {
		return RIGHT_BRACKET;
	} else if (part == "(") {
		return LEFT_PAREN;
	} else if (part == ")") {
		return RIGHT_PAREN;
	} else if (part == ".") {
		return DOT;
	} else if (part == ",") {
		return COMMA;
	} else if (part == ":") {
		return COLON;
	} else if (part == ";") {
		return SEMICOLON;
	} else if (part == "=") {
		return ASSIGNMENT;
	} else if (part == "\t") {
		return TAB;
	} else if (part == " ") {
		return SPACE;
	} else if (part == "\n") {
		return NEWLINE;
	} else if (part == "include") {
		return INCLUDE;
	} else if (part == "byte") {
		return BYTE;
	} else if (part == "char") {
		return CHAR;
	} else if (part == "int") {
		return INT;
	} else if (part == "prec") {
		return PREC;
	} else if (part == "bool") {
		return BOOL;
	} else if (part == "true") {
		return TRUE;
	} else if (part == "false") {
		return FALSE;
	} else if (part == "string") {
		return STRING;
	} else if (part == "function") {
		return FUNCTION;
	} else if (part == "returns") {
		return RETURNS;
	} else if (part == "return") {
		return RETURN;
	} else if (part == "while") {
		return WHILE;
	} else if (part == "still") {
		return STILL;
	} else if (part == "do") {
		return DO;
	} else if (part == "loop") {
		return LOOP;
	} else if (part == "for") {
		return FOR;
	} else if (part == "static") {
		return STATIC;
	} else if (part == "end") {
		return END;
	} else if (part.find('~') != std::string::npos) {
		return COMMENT;
	} else if (part.find('"') != std::string::npos) {
		return LITERAL;
	} else {
		return IDENTIFIER;
	}
}

Token Lexer::lex(std::fstream& file) {
	file.seekg(start, std::ios::beg);

	int buffSize = 36;
	char buffer[buffSize];
	file.read(buffer, buffSize-1);

	// End the buffer with a null terminating character
	buffer[buffSize-1] = 0;

	int index = 0;
	// Set the first character
	char currentChar = buffer[0];
	char nextChar;
	bool isEndOfToken = false;

	if (currentChar == '\n') { line++; charInLine = 0; }

	while (currentChar != 0 && !isEndOfToken) {

		if (buffer[index] == '~') { index++; do { index++; } while (buffer[index] != '~'); }
		if (buffer[index] == '"') { index++; do { index++; } while (buffer[index] != '"'); }

		nextChar = buffer[index+1];
		// Get new character
		currentChar = buffer[index];
		isEndOfToken = Lexer::doesCharacterEndToken(currentChar, nextChar);

		index++;
	}

	std::string part(buffer, index);

	currentToken.type = tokenize(part);
	currentToken.part = part;
	currentToken.location = charInLine;
	currentToken.line = line;

	charInLine += index;
	start += index;

	return currentToken;
}
