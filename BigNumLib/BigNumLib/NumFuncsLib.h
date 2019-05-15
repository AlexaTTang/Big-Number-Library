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
		std::vector<int> bigNum;
		unsigned long long int num;
		int length = 0;

		BigNumFuncs(std::vector<int> v)
		{
			bigNum = v;
		}
		std::vector<int> operator +(unsigned long long int numAdded);
		std::vector<int> operator-(unsigned long long int numSubtracted);
		std::vector<int> operator /(unsigned long long int numDivided);
		std::vector<int> operator *(unsigned long long int numMultiplied);
		std::vector<int> numberIntoVector(unsigned long long int number); //helper method to change unsigned long long int to an integer vector 
		

	};
}
