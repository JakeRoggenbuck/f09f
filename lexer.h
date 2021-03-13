#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include <fstream>

class Lexer {
    public:
		int start = 0;
		bool doesCharacterEndToken(char lastChar, char currentChar, char nextChar);
		int tokenize(std::string part);
		int lex(std::fstream& file);
		void openBuffer(std::string filename);
        Lexer();
};

#endif
