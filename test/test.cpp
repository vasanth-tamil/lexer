#include <iostream>
#include <string>
#include <vector>
#include "../lib/lexer.hpp"

int main(){
	// std::string code = "p \"Hello, World this is my sample programming language.I am create simple tokenizer using cpp language.\"";
	std::string code;
	
	std::cout << "Lexer " << VERSION << std::endl;

	while(true){
		std::cout << "> ";
		
		getline(std::cin, code);

		Lexer lexer(code, true);
		lexer.print();
	}

	return 0;
}