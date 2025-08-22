#include <variant>
#include <string>
#include <sstream>

#include "TokenType.hpp"


using Literal = std::variant<std::monostate, double, std::string>;


std::string token_type_to_string(TokenType type) {
	switch (type) {
		case TokenType::LEFT_PAREN:		return "LEFT_PAREN";
		case TokenType::RIGHT_PAREN:	return "RIGHT_PAREN";
		case TokenType::LEFT_BRACE:		return "LEFT_BRACE";
		case TokenType::RIGHT_BRACE:	return "RIGHT_BRACE";
		case TokenType::COMMA:			return "COMMA";
		case TokenType::DOT:			return "DOT";
		case TokenType::MINUS:			return "MINUS";
		case TokenType::PLUS:			return "PLUS";
		case TokenType::SLASH:			return "SLASH";
		case TokenType::STAR:			return "STAR";
		case TokenType::BANG:			return "BANG";
		case TokenType::BANG_EQUAL:		return "BANG_EQUAL";
		case TokenType::EQUAL:			return "EQUAL";
		case TokenType::EQUAL_EQUAL:	return "EQUAL_EQUAL";
		case TokenType::GREATER:		return "GREATER";
		case TokenType::GREATER_EQUAL:	return "GREATER_EQUAL";
		case TokenType::LESS:			return "LESS";
		case TokenType::LESS_EQUAL:		return "LESS_EQUAL";
		case TokenType::IDENTIFIER:		return "IDENTIFIER";
		case TokenType::STRING:			return "STRING";
		case TokenType::NUMBER:			return "NUMBER";
		case TokenType::AND:			return "AND";
		case TokenType::CLASS:			return "CLASS";
		case TokenType::ELSE:			return "ELSE";
		case TokenType::FALSE:			return "FALSE";
		case TokenType::TRUE:			return "TRUE";
		case TokenType::FUN:			return "FUN";
		case TokenType::FOR:			return "FOR";
		case TokenType::IF:				return "IF";
		case TokenType::NIL:			return "NIL";
		case TokenType::OR:				return "OR";
		case TokenType::PRINT:			return "PRINT";
		case TokenType::RETURN:			return "RETURN";
		case TokenType::SUPER:			return "SUPER";
		case TokenType::THIS:			return "THIS";
		case TokenType::VAR:			return "VAR";
		case TokenType::WHILE:			return "WHILE";
		case TokenType::END_OF_FILE:	return "END_OF_FILE";
		default:						return "UNKNOWN";

	}

};



class Token {
	public:
		const TokenType type;
		const std::string lexeme;
		const Literal literal;
		const int line;


		Token(TokenType type, std::string lexeme, Literal literal, int line):
			type(type), lexeme(lexeme), literal(std::move(literal)), line(line){};


		std::string to_string() const {
			std::string literal_string;

			std::visit([&](auto&& arg) {
					using T = std::decay_t<decltype(arg)>;
					if constexpr (std::is_same_v<T, std::string>) {
						literal_string = arg;
					} else if constexpr (std::is_same_v<T, double>) {
						literal_string = std::to_string(arg);
					} else {
						literal_string = "null";
						}
					}, literal);

			return token_type_to_string(type) + " " + lexeme + " " + literal_string;
		}
};

