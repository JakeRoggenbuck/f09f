#ifndef PASER_H
#define PASER_H

#include <iostream>
#include "f09f_args.h"

enum Mode {NORMAL, DEBUG};

class Node {
	public:
		Node();
};

class Parser {
	public:
		int parse(f09f_args_t ff_args);
		int mode = NORMAL;
		Parser();
};

#endif
