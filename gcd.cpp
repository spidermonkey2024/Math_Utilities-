#include <iostream>

int gcd(int x, int y);
//Finds the greatest common divisor
//between x and y

int main(int argc, char *argv[])
{
	int num1;
	int num2;

	std::cout << "Enter first number: ";
	std::cin >> num1;

	std::cout << "Enter second number: ";
	std::cin >> num2;

	std::cout << "Greatest common divisor between " << num1 << " and " << num2 << " is " << gcd(num1, num2);

	std::cout << "\n";
}//end main

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
	{
		auto remainder = x % y;
		return gcd(y, remainder);
	}
} //end gcd