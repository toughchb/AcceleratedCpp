#include <iostream>
#include <string>

int main()
{
	const std::string hello = "Hello";
	const std::string message = hello + ",world" + "!";
	
	const std::string exclam = "!";
	const std::string message2 = "Hello" + ", world" + exclam;


	return 0;
}