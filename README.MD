### Simple Lexer

**Class**

* Lexer(<string>, <bool>)
  * **void** print()
  * **int** getLine()
  * **vector<string>** getTokens()

**Lexer Simple Code :**

```c++
#include <iostream>
#include <string>
#include <lib/execption.hpp>
#include <lib/lexer.hpp>

int main(){
    std::string code;
	while(true){
		std::cout << "> ";
		getline(std::cin, code);

		Lexer lexer(code, true);
		lexer.print();
	}
    return 0;
}
```

**Get Tokens**

```c++
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
```

**Output :**

```c++
kw:p
str:hello, world
```

**Features :**

* Customize :  `Keywords`
* Edit File :  `utility.hpp` 
* `std::string keywords[]  {}`

