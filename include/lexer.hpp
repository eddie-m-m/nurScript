#ifndef LEXER_HPP
#define LEXER_HPP

#include <cstddef>
#include <string>


class Lexer {
	Lexer();

	// token next_token();
	// token new_token(token, std::byte);


	void skip_whitespace();

	void read_char();

	std::byte peek_char();

	std::string read_identifier();

	std::string read_number();

	std::string read_string();

	bool is_alpha();

	bool is_digit();



};

#endif 
