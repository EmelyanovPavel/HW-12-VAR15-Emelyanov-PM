//Homework 12

//Construct a table of values of the function y=f(x) for x E [a, b] in increments of h. If the function is not defined at some point x,
//then display a message about it. Use the functions y=f(x) from the "Exercises" section of Chapter 3, p. 5.
//
//Remark. 
//When solving this problem, use the auxiliary function f(x), which calculates the value of y,
//and also handle possible exceptions.

#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>

// 15)  y = ln|3x|√(2x^5 - 1)
// 
// Auxiliary function for calculating the function value
double f(double x) {
    //Checking that the logarithm contains a positive number
    if (std::abs(3 * x) <= 0) {
        throw std::domain_error("Logarithm of a non-positive number");
    }

    //Checking that the root expression is non-negative
    if (2 * std::pow(x, 5) - 1 < 0) {
        throw std::domain_error("Square root of a negative number");
    }

    return std::log(std::abs(3 * x)) * std::sqrt(2 * std::pow(x, 5) - 1);
}

void task1() {
    double a, b, h;

    //Entering interval and step boundaries
    std::cout << "Begin of interval (a): ";
    std::cin >> a;
    std::cout << "End of interval (b): ";
    std::cin >> b;
    std::cout << "Step (h): ";
    std::cin >> h;

    double x = a;

    //Displaying the table header
    std::cout << "\nTable of function values:\n";
    std::cout << "x\t\ty\n";

    //Main loop for calculating values
    while (x <= b) {
        try {
            double y = f(x);
            std::cout << x << "\t\t" << y << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error at x = " << x << ": " << e.what() << "\n";
        }

        x += h;
    }

}

int main()
{

    task1();

    return 0;

}