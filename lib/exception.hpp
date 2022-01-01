#ifndef __EXCEPTION_HEADER__
#define __EXCEPTION_HEADER__

#include <iostream>
#include <string>
#include <iomanip>

class Exception{
	public : 
		void Throw_Exception(std::string exception_type, std::string exception_message){

			if(exception_type == "SyntaxError"){
				std::cout << "  <Input>" << std::endl;
				std::cout << "\t" + exception_message << std::endl;
				std::cout << "\t" << std::setw(exception_message.length()+1) << " ^" << std::endl;

				std::cout << exception_type << ": " << "Invalid Syntax" << std::endl;
			}
			exit(1);
		}
};
// syntax error
class SyntaxError:public Exception{
	public :
		SyntaxError(std::string message){
			Throw_Exception("SyntaxError", message);
		}
};

#endif