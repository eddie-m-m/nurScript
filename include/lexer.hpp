#ifndef LEXER_HPP
#define LEXER_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "TokenType.hpp"


class Lexer {
	public:
		Lexer(std::string source);

		std::vector<TokenType> scan_tokens();

	private:
		const std::string source;
		std::vector<TokenType> tokens;

		int start{0};
		int current{0};
		int line{1};


		void scan_token();

		void identifier();
		void number();
		void string();

		bool match(char expected);

		char peek();
		char peek_next();

		bool is_alpha(char c);
		bool is_alphanumeric(char c);
		bool is_digit(char c);

		bool is_at_end();

		char advance();

		void add_token(TokenType type);

		void add_token(TokenType type, Literal literal);

};

#endif 
