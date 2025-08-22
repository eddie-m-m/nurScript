#include <vector>
#include <string>

#include "Lexer.hpp"
#include "TokenType.hpp"



Lexer::Lexer(std::string source): source(source) {}


bool Lexer::is_at_end() {
	return current >= source.size();
}

std::vector<TokenType> Lexer::scan_tokens() {
	while (!Lexer::is_at_end()) {
		start = current;
	Lexer::scan_token();
	}

	tokens.push_back(Token(END_OF_FILE, "", null, line);

	return tokens;

}

