// Osman Zakir
// 3 / 16 / 2022
// Beginning C++20 From Novice to Professional by Ivor Horton and Peter Van Weert
// Chapter 13 Exercise 7
// Exercise Specs:
/**
 * Exercise 13-7. Implement a class called Rational that represents a rational 
 * number. A rational number can be expressed as the quotient or fraction n / d
 * of two integer numbers, an integral numerator n, and a nonzero, positive 
 * integral denominator d. Do not worry about enforcing that the denominator 
 * is nonzero, though. That’s not the point of the exercise. Definitely create
 * an operator that allows a rational number to be streamed to std::cout. 
 * Beyond that, you are free to choose how many and which operators you add.
 * You could create operators to support multiplication, addition, subtraction,
 * division, and comparison of two Rational numbers and of Rational numbers 
 * and integers. You could create operators to negate, increment, or decrement
 * Rational numbers. and what about converting to a float or a double? There 
 * really is a huge amount of operators you could define for Rationals. The
 * Rational class in our model solution supports well over 20 different 
 * operators, many overloaded for multiple types. Perhaps you come up with
 * even more rational (as in sensible) operators for your Rational class? Do
 * not forget to create a program to test that your operators actually work.
 */

import <iostream>;
import rational;

int main()
{
	Rational rational1{ 5, 2 };
	Rational rational2{ 2, 3 };

	std::cout << "rational1 is " << rational1 << std::endl
		      << "rational2 is " << rational2 << std::endl;
	std::cout << rational1 << " as a floating-point number is "
		      << rational1.get_rational_value() << std::endl;
	std::cout << rational2 << " as a floating-point number is "
		      << rational2.get_rational_value() << std::endl;

	if (rational1 > rational2)
	{
		std::cout << rational1 << " is greater than " << rational2 << std::endl;
	}
	else if (rational1 < rational2)
	{
		std::cout << rational1 << " is less than " << rational2 << std::endl;
	}
	else if (rational1 == rational2)
	{
		std::cout << rational1 << " is equal to " << rational2 << std::endl;
	}

	if (rational1 != rational2)
	{
		std::cout << rational1 << " is not equal to " << rational2 << std::endl;
	}

	std::cout << rational1 << " + 2 is " << rational1 + 2 << std::endl;
	std::cout << rational2 << " / 3 is " << rational2 / 3 << std::endl;
	std::cout << rational1 << " * 4 is " << rational1 * 4 << std::endl;
	std::cout << rational2 << " - 1 is " << rational2 - 1 << std::endl;
	std::cout << rational1 << " + "      << rational2 << " is "   <<
     rational1 + rational2 << std::endl;

	Rational rational3{ rational1 };
	std::cout << "rational3 is " << rational3 << std::endl;
	rational3 += rational2;
	std::cout << rational1 << " += " << rational2 << " is " 
		      << rational3 << std::endl;

	Rational rational4{ rational2 };
	rational4 *= rational1;
	std::cout << rational1 << " *= " << rational2 << " is " 
		      << rational4 << std::endl;

	Rational rational5{ rational2 / rational1 };
	std::cout << rational2 << " / " << rational1 << " is "
		      << rational5 << std::endl;

	double quotient1{ static_cast<double>(rational5) };
	std::cout << rational5 << " converted to a double is " 
		      << quotient1 << std::endl;
}