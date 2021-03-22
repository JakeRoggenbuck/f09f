#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "token.h"

class Lexer {
	public:
		Token currentToken;
		int start = 0;
		int line = 1;
		int charInLine = 0;
		bool doesCharacterEndToken(char currentChar, char nextChar);
		int tokenize(std::string part);
		Token lex(std::fstream& file);
		Lexer();
};

#endif
