#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include <fstream>

class Lexer {
    public:
		int start = 0;
		bool doesCharacterEndToken(char character, char theCharacterComingBefore);
		void tokenize(std::string part);
		void lex(std::string filename);
        Lexer();
};

#endif
