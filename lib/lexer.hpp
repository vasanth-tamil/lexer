#ifndef __TOKENS__HEADER__
#define __TOKENS__HEADER__
#include <iostream>
#include <string>
#include <vector>
#include "utility.hpp"
#include "exception.hpp"

#define VERSION "1.0"

class Lexer{
	private:
		std::vector<std::string> tokens;

		bool ignore_space = true;
		
		int lex;
		std::string lexer;
		int dot = 0;
		bool sq = false;
		bool dq = false;
		int lines = 1;

		bool isKeyword(std::string input);

	public : 
		Lexer(std::string text="", bool ignore_space = true){
			this->ignore_space = ignore_space;

			for(int index=0; index<text.length(); index++){
				if(sq == false and dq == false){
					/*****************************************************
					 * IDENTIFIER AND KEYWORDS
					*****************************************************/
					if(isalpha(text[index])){
						lexer = "";
						lex = index;

						if(isalpha(text[index+1])){
							while(isalpha(text[lex]) or isdigit(text[lex])){
								lexer += text[lex];
								lex++;
							}
						}
						else{
							while(isalpha(text[lex]) or isdigit(text[lex])){
								lexer += text[lex];
								lex++;
							}
						}
						(isKeyword(lexer)) ?
							tokens.push_back("kw:" + lexer) : 
							tokens.push_back("id:" + lexer);
						// reset index
						index = lex;
					}
					/**************************************************************
					 * 	INTEGER AND FLOAT
					**************************************************************/
					if(isdigit(text[index]) or text[index] == '.' and text[index+1] != '.'){
						lexer = "";
						lex = index;

						if(isdigit(text[index+1]) or text[index+1] == '.'){
							while(isdigit(text[lex]) or text[lex] == '.'){

								// check dot and increse the dot count
								if(text[lex] == '.') dot += 1;

								// check dot count is 1 or not throw error and exit
								if(1 < dot){
									SyntaxError(lexer + "");
								}
								
								lexer += text[lex];
								lex++;
							}

							// convert string int,float
							(dot == 1) ?
								tokens.push_back("float: " + lexer) :
								tokens.push_back("int:" + lexer);

							// reset values
							index = lex-1;
							dot = 0;
						}
						else{
							lexer = text[index];
							if(text[index] != '.') tokens.push_back("int:" + lexer);
						}
					}
				}
				/*******************************************************************
				 * 	STRINGS
				********************************************************************/
				// single quotes
				if(text[index] == '\'' or sq){
					if(sq){
						lexer = "";
						lex = index;

						// modify `or lex != text.length() -1`
						while(text[lex] != '\''){
							
							// string not completed throw error
							if(lex == text.length()-1 and lexer[lex] != '\''){
								// SyntaxError("Single Quote Not Close");
								SyntaxError(lexer + "");
							}
							lexer += text[lex];
							lex++;
						}
						// remove "'" quotes
						index = lex + 1;
						sq = false;

						tokens.push_back("str:" + lexer);
					}
					else{
						if(text[index] == '\'' and index == text.length()-1){
							// SyntaxError("Single Quote Not Close");
							SyntaxError(lexer + "");
						}
						else sq = true;
					}
				}
				// double quotes
				if(text[index] == '\"' or dq){
					if(dq){
						lexer = "";
						lex = index;

						while(text[lex] != '\"'){
							// string not completed
							if(lex == text.length()-1 and text[lex] != '"'){
								// SyntaxError("Double Quote Not Close");
								SyntaxError(lexer + "");
							}
							lexer += text[lex];
							lex++;
						}
						tokens.push_back("str:" + lexer);

						// remove '"' quotes and reset dq value
						index = lex + 1;
						dq = false;
					}
					else{
						if(text[index] == '\"' and index == text.length()-1){
							SyntaxError(lexer + "");
						}
						else dq = true;
					}
				}
				/*****************************************************************
				 *  PUNNCT
				*****************************************************************/
				if(sq == false and dq == false){
					if(ispunct(text[index]) or isspace(text[index])){
						
						for(int char_index = 0; char_index<sizeof(spcialChars)/sizeof(char); char_index++){
							if(text[index] == spcialChars[char_index]){
								// check ignore space
								if(ignore_space and text[index] != ' ')
									tokens.push_back("spc:" + spcialCharsName[char_index]);
								
								else if(ignore_space == false)
									tokens.push_back("spc:" + spcialCharsName[char_index]);
								
								// increase lines
								if(text[index] == '\n') lines++;
								break;
							}
						}
					}
				}
			}
		} 
		// print all tokens
		void print(){
			for(auto token: this->tokens)
				std::cout << token << std::endl;
		}
		// get line numbers
		int getLines(){
			return this->lines;
		}
		// get tokens
		std::vector<std::string> getTokens(){
			return this->tokens;
		}
};

// keyword finder
bool Lexer::isKeyword(std::string input){
	for(auto keyword: keywords)
		if(input == keyword) return true;	
	return false;
}
#endif