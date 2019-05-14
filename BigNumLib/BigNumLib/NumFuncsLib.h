#pragma once

// MathFuncsLib.h
#include <vector>

namespace NumFuncs
{
	class BigNumFuncs
	{
	public:
		//for 1,000 digits 100 unsigned long int: 0 to 4,294,967,295
		//50 unsigned long long int: 0 to 18,446,744,073,709,551,615
		std::vector<unsigned long long int> bigNum;
		unsigned long long int num;

		BigNumFuncs(std::vector<unsigned long long int> v)
		{
			bigNum = v;
		}
		unsigned long long int operator +(unsigned long long int numAdded);

		unsigned long long int operator-(unsigned long long int numSubtracted);
		unsigned long long int operator *(unsigned long long int numMultiplied);
		














		// Returns a + b
		static double Add(double a, double b);

		// Returns a - b
		static double Subtract(double a, double b);

		// Returns a * b
		static double Multiply(double a, double b);

		// Returns a / b
		static double Divide(double a, double b);
	};
}
