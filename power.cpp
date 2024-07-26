#include <iostream>
#include <string>

struct bad_argument
{
	bad_argument(const std::string message) : _message{message} {}

	std::string what() { return _message; }
	std::string _message;
};

double power(int x, int y);
//Raises x to the power of y

int main(int argc, char *argv[])
{
	try
	{
		int base;
		int exponent;

		std::cout << "Enter the base: ";
		std::cin >> base;
		std::cout << "Enter exponent: ";
		std::cin >> exponent;

		if (base < 0)
			throw bad_argument("Base must be postive.");
		std::cout << base << " ^ " << exponent << " = " << power(base, exponent);
		
		std::cout << std::endl;
	}
	catch (bad_argument &message)
	{
		std::cout << message.what();
	}
} //end main

double power(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y == 1)
		return x;
	else if (y > 1)
		return x * power(x, y - 1);
	else
	{
		y *= -1;
		return 1 / power(x, y);
	}
} //end power