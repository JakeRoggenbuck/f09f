#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include <fstream>

enum Mode {NORMAL, DEBUG};

class Lexer {
	public:
		int start = 0;
		int mode = NORMAL;
		bool doesCharacterEndToken(char lastChar, char currentChar, char nextChar);
		int tokenize(std::string part);
		int lex(std::fstream& file);
		Lexer();
};

#endif
