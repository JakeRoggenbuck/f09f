#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

struct Token { std::string part; int type; int location; int line; };

enum TokenType {
	INCLUDE,
	ASSIGNMENT,
	BYTE,
	CHAR,
	INT,
	PREC,
	PTR,
	BOOL,
	TRUE,
	FALSE,
	STRING,
	FUNCTION,
	RETURNS,
	RETURN,
	WHILE,
	STILL,
	DO,
	LOOP,
	FOR,
	STATIC,
	LEFT_PAREN,
	RIGHT_PAREN,
	LEFT_BRACE,
	RIGHT_BRACE,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	END,
	IDENTIFIER,
	LITERAL,
	DOT,
	COMMA,
	COLON,
	SEMICOLON,
	// Ignore
	SPACE,
	TAB,
	NEWLINE,
	COMMENT,
	NONE,
};

#endif
