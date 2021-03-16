#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define F09F_ERROR(...) do {                                   \
	std::cout << "Error: f09f: " <<  __VA_ARGS__ << std::endl; \
	exit(1);                                                   \
} while (0)
