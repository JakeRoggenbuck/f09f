#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>
#include <fstream>

class Lexer {
    private:
		std::vector <int> tokens;

    public:
		bool doesCharacterBeginToken(char character, char theCharacterComingBefore);
		void tokenize(std::string part);
		void lex(std::string filename);
        Lexer();
};

#endif
