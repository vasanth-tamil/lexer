#ifndef __UTILITY__HEADER__
#define __UTILITY__HEADER__

const char spcialChars[] = {'+', '-', '*', '/', '%', '<', '>', '=', '[', ']', '{', '}', '(', ')', '.', ',', ':', ';', '$', '#', '_', '/', '\\', '?', '@', '`', '~', '^', '&', '|', '!', ' ', '\t', '\n'};
const std::string spcialCharsName[] = {"Plus", "Minus", "Mult", "Divider", "Reminder", "Lessthan", "Greaterthan", "Equal", "Obracket", "Cbraket", "Obrace", "Cbrace", "Oparen", "Cparen", "Dot", "Comma", "Colon", "Semicolon", "Dolor", "Hash", "Undersore", "Fslash", "Bslash", "Quzmark", "At", "Acute", "Tilde", "Caret", "Ampersand", "Pipe", "Exmark", "Space", "Tab", "Newline"};

std::string keywords[] = {
	"p", "g", 
	"if", "elif", "else", 
	"loop", "stop", "break", "done", 
	"lt", "le", "gt", "ge", "eq", "ne", 
	"and", "or", "not", 
	"true", "false",
	"string", "int", "float",
	"return"
};
#endif