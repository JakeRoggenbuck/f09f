#include <iostream>

#include "lexer.cpp"
#include "parser.cpp"
#include "utils.h"
#include "f09f_args.h"


void usage() {
	std::cout << "Usage: " << std::endl;
	std::cout << "\t--help display this help and exit" << std::endl;
	std::cout << "\t-v display the version and exit" << std::endl;
	std::cout << "\t-t show tokens as they are parsed" << std::endl;
	std::cout << "\t[file]: interpret [file]" << std::endl;
}


int main(int argc, char** argv) {
	if (argc == 1) { F09F_ERROR("Expected [file] argument"); }

	f09f_args_t ff_args = {0, NULL, 0, 0};

	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == "-v") {
			if (!ff_args.info) { ff_args.info = true; }
		} else if (std::string(argv[i]) == "--help") {
			if (!ff_args.help) { ff_args.help = true; }
		} else if (std::string(argv[i]) == "-t") {
			if (!ff_args.tokens) { ff_args.tokens = true; }
		}
	}

	ff_args.file = argv[1];

	if (argc == 2) {
		if (ff_args.info) {
			std::cout << "Version: 0.1" << std::endl;
		} else if (ff_args.help) { usage(); }

	} else if (argc >= 2) {
		Parser parser;
		parser.parse(ff_args);

	}
	return 0;
}
