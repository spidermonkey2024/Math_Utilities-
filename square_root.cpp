#include <iostream>
#include <cmath>

struct bad_argument
{
	bad_argument(const std::string message) : _message{message} {}

	std::string what() { return _message; }
	std::string _message;
};

double squareRoot(double x);
//Calculates the square root of x
//using Newton's method

int main(int argc, char *argv[])
{
	try
	{
		double num;

		std::cout << "Enter the number: ";
		std::cin >> num;

		if (num < 0)
			throw bad_argument("Number must be greater or equal to 0.");

		std::cout << "The square root of " << num << " is " << squareRoot(num);
		std::cout << "\n";
	}
	catch (bad_argument &message)
	{
		std::cerr << message.what();
	}
}

double squareRoot(double x)
{
	auto a{x};
	auto epsilon{0.9}; //tolerance

	auto diff = a * a - x;
	if (std::abs(diff) <= epsilon)
		return a;
	else
	{
		a = (a * a + x) / (2.0 * a);
		return squareRoot(a);
	}

} //end squareRoot