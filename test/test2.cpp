#include <iostream>
#include <vector>
#include "../lib/lexer.hpp"

int main(){
	std::string code = "p 'hello, world'";
	std::vector<std::string> tokens;

	Lexer lexer(code);
	tokens = lexer.getTokens();

	for(auto token: tokens){
		std::cout << token << std::endl;
	}

	return 0;
}