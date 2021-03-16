#include <iostream>

#include "parser.h"
#include "f09f_args.h"


Parser::Parser() { }

int Parser::parse(f09f_args_t ff_args) {

	std::fstream file(ff_args.file, std::ios::in);
	Lexer lexer;

	if (ff_args.tokens == true) {
		lexer.mode = DEBUG;
	} else {
		lexer.mode = NORMAL;
	}

	while (true) {
		Token token = lexer.lex(file);

		if (token.type == END) { break; }

		// If they shouldn't be ignored
		if (lexer.mode == DEBUG && token.type < 29) {
			std::cout << token.type << ":\t" << token.part << std::endl;
		}

	}

	return 0;
}
