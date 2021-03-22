#include <iostream>

#include "parser.h"
#include "f09f_args.h"


Node::Node() { }

Parser::Parser() { }

int Parser::parse(f09f_args_t ff_args) {

	std::fstream file(ff_args.file, std::ios::in);
	Lexer lexer;

	if (ff_args.tokens == true) {
		mode = DEBUG;
	} else {
		mode = NORMAL;
	}

	while (true) {
		Token token = lexer.lex(file);

		if (token.type == END) { break; }

		// If they shouldn't be ignored
		if (mode == DEBUG && token.type < 34) {
			std::cout << token.line << ":" << token.location << "\t"
			<< token.type << ":\t" << token.part << std::endl;
		}

	}

	return 0;
}
