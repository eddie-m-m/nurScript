#include "Lexer.hpp"


class Lexer {
	Lexer(){};

	// token next_token();
	// token new_token(token, std::byte);


	void skip_whitespace(){};

	void read_char(){};

	std::byte peek_char(){};

	std::string read_identifier(){return "";};

	std::string read_number(){return "";};

	std::string read_string(){return "";};

	bool is_alpha(){return false};

	bool is_digit(){return false;



};
